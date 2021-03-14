#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack {
	int top;
	int len;
	int* array;
	};

struct Stack* initialize(int len) {
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->len = len;
	stack->top = -1;
	stack->array = (int*) malloc(stack->len * sizeof(int));
	return stack;
	}

int isFull(struct Stack* stack) {
    return (stack->top == stack->len - 1);
    }

int isEmpty(struct Stack* stack){
    return (stack->top == -1);
    }

void push(struct Stack* stack, int item) {
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
	}

int pop(struct Stack* stack) {
	if (isEmpty(stack))
		return;
	return stack->array[stack->top--];
	}

int main(){
    int n, i = 1, item;
    printf("Enter the no. elements to insert: ");
    scanf("%d", &n);
    struct Stack* stack = initialize(n);
    struct Stack* temp = initialize(n);

    while(i<=n){
        printf("Enter element :");
        scanf("%d", &item);
        i++;
        if(stack->top == -1){
            push(stack, item);
        }
        else{
            if(stack->array[stack->top]>=item)
                push(stack, item);
            else{
                while(stack->array[stack->top]<item){
                    push(temp, pop(stack));
                }
                push(stack, item);
                while(temp->top != -1){
                    push(stack, pop(temp));
                }
            }
        }
    }
    printf("Sorted array is: ");
    while(stack->top!=-1)
        printf("%d ", pop(stack));
    return 0;
}