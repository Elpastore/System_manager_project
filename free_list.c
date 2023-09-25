#include "main.h"
/**
 * free_list: function  that free list
 */
void free_list(system_m *head)
{
	system_m *temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->name);
		free(temp->poste);
		free(temp);	
	}
}
