#include<stdio.h>
#include<stdlib.h>

#define MAX 3

typedef struct{
    int front, rear;
    int array[MAX];
}CQueue;

void initialize(CQueue* q) {
	q->front = -1;
	q->rear = -1;
}

void insert(CQueue* q, int item){
    if((q->front==0 && q->rear == MAX-1)||(q->front == q->rear+1))
        printf("\n\nCircular Queue is Full");

    else {
        if(q->front==-1)
            q->front=0;

        q->rear = (q->rear+1)%MAX;
        q->array[q->rear]=item;
    }
}

void delete_element(CQueue* q){
    int val;
    if(q->front==1)
        printf("\n Circular Queue is empty");
    else{
        val = q->array[q->front];
        if(q->front==q->rear)
            q->front=q->rear=-1;
        else
            q->front = (q->front+1)%MAX;
    }
    printf("\n Element deleted = %d", val);
}

void display(CQueue* q){
    int i;
    if(q->front==-1)
        printf("\n Circular Queue is empty");
 else{
        for(i=q->front; i!=q->rear; i=(i+1)%MAX)
            printf("%d  ", q->array[i]);
    }
    printf("%d", q->array[i]);
}

int main(){
    int opt, val;
	CQueue cqueue;
	initialize(&cqueue);

	do{
        printf("\n\n **********MENU**********");
        printf("\n 1. Insert an element \n 2. Display the queue \n 3. Delete an element \n 4. EXIT");
        printf("\n Enter your choice : ");
        scanf("%d", &opt);
        switch(opt){
            case 1: printf("\n Enter the element to insert: ");
                    scanf("%d", &val);
                    insert(&cqueue, val);
                    break;

            case 2: display(&cqueue);
                    break;

            case 3: delete_element(&cqueue);
                    break;

            case 4: break;
            default: printf("\n Wrong Input");
        }
	}while(opt!=4);
    return 0;
}