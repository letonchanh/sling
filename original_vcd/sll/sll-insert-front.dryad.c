// ---- Commmon definitions for singly-linked list examples  ----
#include <vcc.h>
#include <stdlib.h>

typedef 
/*D_tag node */
struct node {
  int key;
  struct node * next;
} SNnode;

/*D_defs
define pred sll^(x): 
  ( 
  ((x l= nil) & emp) | 
  ((x |-> loc next: nxt) * sll^(nxt))  
  ) ;
  
define set-fun keys^(x):
  (case (x l= nil): emptyset;
   case ((x |-> loc next: nxt; int key: ky) * true): 
    ((singleton ky) union keys^(nxt));
   default: emptyset
  ) ;*/
// --------------------------------------------------------------


_(dryad)
SNnode * sll_insert_front(SNnode * x, int k)
  /*D_requires sll^(x) */
  /*D_ensures (sll^(ret) & (keys^(ret) s= (old(keys^(x)) union (singleton k)))) */
{
		SNnode * head = (SNnode *) malloc(sizeof(SNnode));
		_(assume head != NULL)
		head->key = k;
		head->next = x;
		return head;
}
