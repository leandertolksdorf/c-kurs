#include <stdio.h>
#include <stdbool.h>
#include "memory.h"

// Memory-Array definition.
char memory[MEM_SIZE];

struct node *head = (struct node*) (&memory[0]);
struct node *dummy = (struct node*) (&memory[MEM_SIZE - sizeof(struct node)]);

// Helper functions

size_t blockSize(struct node *a, struct node *b) {
    printf("a %d, b %d, sizeof(node) %ld\n", a, b, sizeof(*head));
    // Calculate memory size between a and b (page 10)
    size_t result = (long long) b - (long long) a - sizeof(*head);
    printf("blockSize(): %zu\n", result);
    return result;
}

void memory_init() {
    head -> free = true;
    head -> size = blockSize(head, dummy);
    head -> next = dummy;
}

void *memory_allocate(size_t byte_count) {
    /* 
    First fit methode

    Iteriere durch nodes
        Wenn node -> free == True & node -> size >= (byte_count + sizeof(*head)):
            Wenn node -> size == (byte_count + sizeof(*head)):
                node -> free = false
            Sonst:
                finde passenden (freien) Node x
                    Passe diesen an:
                    x -> free = false
                    x -> size = byte_count + sizeof(*head)
                finde nächsten Node (nextNode()) (1)
                
                erstelle neuen node

                struct node *new = (struct *node) (Speicheradresse vom neuen node)
                new -> prev = Node x
                new -> next = Node aus (1)
                new -> size = blockSize(new, Node aus (1))
                new -> free = true

                Node aus (1) -> prev = new
    */
}

void memory_free(const void *const pointer) {
}

void memory_print() {
    // Vielleicht mit memory_by_index lösen?
    int block = 0;
    for (struct node *n = head; n != dummy; n = n -> next) {
        printf("Block %d | Free: %d | Size: %d\n", block, n -> free, n -> size);
        block++;
    }
}

void *memory_by_index(size_t index) {
    struct node *n = head;
    int i = 0;
    for (struct node *n; n != dummy; n = n -> next) {
        if (i == index) {
            return n;
        }
    }

    return NULL;
}