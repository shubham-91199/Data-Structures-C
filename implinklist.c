#include<stdio.h>
#include<stdlib.h>

struct N{
    int item;
    struct N* next;
};

typedef struct N Node;

Node *start=NULL, *tail=NULL, *ptr;
void create(){
    int choice;
    do{
        ptr = (Node*)malloc(sizeof(Node));
        printf(" Enter the info : ");
        scanf("%d", &ptr->item);
        if(start==NULL)
            start = tail = ptr;
        else{
            tail->next = ptr;
            tail = ptr;
        }
        printf(" Do you want to continue ? (Press 1-> Continue / 0-> Return to Menu )");
        scanf("%d", &choice);
    }while(choice==1);
    tail->next=NULL;
}

void display(){
    Node* temp;
    for(temp= start; temp!=NULL; temp=temp->next)
        printf(" %d  ", temp->item);
}

void delete_element(){
   

 Node* temp;
    int n;
    temp = start;
    n = temp->item;
    start = start->next;
    free(temp);
    printf("\n Deleted element : %d", n);
}

void main(){
        int opt;
        do{
        printf("\n ****** MENU ******\n1. Enter elements\n2. Display Elements\n3. Delete Element\n4. EXIT\n\n Enter your choice: ");
        scanf("%d", &opt);
        switch(opt){
                case 1: create();
                        break;
                case 2: display();
                        break;
                case 3: delete_element();
                        break;
                case 4:
                        break;
                }
        }while(opt!=4);
}