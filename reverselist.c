#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
    int number;
    struct linked_list *next;
};

typedef struct linked_list node;
node *head=NULL, *last=NULL;

void create_linked_list();
void print_linked_list();
void insert_at_last(int value);
void reverse();
void search();

int main()
{
    int key, value,ch;

    printf("Create Linked List\n");
    create_linked_list();
    print_linked_list();

    do
    {
    printf("\n\n1. Insert element\n2. Display\n3. Reverse\n4. Search\n5. EXIT\n\n Enter Your Choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
          case 1:   printf("\nInsert new item at last\n");
                    scanf("%d", &value);
                    insert_at_last(value);
                    break;

          case 2:   print_linked_list();
                    break;

          case 3:   reverse();
                    break;

          case 4:   search();
                    break;

          case 5:   break;

          default: printf("wrong input\n");
    }
    }while(ch!=5);

    return 0;
}


void create_linked_list()
{
    int val;

    while(1)
    {
        printf("Input a number. (Enter -1 to exit)\n");

        scanf("%d", &val);

        if(val==-1)
            break;

        insert_at_last(val);
    }

}


void insert_at_last(int value)
{
    node *temp_node;
    temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    temp_node->next=NULL;


    if(head==NULL)
    {
        head=temp_node;
        last=temp_node;
    }
    else
    {
        last->next=temp_node;
        last=temp_node;
    }

}


void print_linked_list()
{
    printf("\n\nYour full linked list is\n");

    node *myList;
    myList = head;

    while(myList!=NULL)
    {
        printf("%d ", myList->number);

        myList = myList->next;
    }
    puts("");
}


void reverse(){
     node* prev = NULL;
     node* current = head;
     node* next = NULL;

     while(current!=NULL){
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }
     head = prev;
}


void search(){
     int num;
     node* temp;
     printf("\nEnter an element to search: ");
     scanf("%d", &num);

     for(temp = head; temp!=NULL; temp=temp->next){
          if(num==temp->number)
               printf("\n Element found at %p", temp);
     }
}