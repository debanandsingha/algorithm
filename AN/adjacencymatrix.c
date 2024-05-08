#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	struct node* next;
}

struct node* createNode(int);

struct node* createNode(int v){
	struct node new = malloc(sizeof(struct node));
	new.vertex = v;
	new.next = NULL;
	return 
}
