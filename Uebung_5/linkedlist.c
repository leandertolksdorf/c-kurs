#include <stdio.h>
#include <stdlib.h>

// Struct definition

struct node {
    struct node *next;
    struct node *prev;

    int value;
};

struct node dummy = {
    .next = &dummy,
    .prev = &dummy,
};

struct node *head = &dummy;

//

// Function declaration
// Helpers
void printList(struct node *head);

// List getters
struct node *lastElement(struct node *head);

// List operations
void enqueue(struct node *head, int value);

// Main function
int main(int argc, char const *argv[])
{
    enqueue(head, 123);
    enqueue(head, 456);
    printList(head);
    return 0;
}


void enqueue(struct node *head, int value) {
    struct node *new = malloc(sizeof (*new));
    new -> value = value;

    new -> next = head;
    new -> prev = head -> prev;

    new -> prev -> next = new;
    new -> next -> prev = new;
}

void printList(struct node *head) {
    int element = 0;
    for (struct node *n = head -> next; n != head; n = n -> next) {
        printf("Element %d | Value %d\n", element, n -> value);
        element++;
    }
}