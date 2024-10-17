#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGHT 100

typedef struct Node
{
    char *ruleIdentifier;
    char *production
    struct Node *next;
}Node;

Node *createNode(const char *ruleIdentifier, const char *production);
void appendNode(Node **head, const char *ruleIdentifier, const char *production);
void freeLinkedList(Node *head);
Node* createLinkedList(FILE *file);
void printList(Node *head); 