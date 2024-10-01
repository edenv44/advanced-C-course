#define _CRT_SECURE__NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct charNode {
	char data;
	struct charNode* next;
} charNode;
//???? ???? ?? ??????
typedef struct Stack {
	charNode* head;
} Stack;

/****** Stack ADT Implementation ******/

void initStack(Stack* s);
void destroyStack(Stack* s);
void push(Stack* s, char data);
char pop(Stack* s);
int isEmptyStack(const Stack* s);
void flipBetweenHashes(const char* sentence);
int isPalindrome(Stack* s);
void rotateStack(Stack* s, int n);

void main()
{
	char f, e, d;
	char str[] = { "remem#reb# thi#carp s#tice" };

	int i = 0;
	Stack* s = (Stack*)malloc(sizeof(Stack));
	if (!s) {
		printf("allocation failed.");
		exit(1);
	}
	initStack(s);
	push(s, 'f');
	push(s, 'e');
	push(s, 'd');
	pop(s);
	pop(s);
	pop(s);
	printf("Check if POP and PUSH are working:\n");
	if (isEmptyStack(s) == 1)
		printf("The stack is empty\n");
	else printf("The stack is not empty\n");
	push(s, 'n');
	push(s, 'o');
	destroyStack(s);
	printf("Check if isEmptystack is working:\n");
	if (isEmptyStack(s) == 1)
		printf("The stack is empty\n");
	else printf("The stack is not empty\n");
	//flipBetweenHashes(str); not working
	Stack* st = (Stack*)malloc(sizeof(Stack));
	push(st, 'n');
	push(st, 'o');
	push(st, 'o');
	push(st, 'n');
	//isPalindrome(s); not working
	destroyStack(st);
	Stack* sta = (Stack*)malloc(sizeof(Stack));
	push(sta, 'f');
	push(sta, 'e');
	push(sta, 'd');
	push(sta, 'c');
	push(sta, 'b');
	push(sta, 'a');
	//rotateStack(s, 3); not working
}

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	charNode* temp = s->head;
	while (s->head != NULL) {
		temp = temp->next;
		s->head->data = NULL; // delete the data
		free(s->head);
		s->head = temp;
	}
}

void push(Stack* s, char data)
{
	charNode* newVar = (charNode*)malloc(sizeof(charNode));
	if (newVar == NULL)
		printf("allocation failed");
	if (s->head == NULL) {
		s->head = newVar;
		newVar->next = NULL;
		newVar->data = data;
	}
	else {
		newVar->data = data;
		newVar->next = s->head;
		s->head = newVar;
	}

}

char pop(Stack* s)
{
	char tempo;
	tempo = s->head->data;
	charNode* temp = s->head;
	s->head = s->head->next;
	temp->data = NULL;
	free(temp);
	temp = NULL;
	return tempo;
}


int isEmptyStack(const Stack* s)
{
	if (s->head == NULL)
		return 1;
	else return 0;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	Stack* HelpS = (Stack*)malloc(sizeof(Stack));
	if (HelpS == NULL)
		printf("allocation failed");
	int i = 0, counter = 0;
	while (sentence[i] != '\0') {
		if (sentence[i] != '#')
			printf("%c", sentence[i]);
		else {
			counter++; // count the number of #
			i++;
			int intemp = 0;
			while (sentence[i] != '#') {
				push(HelpS, sentence[i]); // Push the items between 2 asterisks to new stack
				i++;
				intemp++; // count how much letters between 2 asterisks
			}
			counter++; // Here we get to the second asterisk
			if (counter % 2 == 0 && counter != 0) { // if you get to another asterisks (the second) - start print 
				while (intemp != 0) {
					printf("%c", HelpS->head->data);
					pop(HelpS);
					intemp--;
				}
			}

		}
		i++;

	}
	free(HelpS);
}

int isPalindrome(Stack* s)
{
	if (s->head == NULL)
		return 1;

	int size = 0, counter = 1;
	charNode* temp1 = s->head;
	charNode* temp2 = s->head;

	while (temp1 != NULL) {
		size++;
		temp1 = temp1->next;
	}
	temp1 = s->head;
	for (int i = 1; i <= (size + 1) / 2; i++) {
		for (int j = 1; j < size; j++) {
			temp2 = temp2->next;
		}
		if (temp2->data != temp1->data) {
			return 0;
		}
		temp1 = temp1->next;
		size -= 2;
		temp2 = temp1;
		if (size == 1 || size == 0) {
			return 1;

		}

	}
}

void rotateStack(Stack* s, int n)
{
	if (n < 0 || s->head == NULL)
		return;
	Stack* temp1 = (Stack*)malloc(sizeof(Stack));
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	if (temp == NULL || temp1 == NULL)
		printf("allocation failed");
	initStack(temp1);
	initStack(temp);
	charNode* temp2 = s->head;
	temp->head = s->head;
	int count = 0;
	while (temp2 != NULL) {
		count++;
		temp2 = temp2->next;
	}
	if (n > count)
	{
		return;
	}
	for (int i = 0; i < count - n; i++) // cut the stack by count - n letters to new stack
	{
		char tav = pop(s);
		push(temp, tav);
	}
	for (int i = 0; i < n; i++) //  cut the stack by n letters to new stack
	{
		char tav = pop(s);
		push(temp1, tav);
	}

	for (int i = 0; i < count - n; i++) // push the items to stack by order
	{
		char tav = pop(temp);
		push(s, tav);
	}
	for (int i = 0; i < n; i++) //push the items to stack by order
	{
		char tav = pop(temp1);
		push(s, tav);
	}
	while (s->head != NULL) // print new stack
	{
		printf("%c\n", s->head->data);
		s->head = s->head->next;
	}
	free(temp);
	free(temp1);
}