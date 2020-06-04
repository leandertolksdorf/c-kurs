#include <stdio.h>
#include <stdbool.h>
#include "memory.h"

// Memory-Array definition.
char memory[MEM_SIZE];

struct node *head = (struct node*) (&memory[0]);
struct node *dummy = (struct node*) (&memory[MEM_SIZE - sizeof(struct node)]);

// Helper functions

/*
Returns the first free node with size >= minSize.
*/
struct node *freeNode(size_t minSize) {
    for (struct node *n = head; n != dummy; n = n -> next) {
        if ((n -> free) && (n -> size >= minSize)) {
            return n;
        }
    }
    return NULL;
}

size_t distance(struct node *a, struct node *b) {
    size_t result = (long long) b - (long long) a  - sizeof(*head);
    return result;
}

void memory_init() {
    head -> free = true;
    head -> size = distance(head, dummy);
    head -> next = dummy;
    head -> prev = dummy;
    dummy -> next = head;
}

void *memory_allocate(size_t byte_count) {


    struct node *a = freeNode(byte_count);

    // When no big enough free node available -> Stop
    if (!a) {
        printf("No free node found.\n");
        return NULL;
    } 
    
    if (a -> size == byte_count) {
        a -> free = false;
        return a;
    } else if (a -> size >= byte_count + sizeof(*head)) {

        /*
        Scenario (--- means not free):
        |A                 |C-----|
        We want to allocate memory at node A and create a new free node B at the end of that memory.
        |A-----|B          |C-----|
        After that we have to re-link all nodes.
        */
        
        // Save c for relinking.
        struct node *c = a -> next;
        // Create new node b behind a.
        struct node *b = (struct node*) ((long long) a + byte_count + sizeof(*head));
        
        // Link  a -> next = b
        a -> next = b;
        // Link b -> prev = a
        a -> next -> prev = a;
        // Link b -> next = c
        a -> next -> next = c;
        // Set b to free.
        a -> next -> free = true;
        // Set a to not free.
        a -> free = false;
        // Set a size to byte_count
        a -> size = byte_count;
        // Set b size to fill space.
        a -> next -> size = distance((a -> next), c);
        return a;
    } else {
        return NULL;
    }
}

void memory_free(const void *const pointer) {

    // Define to-free pointer and pointers to surrounding nodes.
    // |A     |B     |C     |D...
    struct node* b = (struct node*) pointer;
    
    if (b -> free) {
        printf("Block already free.\n"); 
        return;
    }

    struct node *a = b -> prev;
    struct node *c = b -> next;
    struct node *d = b -> next -> next;

    // Check surrounding nodes' states.
    // We want to free block B.
    // Case: |A      |B------|C      |D...
    // After freeing: |A                 |D...
    if (b -> next -> free && b -> prev -> free) {
        // Link a -> d
        a -> next = d;
        // Link d -> a
        d -> prev = a;
        b -> prev -> free = true;
        b -> prev -> size = distance(a, d);
    /*
    Case: |A-----|B-----|C     |D...
    After freeing: |A-----|B          |D...
    */
    } else if (b -> next -> free) {
        // Link b -> d
        b -> next = d;
        // Link b <- d
        d -> prev = b;
        b -> free = true;
        b -> size = distance(b, d);
    /*
    Case: |A     |B-----|C-----|D...
    After freeing: |A          |C-----|D...
    */
    } else if (b -> prev -> free) {
        // Link a -> c
        a -> next = c;
        // Link c -> a
        c -> prev = a;
        b -> prev -> free = true;
        b -> prev -> size = distance(a, c);
    /*
    Case: |A-----|B-----|C-----|D...
    After freeing: |A-----|B     |C-----|D...
    */
    } else {
        b -> free = true;
    }
}

void memory_print() {
    int block = 0;
    int totalSize = sizeof(*head);
    printf("|--------------------------------|\n");
    for (struct node *n = head; n != dummy; n = n -> next) {
        printf("| Block %d | Free: %d | Size: %d  |\n", block, n -> free, (int) n -> size);
        for (int i = 0; i != (((int) n -> size / 100)); i++) {
            if (n -> free) {
                printf("|                                |\n");
            } else {
                printf("|xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx|\n");
            }
            
        }
        printf("|--------------------------------|\n");
        block++;
        totalSize += sizeof(*head) + (n -> size);
    }
    printf("Total size: %d\n", totalSize);
}

void *memory_by_index(size_t index) {
    // Gibt zum testen einfach head zurück.
    int i = 0;
    for (struct node *n = head; n != dummy; n = n -> next) {
        if (i == (int) index) {
            return n;
        }
        i++;
    }
    return NULL;
}