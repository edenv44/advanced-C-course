#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct worker {
	int id;
	char* name;
	int salary;
	union year {
		unsigned int yearI;
		char yearC[];
	}year;
}worker;

typedef struct WorkerList {
	worker* data;
	struct WorkerList* next;
}WorkerList;

worker* CreateWorker(int type); //OVED
void PrintWorker(int type, const worker* worker1); // OVED
WorkerList* addWorker(WorkerList* head, worker* w1); // OVED
int index(WorkerList* head, long unsigned id); // OVDD
int index1(WorkerList* head, long unsigned id); // OVED
WorkerList* deleteWorstWorker(WorkerList* head); // OVED
void update_worker(WorkerList* head, float percent); // OVED
WorkerList* reverse(WorkerList* head); // OVED
void freeWorkers(WorkerList* head); // OVED

void main() {
	int type = 0;
	WorkerList* head = NULL;  // reset a list named head
	worker wo1 = { 207908997, "guy", 36000, 2020 };  // worker number 1
	worker wo2 = { 207908996, "maor", 12000, 2021 };  // worker number 2
	worker wo3 = { 207908995, "eden", 20023, 2022 };  // worker number 2
	worker wo4 = { 207908994, "natan", 20024, 2023 };  // worker number 4
	printf("set year type:\n0 for foreign\n1 for hebrew\n");
	scanf("%d", &type);
	worker* w1 = CreateWorker(type);
	head = addWorker(head, &wo1);  // add worker number 1 to list - head
	head = addWorker(head, &wo2);  // add worker number 2 to list - head
	head = addWorker(head, &wo3);  // add worker number 3 to list - head
	head = addWorker(head, &wo4);  // add worker number 4 to list - head
	PrintWorker(type, w1);
	update_worker(head, 100);
	PrintWorker(type, w1);
	head = reverse(head);
	PrintWorker(type, w1);
	index1(head, 207908995);
	PrintWorker(type, w1);
	deleteWorstWorker(head);
	PrintWorker(type, w1);
	// addWorker adds a new worker to the correct position in the lincked list according to the workers salary.
	head = reverse(head);  // call reverse function
	PrintWorker(type, w1);
	PrintWorker(type, w1);
	freeWorkers(head);
}

worker* CreateWorker(int type) {
	char* temp = 0;
	worker* worker1 = (worker*)malloc(sizeof(worker));  // search for memory slot large enough to fit worker type.
	if (!worker1) { // chack if location searching has failed.
		puts("allocation failed");
	}
	printf("Please enter ID:\n");
	scanf("%d", &worker1->id);  // ID request.
	worker1->name = (char*)malloc(sizeof(char));  // locate memory slot for worker name.
	if (worker1->name == NULL)  // check if location searching has failed. 
		printf("allocation failed");
	printf("Please enter your name:\n");
	scanf("%s", worker1->name);  // name request.
	printf("Please enter your salary:\n");
	scanf("%d", &worker1->salary);  // salary request.
	switch (type)  // check type cases.
	{
	case 0: // in case the value that the user entered means foreigne year
		printf("Please enter the foreign begin year:\n");
		scanf("%d", &worker1->year.yearI);
		break;

	case 1:  // in case the value that the user entered means Hebrew year
		printf("Please enter the hebrew begin year:\n");
		scanf("%s", worker1->year.yearC);
		break;

	default:  // in case the value that was entered is incorrect.
		printf("The value isnt correct");
	}
	return worker1;
}

void PrintWorker(int type, const worker* worker1) {
	printf("Worker's ID: %d\nWorker's Name: %s\nWorker's Salary: %d\n", worker1->id, worker1->name, worker1->salary);
	switch (type)  // check type cases.
	{
	case 0:  // in case the year entered was a foreign year
		printf("Worker's Begin Year: %d\n", worker1->year.yearI);
		break;

	case 1:  // in case the year entered was a hebrew year
		printf("Worker's Begin year: %s\n", worker1->year.yearC);
		break;

	default: printf("Try again"); // in case of peculiar instance.
	}
}

WorkerList* addWorker(WorkerList* head, worker* w1) {
	WorkerList* new_worker = (WorkerList*)malloc(sizeof(WorkerList));  // locating larger memory slot for bigger lincked list.
	if (!new_worker) {  // check if location searching has failed.
		puts("allocation faild");
		return head;
	}
	new_worker->data = w1;  // insert new worker in to data of the new worker part of the list.
	new_worker->next = 0;  // reset next pointer of new worker.
	if (head == NULL) {  // check if list is empty.
		head = w1;  // insert new worker in to first locations data in the lincked list.
		new_worker->next = NULL;  // NULLIFY next pointer.
		return new_worker;
	}
	WorkerList* ptr = NULL;
	WorkerList* temp = head;

	while (temp != NULL && temp->data->salary < new_worker->data->salary) {  // move temp to last position unless proper location is found.
		ptr = temp;
		temp = temp->next;
	}
	new_worker->next = temp;  // if proper location wasn't found add worker to last place. 
	if (ptr) {  // set next location as new worker.
		ptr->next = new_worker;
	}
	else {
		head = new_worker;
	}
	return head;
}

