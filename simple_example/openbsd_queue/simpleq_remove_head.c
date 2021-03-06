#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void simpleq_remove_head(Node * head)
{
  //pre
  Node * fst = head->next;
  Node * fstn = fst->next;
  head->next =fstn;
  if (fstn == NULL) {
    head->last = head;
  }
  free(fst);
  //post
}

int main(int argc, char * argv[]){
    int size = 0;
    sscanf(argv[1],"%d",&size);
    Node * hd = create_queue_buggy(size);
    simpleq_remove_head(hd);
    return 0;
}
