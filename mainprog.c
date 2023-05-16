#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct sNode {
	int value;
	struct sNode* next;
}list;

list* read_list() {
	list* head = malloc(sizeof(list));
	head->next = NULL;
	list* p = head;

	int u;
	printf("Enter the test file number:");
	scanf("%d", &u);
	char* file_name = "";
	if (u == 1)
	{
		file_name = "elems1.txt\0";
	}
	else if (u == 2)
	{
		file_name = "elems2.txt\0";
	}
	else if (u == 3) {
		file_name = "elems3.txt\0";
	}
	else {
		list* null_result = malloc(sizeof(list));
		null_result->next = NULL;
		return null_result;
	}

	int val;
	FILE* file;
	file = fopen(file_name, "r");
	while (fscanf(file, "%d", &val) != EOF) {
		p->next = malloc(sizeof(list));
		p = p->next;
		p->value = val;
		p->next = NULL;
	}
	fclose(file);
	return head;
}

list* enter_list() {
	list* head = malloc(sizeof(list));
	head->next = NULL;
	list* p = head;
	int n;
	int value;
	printf("Enter the number of totalized objects:");
	scanf("%d", &n);
	while (n > 0) {
		if (scanf("%d", &value) == 1) {
			p->next = malloc(sizeof(list));
			p = p->next;
			p->value = value;
			p->next = NULL;
			n--;
		}
		else {
			list* null_result = malloc(sizeof(list));
			null_result->next = NULL;
			return null_result;
		}
	}
	return head;
}

int sum_list(list* head) {
	int result = 0;
	list* p = head->next;
	while (p != NULL) {
		result += p->value;
		p = p->next;
	}
	return result;
}

float average_list(list* head) {
	float sum = 0;
	float count = 0;
	list* p = head->next;
	if (p == NULL) {
		return 0;
	}
	else {
		while (p != NULL) {
			sum += p->value;
			count += 1;
			p = p->next;
		}
		float result = sum / count;
		return result;
	}
}

int sum() {
	int option;
	printf("This program calculates the sum of the list items. the list is filled in from a file or from the keyboard with integer values. The operating mode is selected in the following menu\n");
	printf("1 - Read data from file\n2 - Enter data on keyboard\nEnter a number for the operation:");
	scanf("%d", &option);
	list* lst;
	if (option == 1) {
		lst = read_list();
		if (lst->next == NULL) {
			printf("Error! Invalid file number entered!\n");
		}
	}
	else if (option == 2) {
		lst = enter_list();
		if (lst->next == NULL) {
			printf("Error! An incorrect number of elements was entered or the element does not match the integer type!\n");
		}
	}
	else {
		printf("No such operation!\n");
		lst = malloc(sizeof(list));
		lst->next = NULL;
	}
	int sum = sum_list(lst);
	return sum;
}

float average() {
	int option;
	printf("This program calculates the sum of the list items. the list is filled in from a file or from the keyboard with integer values. The operating mode is selected in the following menu\n");
	printf("1 - Read data from file\n2 - Enter data on keyboard\nEnter a number for the operation:");
	scanf("%d", &option);
	list* lst;
	if (option == 1) {
		lst = read_list();
		if (lst->next == NULL) {
			printf("Error! Invalid file number entered!\n");
		}
	}
	else if (option == 2) {
		lst = enter_list();
		if (lst->next == NULL) {
			printf("Error! An incorrect number of elements was entered or the element does not match the integer type!\n");
		}
	}
	else {
		printf("No such operation!\n");
		lst = malloc(sizeof(list));
		lst->next = NULL;
	}
	int avrg = average_list(lst);
	return avrg;
}

int main() {
	int option;
	int result1;
	float result2;
	printf("The prog1 program calculates the sum of the list items. \n");
	printf("The prog2 program calculates the arithmetic mean of the list items.\nThe list is filled in from a file or from the keyboard with integer values. The operating mode is selected in the following menu\n");
	printf("\n1 - prog1\n2 - prog2\n3 - quit\nEnter a number for the program:");
	scanf_s("%d", &option);
	if (option == 1) {
		result1 = sum();
		printf("Result of prog1: %i\n", result1);
	}
	else if (option == 2) {
		result2 = average();
		printf("Result of prog2: %f\n", result2);
	}
	else {
		printf("No such function!\n");
	}
}