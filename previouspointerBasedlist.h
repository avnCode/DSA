
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};


void  empty(struct node *H)
{
    if (H==NULL)
    {
        printf("Empty List ");
    }
    else
    {
        printf("List is not Empty");
    }
}


struct node * insert(struct node *H, int p, int x)
{
    int i=1;
    struct node* h=H;
    struct node* temp= (struct node *)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=NULL;
        if (p==1)
        {    
        temp->link=H;
        H=temp;
        return H;   
        }
    else
    {
    while (i<p-1)
    {
        h=h->link;
        i=i+1;
    }
    printf("This is running...");
    temp->link=h->link;
    h->link=temp;
    }
    return H;
}

int retrieve(struct node *H, int p)
{
    int i=1;
    struct node* h=H;
    while (i<p)
    {
        h=h->link;
        i=i+1;
    }
    int x=h->data;
    return x;
}

struct node *del(struct node *H,int p)
{
    if (p==1)
    {
        H=H->link;
        return H;
    }
    else
    {
    int i=1;
    struct node* h=H;
    while (i<p-1)
    {
        h=h->link;
        i=i+1;
    }

    h->link=h->link->link;
    return H;
    }
}


void unique2(struct node *H)
{   
    struct node * temp = H;
    int tp=1;
    while(temp->link!=NULL)
    {   
        int a=temp->data;
        int hp=tp+1;
        struct node *h=temp->link;
        while (h!=NULL)
        {
            if (a==retrieve(H,hp))
            { 

                del(H,hp);
                hp=hp-1;
            }

            hp=hp+1;
            h=h->link;
        }

        tp=tp+1;
        temp=temp->link;

    }


}