#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50

struct Stack {
	int top;
	int len;
	char* array;
	};

struct Stack* initialize(int len) {
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->len = len;
	stack->top = -1;
	stack->array = (char*) malloc(stack->len * sizeof(char));
	return stack;
	}

int isFull(struct Stack* stack) {
    return (stack->top == stack->len - 1);
    }

int isEmpty(struct Stack* stack){
    return (stack->top == -1);
    }

void push(struct Stack* stack, char item) {
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
	}

char pop(struct Stack* stack) {
	if (isEmpty(stack))
		return;
	return stack->array[stack->top--];
	}

void reverse(char str[50]) {
	int n = strlen(str);
	struct Stack* stack = initialize(n);

	int i;
	for (i = 0; i < n; i++)
		push(stack, str[i]);

	for (i = 0; i < n; i++)
		str[i] = pop(stack);
		}

int main() {
	char str[MAX];
	printf("\n Enter a string : ");
	fgets(str, MAX, stdin);
	reverse(str);
	printf("Reversed string : %s", str);
return 0;
	}