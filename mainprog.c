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
	int value;
	FILE* file;
	fopen_s(&file, "elems.txt", "r");
	while (fscanf_s(file, "%d", &value) != EOF) {
		p->next = malloc(sizeof(list));
		p = p->next;
		p->value = value;
		p->next = NULL;
	}
	fclose(file);
	return head;
}

list* enter_list() {
	list* head = malloc(sizeof(list));
	list* p = head;
	int n;
	int value;
	printf_s("Enter the number of totalized objects:");
	scanf("%d", &n);
	while (n > 0) {
		scanf("%d", &value);
		p->next = malloc(sizeof(list));
		p = p->next;
		p->value = value;
		p->next = NULL;
		n--;
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
	while (p != NULL) {
		sum += p->value;
		count += 1;
		p = p->next;
	}
	float result = sum / count;
	return result;
}

int sum() {
	int option;
	printf("1 - Read data from file\n2 - Enter data on keyboard\nEnter a number for the operation:");
	scanf("%d", &option);
	list* lst;
	if (option == 1) {
		lst = read_list();
	}
	else if (option == 2) {
		lst = enter_list();
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
	printf("1 - Read data from file\n2 - Enter data on keyboard\nEnter a number for the operation:");
	scanf("%d", &option);
	list* lst;
	if (option == 1) {
		lst = read_list();
	}
	else if (option == 2) {
		lst = enter_list();
	}
	else {
		printf("No such operation!\n");
		lst = malloc(sizeof(list));
		lst->next = NULL;
	}
	float avrg = average_list(lst);
	return avrg;
}

int main() {
	int option;
	int result1;
	float result2;
	printf("1 - prog1\n2 - prog2\nEnter a number for the program:");
	scanf("%d", &option);
	if (option == 1) {
		result1 = sum();
		printf("Result of prog1: %i", result1);
	}
	else if (option == 2) {
		result2 = average();
		printf("Result of prog2: %f", result2);
	}
	else {
		printf("No such function!\n");
	}
}