#include "stdhipmem.h"



BNode * bst_insert_rec(BNode * x, int k)
/*@
 infer[@shape]
 requires true
 ensures true;
 */
{

  if (x == NULL) {
    BNode * leaf = (BNode *) malloc(sizeof(BNode));

    leaf->key   = k;
    leaf->left  = NULL;
    leaf->right = NULL;

    return leaf;
  } else if (k < x->key) {
    BNode * l = x->left;
    BNode * r = x->right;
    BNode * tmp = bst_insert_rec(l, k);

    x->left = tmp;

    return x;
  } else {
    BNode * l = x->left;
    BNode * r = x->right;
    BNode * tmp = bst_insert_rec(r, k);
    
    x->right = tmp;

    return x;
  } 
}
