#include "main.h"

int main(){

    FILE *grammar = fopen("gramatica1.txt", "r");

    if(grammar == NULL){
        perror("Error openning the file");
        return EXIT_FAILURE;
    }

    Node *head = createLinkedList(grammar);

    fclose(grammar);

    //Output the contents of the linked list
    printList(head);

    //free the linked list
    freeLinkedList(head);

    return EXIT_SUCCESS;

}

//FUNCTIONS
Node *createNode(const char *line){

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->line = strdup(line);
    newNode->next = NULL;

    return (newNode);
}


void appendNode(Node **head, const char *line){
    Node *newNode = createNode(line);

    if(*head == NULL){
        *head == newNode; 
    }
    else{
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        }
    }


void freeLinkedList(Node *head){
    Node *current = head;
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next; 
    }
}


Node* createLinkedList(FILE *file){
    Node *head = NULL; //Head of the linked list
    char line[MAX_LINE_LENGHT];

    while(fgets(line, sizeof(line), file)){
        //remove the newline character if present
        line[strcspn(line, "\n")] = '\0';
        appendNode(&head, line);
    }

    return (head);
}


void printList(Node *head){
    Node *current = head;

    while (current != NULL) {
        printf("%s\n", current->line);
        current = current->next;
    }
}