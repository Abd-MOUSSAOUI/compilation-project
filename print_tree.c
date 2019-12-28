#include "print_tree.h"

#define MAX_HEIGHT 1000
int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];
#define INFINITY (1<<20)
#define MAX_CHAR_PER_WORD 26 /* max characters that can be displayed on an ascii node */
#define GAP 2 /* adjust gap between left and right nodes */

//printing tree in ascii

typedef struct asciinode_struct asciinode;

struct asciinode_struct
{
  asciinode *left_child, *right_child;

  //length of the edge from this node to its children
  int edge_length;

  int height;

  int lablen;

  //-1=I am left, 0=I am root, 1=right
  int parent_dir;

  //max supported unit32 in dec, 10 digits max
  char label[MAX_CHAR_PER_WORD];
};



//used for printing next node in the same level,
//this is the x coordinate of the next char printed
int print_next;

int MIN (int X, int Y)
{
  return ((X) < (Y)) ? (X) : (Y);
}

int MAX (int X, int Y)
{
  return ((X) > (Y)) ? (X) : (Y);
}

asciinode * build_ascii_tree_recursive(ast *t)
{
  asciinode * node;

  if (t == NULL) return NULL;
  node = malloc(sizeof(asciinode));

  if (t->type == AST_ADD)
  {
    sprintf(node->label, "%s", " + ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_MIN)
  {
    sprintf(node->label, "%s", " - ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_MUL)
  {
    sprintf(node->label, "%s", " * ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_DIV)
  {
    sprintf(node->label, "%s", " / ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_ID)
  {
    sprintf(node->label, "%s(ID)", t->id);
    node->lablen = strlen(node->label);
  }
  if (t->type == AST_NUMBER)
  {
    sprintf(node->label, "%d(NUMBER)", t->number);
    node->lablen = strlen(node->label);
  }
  if (t->type == AST_ASIGN)
  {
    sprintf(node->label, "%s", " = ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_NEG)
  {
    sprintf(node->label, "%s", " -(UN) ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->left_child->parent_dir = -1;
  }
  if (t->type == AST_INCR)
  {
    sprintf(node->label, "%s", " ++ ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->left_child->parent_dir = -1;
  }
  if (t->type == AST_DECR)
  {
    sprintf(node->label, "%s", " -- ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->left_child->parent_dir = -1;
  }
  if (t->type == AST_EQ)
  {
    sprintf(node->label, "%s", " == ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_NEQ)
  {
    sprintf(node->label, "%s", " != ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_GT)
  {
    sprintf(node->label, "%s", " > ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_GE)
  {
    sprintf(node->label, "%s", " >= ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_LT)
  {
    sprintf(node->label, "%s", " < ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_LE)
  {
    sprintf(node->label, "%s", " <= ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_RET)
  {
    sprintf(node->label, "%s", " RETURN ");
    node->lablen = strlen(node->label);
    if(t->op.left != NULL)
    {
      node->left_child = build_ascii_tree_recursive(t->op.left);
      node->left_child->parent_dir = -1;
    }
  }
  if (t->type == AST_FUNC)
  {
    sprintf(node->label, "%s", " FUNC ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_BLOCK)
  {
    sprintf(node->label, "%s", " BLOCK ");
    node->lablen = strlen(node->label);
    if(t->op.left != NULL)
    {
      node->left_child = build_ascii_tree_recursive(t->op.left);
      node->left_child->parent_dir = -1;
    }
  }
  if (t->type == AST_STMT)
  {
    sprintf(node->label, "%s", " STMT ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->left_child->parent_dir = -1;
    if(t->op.right != NULL)
    {
      node->right_child = build_ascii_tree_recursive(t->op.right);
      node->right_child->parent_dir = 1;
    }
  }
  if (t->type == AST_DECL)
  {
    sprintf(node->label, "%s", " DECLARATION ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->left_child->parent_dir = -1;
    if(t->op.right != NULL)
    {
      node->right_child = build_ascii_tree_recursive(t->op.right);
      node->right_child->parent_dir = -1;
    }
  }
  if (t->type == AST_IF)
  {
    sprintf(node->label, "%s", " IF ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  if (t->type == AST_WHILE)
  {
    sprintf(node->label, "%s", " WHILE ");
    node->lablen = strlen(node->label);
    node->left_child = build_ascii_tree_recursive(t->op.left);
    node->right_child = build_ascii_tree_recursive(t->op.right);
    node->left_child->parent_dir = -1;
    node->right_child->parent_dir = 1;
  }
  
  return node;
}


//Copy the tree into the ascii node structre
asciinode * build_ascii_tree(ast *t)
{
  asciinode *node;
  if (t == NULL) return NULL;
  node = build_ascii_tree_recursive(t);
  node->parent_dir = 0;
  return node;
}

//Free all the nodes of the given tree
void free_ascii_tree(asciinode *node)
{
  if (node == NULL) return;
  free_ascii_tree(node->left_child);
  free_ascii_tree(node->right_child);
  free(node);
}

//The following function fills in the lprofile array for the given tree.
//It assumes that the center of the label of the root of this tree
//is located at a position (x,y).  It assumes that the edge_length
//fields have been computed for this tree.
void compute_lprofile(asciinode *node, int x, int y)
{
  int i, isleft;
  if (node == NULL) return;
  isleft = (node->parent_dir == -1);
  lprofile[y] = MIN(lprofile[y], x-((node->lablen-isleft)/2));
  if (node->left_child != NULL)
  {
	  for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++)
    {
	    lprofile[y+i] = MIN(lprofile[y+i], x-i);
    }
  }
  compute_lprofile(node->left_child, x-node->edge_length-1, y+node->edge_length+1);
  compute_lprofile(node->right_child, x+node->edge_length+1, y+node->edge_length+1);
}

void compute_rprofile(asciinode *node, int x, int y)
{
  int i, notleft;
  if (node == NULL) return;
  notleft = (node->parent_dir != -1);
  rprofile[y] = MAX(rprofile[y], x+((node->lablen-notleft)/2));
  if (node->right_child != NULL)
  {
	  for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++)
    {
	    rprofile[y+i] = MAX(rprofile[y+i], x+i);
    }
  }
  compute_rprofile(node->left_child, x-node->edge_length-1, y+node->edge_length+1);
  compute_rprofile(node->right_child, x+node->edge_length+1, y+node->edge_length+1);
}

//This function fills in the edge_length and
//height fields of the specified tree
void compute_edge_lengths(asciinode *node)
{
  int h, hmin, i, delta;
  if (node == NULL) return;
  compute_edge_lengths(node->left_child);
  compute_edge_lengths(node->right_child);

  /* first fill in the edge_length of node */
  if (node->right_child == NULL && node->left_child == NULL)
  {
	  node->edge_length = 0;
  }
  else
  {
    if (node->left_child != NULL)
    {
	    for (i=0; i<node->left_child->height && i < MAX_HEIGHT; i++)
      {
		    rprofile[i] = -INFINITY;
	    }
	    compute_rprofile(node->left_child, 0, 0);
	    hmin = node->left_child->height;
    }
    else
    {
	    hmin = 0;
    }
	  if (node->right_child != NULL)
    {
	    for (i=0; i<node->right_child->height && i < MAX_HEIGHT; i++) /////
      {
		    lprofile[i] = INFINITY;
	    }
	    compute_lprofile(node->right_child, 0, 0);
	    hmin = MIN(node->right_child->height, hmin); //////
    }
    else
    {
	    hmin = 0;
    }
	  delta = 4;
	  for (i=0; i<hmin; i++)
    {
	    delta = MAX(delta, GAP + 1 + rprofile[i] - lprofile[i]);
    }

    //If the node has two children of height 1, then we allow the
    //two leaves to be within 1, instead of 2
	  if (((node->left_child != NULL && node->left_child->height == 1) ||
	      (node->right_child != NULL && node->right_child->height == 1))&&delta>4)
    {
      delta--;
    }

    node->edge_length = ((delta+1)/2) - 1;
  }

  //now fill in the height of node
  h = 1;
  if (node->left_child != NULL)
  {
	  h = MAX(node->left_child->height + node->edge_length + 1, h);
  }
  if (node->right_child != NULL)
  {
	  h = MAX(node->right_child->height + node->edge_length + 1, h);
  }
  node->height = h;
}

//This function prints the given level of the given tree, assuming
//that the node has the given x cordinate.
void print_level(asciinode *node, int x, int level)
{
  int i, isleft;
  if (node == NULL) return;
  isleft = (node->parent_dir == -1);
  if (level == 0)
  {
	  for (i=0; i<(x-print_next-((node->lablen-isleft)/2)); i++)
    {
	    printf(" ");
    }
	  print_next += i;
	  printf("%s", node->label);
	  print_next += node->lablen;
  }
  else if (node->edge_length >= level)
  {
	  if (node->left_child != NULL)
    {
	    for (i=0; i<(x-print_next-(level)); i++)
      {
		    printf(" ");
	    }
	    print_next += i;
	    printf("/");
	    print_next++;
    }
	  if (node->right_child != NULL)
    {
	    for (i=0; i<(x-print_next+(level)); i++)
      {
		    printf(" ");
	    }
	    print_next += i;
	    printf("\\");
	    print_next++;
    }
  }
  else
  {
	  print_level(node->left_child,
                x-node->edge_length-1,
                level-node->edge_length-1);
	  print_level(node->right_child,
                x+node->edge_length+1,
                level-node->edge_length-1);
  }
}

//prints ascii tree for given Tree structure
void print_ascii_tree(ast *t)
{
  asciinode *proot;
  int xmin, i;
  if (t == NULL) return;
  proot = build_ascii_tree(t);
  compute_edge_lengths(proot);
  for (i=0; i<proot->height && i < MAX_HEIGHT; i++)
  {
	  lprofile[i] = INFINITY;
  }
  compute_lprofile(proot, 0, 0);
  xmin = 0;
  for (i = 0; i < proot->height && i < MAX_HEIGHT; i++)
  {
	  xmin = MIN(xmin, lprofile[i]);
  }
  for (i = 0; i < proot->height; i++)
  {
	  print_next = 0;
	  print_level(proot, -xmin, i);
	  printf("\n");
  }
  if (proot->height >= MAX_HEIGHT)
  {
	  printf("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
  }
  free_ascii_tree(proot);
}
