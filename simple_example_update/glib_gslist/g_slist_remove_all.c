#include "header.h"
#include <stdio.h>
#include <stdlib.h>

Node * g_slist_remove_all(Node * list, int data)
{
	//pre
	Node *tmp, *prev = NULL;
	tmp = list;
    int tp;

	while(tmp != NULL)
	{
		//loop
		if (tmp->key == data)
		{
			Node * tmp_next = tmp->next;
			if (prev != NULL) {
        		tp = prev->key;
				prev->next = tmp_next;
			} else {
				list = tmp_next;
			}
			free(tmp);
			tmp = tmp_next;
		} else {
			prev = tmp;
			tmp = prev->next;
		}
	}
	//post
	return list;
}

int main(int argc, char * argv[]){
	int size = 0;
	sscanf(argv[1],"%d", &size);
    Node * root = create_list(size);
    Node * res = g_slist_remove_all(root, rand_num());
	g_slist_remove_all(NULL, rand_num());
    return 0;
}
