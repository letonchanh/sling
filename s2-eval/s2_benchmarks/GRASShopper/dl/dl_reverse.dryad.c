#include "stdhipmem.h"



DLNode * dl_reverse(DLNode * lst)
/*@
 infer[@shape]
 requires true
 ensures true;
 */
{
  DLNode * curr = lst;
  DLNode * rev = NULL;
  while(curr != NULL) 
  /*@
   infer[@shape]
   requires true
   ensures true;
   */
  {
    DLNode * tmp;
    tmp = curr;
    curr = curr->next;
    tmp->next = rev;
    if(rev != NULL) {
      rev->prev = tmp;
    }
    rev = tmp;
  }
  return rev;
}
