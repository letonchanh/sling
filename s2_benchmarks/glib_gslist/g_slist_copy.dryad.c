#include "stdhipmem.h"



Node * g_slist_copy(Node * list)
/*@
 infer[@shape]
 requires true
 ensures true;
 */
{
	Node * new_list = NULL;
	if (list != NULL) {
		Node * last = NULL;

		new_list = (Node *) malloc(sizeof(Node));

    
    int list_key = list->key;
		new_list->key = list_key;
		new_list->next = NULL; 

		last = new_list;

		list = list->next; 

		while(list != NULL)
        /*@
         infer[@shape]
         requires true
         ensures true;
         */

		{
			Node * tail = (Node *)malloc(sizeof(Node));


      int list_key = list->key;
 			tail->key = list_key;
			tail->next = NULL;

			last->next = tail;
			last = last->next;

			list = list->next;
		}
	}
	
	return new_list;
}