int index(WorkerList* head, long unsigned id) {
	int counter = 2;  // counter will count indexes untill the right ID id found.
	WorkerList* temp = head;  // set temp inorder to keep the head pointer as the pointer to the begining of the list.
	if (head == NULL) {  // in case the list is empty.
		return -1;
	}
	if (head->data->id == id) {  // check first index in list.
		return 1;
	}
	temp = temp->next;  // temp is now the second worker in the list.
	do
	{
		if (temp->data->id == id) {  // check if ID matches.
			return counter;  //  if the ID matches return index of worker in list/
		}
		counter++;  // if match wasn't found raise index counter.
		temp = temp->next;  // progress temp to next worker.
	} while (temp != NULL);  // will run until reaches last index is checked.
	return -1;  // if no ID in the list matched the ID that was searched return -1.
}

int index1(WorkerList* head, long unsigned id) {  //  recursive index search.
	static int counter = 1;  //  defined as static in order to not reset counter every recursion.
	if (head == NULL) {  // first check if list is empty. also exit condition - if head has progressed to far.
		return -1;
	}
	if (head->data->id == id) {  // check current index ID.
		return counter;
	}
	else {
		counter = index1(head->next, id) + 1;  // progress head to next index in list recursively.
	}  // head wont be lost given this function is recursive so when the right ID is found the recursion will reset head as first pointer.
}

WorkerList* deleteWorstWorker(WorkerList* head) {  // removes worker with lowest salary from list.
	WorkerList* temp = head;
	int counter = 0;
	int indx = 0;
	int sal = head->data->salary;  // sal will start off as equal to salary of first index.
	while (temp != NULL) {  // will run until temp out of list.
		if (temp->data->salary < sal) {   // check if salary is lower then current sal variable.
			sal = temp->data->salary;  // if salary is lower then change sal in to lower salary.
			indx = counter;  // save current counter(index in list) in indx variable. 
		}
		temp = temp->next;  // of lower salary was found not progres temp anyway.
		counter += 1;  // raise counter to next index that will be checked.
	}
	WorkerList* temp1 = head;
	if (head->data->salary == sal) {
		head = head->next;
		temp1->next = NULL;
		return head;
	}
	for (int rightI = 0; rightI <= indx; rightI++) {
		temp1 = temp1->next;  //  progres temp1 until index before lowest salary index that was found.
		if (temp1->next->data->salary == sal) {
			if (temp1->next->next == NULL) {
				temp1->next = NULL;
			}
			else {
				temp1->next = temp1->next->next;
			}
			break;
		}
	}
	return head;
}

void update_worker(WorkerList* head, float percent) {
	WorkerList* temp = head;  // temp was defined in order to keep head as first pointer.
	if (head == NULL) {  // in case list is empty.
		return;
	}
	while (temp != NULL) {  // will run on every single worker in list.
		temp->data->salary += (percent / 100) * temp->data->salary;  // raise salary by given percentage.
		temp = temp->next;  // progress to next worker and do the same.
	}
}

WorkerList* reverse(WorkerList* head) {  //  meant to revers order of list.
	if (head == NULL) {  // in case list is empty;
		return head;
	}
	if (head->next == NULL) {  // in case list has only 1 worker.
		return head;
	}
	WorkerList* temp = head;
	WorkerList* save = head;
	int counter = 1, amount = 0;
	while (temp->next != NULL) {  // progress temp to last worker.
		counter++;  // count amount of workers.
		temp = temp->next;
		save = temp;  // save pointer to last worker.
	}
	temp = head;  // reset temp to begining of list.
	amount = counter;  // both amount and counter are worth the amount of workers.
	for (int i = 1; i < amount; i++) {
		for (int j = 1; j < counter - 1; j++) {
			temp = temp->next;  // get temp to 1 before last worker.
		}
		temp->next->next = temp;  // will change last workers next pointer to point at 1 before last. 
		counter--;  // decrease counter so next run will change previouse worker.
		if (counter == 2) {  // when first worker has been reached discontinue the loop.
			break;
		}
		temp = head;  // reset counter to begining.
	}
	head->next->next = head;
	head->next = NULL;  // reset former heads pointer.
	head = save;  //  reset head to be the new first pointer.
	return head;
}

void freeWorkers(WorkerList* head) {  //  free all workers.
	WorkerList* temp = head;
	while (head != NULL) {  // run until empty list remains.
		temp = head;
		head = head->next;  // progress head to next worker.
		free(temp);  // free memory of former head.
	}
}