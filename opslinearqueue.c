#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
	int front, rear;
	int array[MAX];
}Queue;

void initialize(Queue* q) {
	q->front = -1;
	q->rear = -1;
}

void enqueue(Queue* q, int item)
{
	if(q->rear == MAX-1)
        printf("\nQueue is Full\n");
    else{
        if(q->rear==-1){
             q->rear = q->front = 0;
            q->array[q->rear] = item;
        }
        else{
            q->array[++q->rear] = item;
        }
    }
}

void dequeue(Queue* q){
	if (q->rear == -1 || q->front == q->rear+1)
		printf("\nQueue is empty\n");
	int item = q->array[q->front++];
	printf("\n Deleted element = %d", item);
}

void display(Queue* q){
    int i;
    if (q->rear == -1 || q->front == q->rear+1)
		printf("\nQueue is empty\n");
    for(i=q->front ; i<=q->rear; i++)
        printf("%d  ", q->array[i]);
}

int main()
{
	int opt, val;
	Queue queue;
	initialize(&queue);

	do{
        printf("\n\n **********MENU**********");
        printf("\n 1. Insert an element \n 2. Display the queue \n 3. Delete an element \n 4. EXIT");
        printf("\n Enter your choice : ");
        scanf("%d", &opt);
        switch(opt){
            case 1: printf("\n Enter the element to insert: ");
                    scanf("%d", &val);
                    enqueue(&queue, val);
                    break;

            case 2: display(&queue);
                    break;

            case 3: dequeue(&queue);
                    break;

            case 4: break;
            default: printf("\n Wrong Input");
        }
	}while(opt!=4);
	return 0;
}
