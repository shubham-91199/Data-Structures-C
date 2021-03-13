#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
	int top;
	int* array;
}Stack;

Stack* createStack(){
	Stack* stack = (Stack*)malloc(sizeof(Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
    stack->array = (int*) malloc(MAX*sizeof(int));

	if (!stack->array)
		return NULL;
	return stack;
}

char pop(Stack* stack) {
	if (!(stack->top==-1))
		return stack->array[stack->top--] ;
	return '$';
}

void push(Stack* stack, char op) {
	stack->array[++stack->top] = op;
}

int isEmpty(Stack* stack) {
    return stack->top == -1 ;
}

char peek(Stack* stack) {
    return stack->array[stack->top];
}

int isOperand(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Prec(char ch) {
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}


int infixToPostfix(char* exp) {
	int i, k;

	Stack* stack = createStack();
	if(!stack)
		return -1 ;

	for (i = 0, k = -1; exp[i]; ++i)
	{
		if (isOperand(exp[i]))
			exp[++k] = exp[i];

		else if (exp[i] == '(')
			push(stack, exp[i]);

		else if (exp[i] == ')')
		{
			while (!isEmpty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '(')
				return -1;
			else
				pop(stack);
		}
		else
		{
			while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}
	}

	while (!(stack->top==-1))
		exp[++k] = pop(stack );

	exp[++k] = '\0';
	printf("Postfix expression: %s", exp );
}

int main()
{
	char exp[MAX];
	printf("Infix to Postfix\n");
	printf("\n Enter an infix expression : ");
	scanf("%s", exp);
	infixToPostfix(exp);
	return 0;
}