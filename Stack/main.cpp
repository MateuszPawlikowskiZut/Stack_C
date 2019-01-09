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
	//Tworzenie nowego wskaznika do struktury stosu
	Stack *newStack = (Stack*)malloc(sizeof(Stack));
	
	//Zapisanie danej wartosci do nowego elementu stosu
	newStack->value = item;
	
	//Zapisanie poprzedniego elementu do wskaznika w nowym elemencie 
	newStack->prev = top;
	
	//Ustawienie wskaznika top na nowy element
	top = newStack;
}

int Pop()
{
	//Jezeli stos jest pusty to zwroc -1
	if(top == NULL) return -1;
	
	//Zapisz w zmiennej pomocniczej wartosc z wyciaganego elementu
	int item = top->value;
	
	//Zapisane we wskazniku pomocniczym wskaznika do nastepnego elementu
	Stack *_prev = top->prev;
	
	//Wyczyszczenie aktualnego elementu
	free(top);
	
	//Ustawienie poprzedniego elementu jako akualny element.
	top = _prev;
	
	//Zwrocenie wartosci z wyciaganego elementu
	return item;
}

int Peek()
{
	//Jezeli stos jest pusty to zwroc -1
	if(top == NULL)
		return -1;
	
	//Wyciagnij wartosc z aktualnego elementu bez jego usuwania
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
