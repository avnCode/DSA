#include <stdio.h>
#include <stdlib.h>
#include "pplist.h"

int main()
{   
    int arr[]={2,10,56,4,5,9,7,8,844,81,8,9,44,8,44,8,66,8,1,6,777,6,7,3,3,8,9,7,6,7,6,8,2,9,88,3,4,66,7,6,85,9,2,8,3,53,5,26,9,12,9,62,6622,6,369};    
    int s=sizeof(arr)/sizeof(arr[0]);

    struct node *head = malloc(sizeof(struct node));
    head->data=arr[0];
    head->link=NULL;
    struct node *b= head;

    struct node *current ;

    for (int i=1;i<=s;i++ )
    {
        current= malloc(sizeof(struct node));
        current->data=arr[i];
        current->link=NULL;
        b->link=current;
        b=b->link;
        // EDITED
        if (i==s)
        {
            b=NULL;
        }
        
    }

    unique2(head);
    printf("\nI am result!\n");
    
    struct node *p=head;
	while(p->link != NULL)
	{
		printf("%d ",p->data);
		p = p->link;
	}
}