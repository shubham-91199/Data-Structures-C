#include<stdio.h>
#include<stdlib.h>

struct N{
    int item;
    struct N* next;
};
typedef struct N Node;
Node *start=NULL, *tail=NULL, *ptr, *preptr, *pos;
int count=0;

void insert_beg();
void insert_end();
void insert_pos(int);
void display();
void delete_beg();
void delete_end();
void delete_pos(int);

void main(){
        int opt, pos;
        do{
        printf("\n ****** MENU ******\n1. Create List\n2. Display Elements\n3. Enter at the beginning\n4. Enter at the end\n5. Enter in the middle\n6. Enter at the position\n");
        printf("7. Delete from the beginning\n8. Delete from the end\n9. Delete from the middle\n10. Delete from the position\n11. EXIT\n\n Enter your choice: ");
        scanf("%d", &opt);
        switch(opt){
                case 1: insert_end();
                        break;
                case 2: display();
                        break;
                case 3: insert_beg();
                        break;
                case 4: insert_end();
                        break;
                case 5: insert_pos((count/2 + 1));
                        break;
                case 6: printf("\n Enter the position to enter : ");
                        scanf("%d", &pos);
                        insert_pos(pos);
                        break;
                case 7: delete_beg();
                        break;
                case 8: delete_end();
                        break;
                case 9: delete_pos((count/2 + 1));
                        break;
                case 10: printf("\n Enter the position to delete : ");
                        scanf("%d", &pos);
                        delete_pos(pos);
                        break;
                case 11:
                        break;
                }
        }while(opt!=11);
}

void insert_end(){
    int choice;
    do{
        ptr = (Node*)malloc(sizeof(Node));
        printf(" Enter the info : ");
        scanf("%d", &ptr->item);
        if(start==NULL){
            start = tail = ptr;
            count++;
        }
        else{
            tail->next = ptr;
            tail = ptr;
            count++;
        }
        printf(" Do you want to continue ? (Press 1-> Continue / 0-> Return to Menu )");
        scanf("%d", &choice);
    }while(choice==1);
    tail->next=NULL;
}

void insert_beg(){
    ptr = (Node*)malloc(sizeof(Node));
    printf(" Enter the info : ");
    scanf("%d", &ptr->item);
    ptr->next = start;
    start = ptr;
    count++;
}

void insert_pos(int n){
    int c=1;
    ptr = (Node*)malloc(sizeof(Node));
    printf(" Enter the info : ");
    scanf("%d", &ptr->item);
    pos = start;
    while(c!=n){
        preptr = pos;
        pos = pos->next;
        c++;
    }
    preptr->next = ptr;
    ptr->next = pos;
    count++;
}


void display(){
    Node* temp;
    for(temp= start; temp!=NULL; temp=temp->next)
        printf(" %d  ", temp->item);
}

void delete_beg(){
    Node* temp;
    int n;
    temp = start;
    n = temp->item;
    start = start->next;
    free(temp);
    count--;
    printf("\n Deleted element : %d", n);
}

void delete_end(){
    int n;
    pos = start;
    while(pos->next!=NULL){
        preptr = pos;
        pos = pos->next;
    }
    n = pos->item;
    preptr->next = NULL;
    free(pos);
    count--;
    printf("\n Deleted element : %d", n);
}

void delete_pos(int n){
    int c = 1;
    int p;
    pos = start;
    while(c!=n){
        preptr = pos;
        pos = pos->next;
        c++;
    }
    p = pos->item;
    preptr->next = pos->next;
    free(pos);
    count--;
    printf("\n Deleted element : %d", p);
}