#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFLEN 2048


void swap(int a, int b);
void Quicksort(int p, int r);
int partition(int start, int end);

typedef struct {
	char** value;
}item;

int n;
int basis = -1;
item* items;

 void main(void) {
	FILE* input = fopen("hw1_input.txt", "r");
	int i,j;
	int attnum = 0;
	
	
	if (input != NULL) {
		int n;
		char buffer[BUFLEN];
 		while (1) {
			fgets(buffer, BUFLEN - 1, input);
			if (strchr(buffer, '$') != NULL)
				break;
			n = atoi(buffer);
		}//input number of objects

		while (1) {
			fgets(buffer, BUFLEN - 1, input);
			if (strchr(buffer, '$') !=NULL)
				break;
			char* ptr=strtok(buffer,":");
			while (ptr!=NULL)
			{
				if ((basis == -1) && (strchr(ptr, '*') != NULL))
					basis = attnum;
				attnum++;
				ptr = strtok(NULL, ":");
			}
		}//get number of attributes

		items = malloc(sizeof(item) * n);
		for (i = 0;i < n;i++) {
			items[i].value = malloc(sizeof(char*) * attnum);
			fgets(buffer, BUFLEN - 1, input);			
			char* ptr= strtok(buffer, ":\n");
			for(j=0;j<attnum;j++)
			{
				char* valbuf = malloc(sizeof(char) * (strlen(ptr) + 1));
				strcpy(valbuf,ptr);
				items[i].value[j] = valbuf;
 				ptr = strtok(NULL, ":\n");
			}
		}//input value of objects

		Quicksort(0, n-1);//excute sort

		FILE* output = fopen("hw1_output.txt", "w");

		for (i = 0;i < n;i++) {
			for (j = 0;j < attnum-1;j++) {
				fprintf(output,"%s:", items[i].value[j]);
 			}
 			fprintf(output,"%s", items[i].value[attnum-1]);
			fprintf(output, "\n");
		}

		for (i = 0;i < n;i++) {
			for (j = 0;j < attnum;j++) {
				free(items[i].value[j]);
			}
			free(items[i].value);
		}
		free(items);
		fclose(output);
		fclose(input);
	}
	else {
		printf("Wrong Input files");
	}
 }

 void Quicksort(int p, int r) {
	 if (p < r) {
		int pivot = partition(p, r);
		Quicksort(p, pivot-1);
		Quicksort(pivot + 1, r);
	 }
 }

 int partition(int start,int end) {
	 int pivot;
	 int middle = (start + end) / 2;
	 if (strcmp(items[start].value[basis], items[end].value[basis]) > 0) {
		 if (strcmp(items[middle].value[basis], items[start].value[basis]) > 0) {
			 pivot = start;
		 }
		 else if (strcmp(items[middle].value[basis], items[end].value[basis]) > 0) {
			 pivot = middle;
		 }
		 else
			 pivot = end;
	 }
	 else {
		 if (strcmp(items[middle].value[basis], items[end].value[basis]) > 0) {
			 pivot = end;
		 }
		 else if (strcmp(items[middle].value[basis], items[start].value[basis])>0) {
			 pivot = middle;
		 }
		 else
			 pivot = start;
	 }//choose pivot
	 
	 int small = end;
	 int big=start;
	 while (1) {
		 while ((big < end)&&(strcmp(items[big].value[basis], items[pivot].value[basis]) <= 0)) {
			 big++;
		 }
		 while ((small>start)&&(strcmp(items[small].value[basis], items[pivot].value[basis]) >= 0)) {
			 small--;
		 }
		 if (big >= small) {
			 if (pivot > big) {
				 swap(pivot, big);
				 return big;
			 }
			 else if (pivot < small) {
				 swap(pivot, small);
				 return small;
			 }
			 return pivot;
		 }
		 swap(big, small);
	 }//swap
 }

 void swap(int a, int b) {
	 item temp;
	 temp = items[a];
	 items[a] = items[b];
	 items[b] = temp;
 }
