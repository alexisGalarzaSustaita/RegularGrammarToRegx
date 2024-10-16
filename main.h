#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGHT 100

typedef struct Node
{
    char *line;
    struct Node *next;
}Node;

Node* createNode(const char *line);
void appendNode(Node **head, const char *line);
void freeLinkedList(Node *head);
Node* createLinkedList(FILE *file);
void printList(Node *head); 