#include<stdio.h>
#include<malloc.h>
void main()
{
    int ch,x;
    do
    {
        printf("\n ******* DOUBLY LINKED LIST *******\n 1.create\n 2.insert\n 3.display\n 4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
                    break;
            case 2: printf("enter the value to be inserted at the end:\n");
                    scanf("%d",&x);
                    insert(x);
                    break;
            case 3: display();
                    break;
            case 4: break;
            default:printf("Wrong Input");
        }
    }while(ch!=4);
}
struct linkedlist
{
    int data;
    struct linkedlist *prev, *next;
};
typedef struct linkedlist node;
node *start,*tail;
void insert(int val)
{
    node *ptr,*temp;
    ptr =(node*)malloc(sizeof(node));
    ptr->data=val;
    if(start==NULL)
        start=tail=ptr;
    else
    {
        temp = tail;
        tail->next=ptr;
        tail=tail->next;
        tail->prev=temp;
        tail->next=NULL;
    }
}
void create()
{
    int val;
    do
    {
        printf("Enter values:\nEnter -1 to exit\n");
        scanf("%d",&val);
        if(val!=-1)
            insert(val);
    }while(val!=-1);
}
void display()
{
    node *ptr;
    if(start==NULL)
       printf("linkedlist empty\n");
    else
    {
        ptr=start;
        printf("The doubly linked list is: ");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
