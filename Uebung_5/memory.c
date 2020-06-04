/*
TI3: 5. Übungsblatt / Aufgabe 2
Bearbeiter: Leander Tolksdorf, Simon Franke
Tutor: Leon Dirmeier
*/

#include <stdio.h>
#include <stdbool.h>
#include "memory.h"

// Define node-structure.
struct node {
    bool free;
    size_t size;
    struct node *next;
    struct node *prev;
};

// Define fake-memory array.
char memory[MEM_SIZE];

// Define head and dummy- structs at beginning and end of memory array.
struct node *head = (struct node*) (&memory[0]);
struct node *dummy = (struct node*) (&memory[MEM_SIZE - sizeof(struct node)]);

// Helper functions

// Return first free node of size >= minSize.
struct node *freeNode(size_t minSize) {
    for (struct node *n = head; n != dummy; n = n -> next) {
        if ((n -> free) && (n -> size >= minSize)) {
            return n;
        }
    }
    return NULL;
}

// Return address-difference ( - overhead) of two nodes a and b.
size_t distance(struct node *a, struct node *b) {
    size_t result = (long long) b - (long long) a  - sizeof(*head);
    return result;
}

void memory_init() {
    // Set first and only block to free.
    head -> free = true;
    // Set size to fill space to dummy.
    head -> size = distance(head, dummy);
    // Link head to dummy.
    head -> next = dummy;
    head -> prev = dummy;
    dummy -> next = head;
}

void *memory_allocate(size_t byte_count) {

    // Get a big enough free node (NULL if not enough space.)
    struct node *a = freeNode(byte_count);

    // When no big enough free node available -> Stop
    if (!a) {
        printf("Not enough space.\n");
        return NULL;
    } 
    
    // If perfect fit -> only set a to not free and stop.
    if (a -> size == byte_count) {
        a -> free = false;
        return a;
    
    // Else, run reallocation routine.
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

    /*
    Scenario: We want to free block B:
    |A     |B     |C     |D...
    */
    struct node* b = (struct node*) pointer;
    
    // If block already free -> do nothing.
    if (b -> free) {
        printf("Block already free.\n"); 
        return;
    }

    // Define nodes a,c,d for simplification.
    struct node *a = b -> prev;
    struct node *c = b -> next;
    struct node *d = b -> next -> next;

    /*
    Check surrounding nodes' states.
    We want to free block B.
    Case: |A      |B------|C      |D...
    After freeing: |A                 |D...
    */
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
    /*
    Unneccesarily complicated but pretty print function...
    Prints block index, free-flag, size and the total Size of memory as a checksum.
    */

    int block = 0; // Index counter
    int totalSize = sizeof(*head); // Initial total size
    printf("|--------------------------------|\n");
    
    // Iterate through nodes and print interesting data.
    for (struct node *n = head; n != dummy; n = n -> next) {
        printf("| Block %d | Free: %d | Size: %d  |\n", block, n -> free, (int) n -> size);

        // This is for decoration according to the free-flag of every block.
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
    // Iterate through nodes and return node when index reached.
    int i = 0;
    for (struct node *n = head; n != dummy; n = n -> next) {
        if (i == (int) index) {
            return n;
        }
        i++;
    }

    // If index non-existent -> return NULL.
    return NULL;
}