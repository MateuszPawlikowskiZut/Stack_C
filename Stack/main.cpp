#include <iostream>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct stack
{
	
	int value;
	
	struct stack *prev;
	
} Stack;

Stack *top = NULL;

void Push(int item)
{
	Stack *newStack = (Stack*)malloc(sizeof(Stack));
	
	newStack->value = item;
	
	newStack->prev = top;
	
	top = newStack;
}

int Pop()
{
	if(top == NULL) return -1;
	
	int item = top->value;
	
	Stack *_prev = top->prev;
	
	free(top);
	
	top = _prev;
	
	return item;
}

int Peek()
{
	if(top == NULL)
		return -1;
	
	return top->value;
}

int main(int argc, char** argv) 
{
	int keepGoing = 1;
	
	int wybor, item;
	
	while(keepGoing == 1)
	{
		printf("1. Push \n");
		
		printf("2. Pop \n");
		
		printf("3. Peek \n");
		
		printf("4. Koniec \n");
		
		scanf("%d", &wybor);
		
		switch(wybor)
		{
			case 1:
				
				
				printf("Push item: "); scanf("%d", &item);
				
				Push(item);
				
				break;
			
			case 2:
				
				printf("%d", Pop());
				
				break;
				
			case 3:
				
				printf("%d", Peek());
			
				break;
			
			case 4:
				keepGoing = 0;
				break;
		}
		
		printf("\n ----------------------------- \n");
	}
	
	return 0;
}
