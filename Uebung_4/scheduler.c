#include "scheduler.h"
#include <stdbool.h>
#include <math.h>
#include <stddef.h>
//#include <stdio.h>

/* Round Robin */

struct process *nextReady(struct process *head, struct process *p) {
    for (struct process *c = p -> next; c != head; c = c -> next) {
        if (c -> state == PS_READY) {
            return c;
        }
    }
    for (struct process *c = head -> next; c != p; c = c -> next) {
        if (c -> state = PS_READY) {
            return c;
        }
    }
}

int processes(struct process *head) {
    int result = 0;
    for (struct process *c = head -> next; c != head; c = c -> next) {
        if (c -> state == PS_READY) {
            result++;
        }
    }
    return result;
}

void rr(struct process *head) {
    return;
}
/* First Come First Serve */
void fcfs(struct process *head) {
    head -> next -> state = PS_RUNNING;

    for (struct process *c = head -> next; c != head; c = c -> next) {
        if (c -> cycles_todo == 0) {
            c -> state = PS_DEAD;
            if (c -> next != head) {
                c -> next -> state = PS_RUNNING;
            }
        }
    }
}

struct process *shortestProcess(struct process *head) {
    struct process *c = head -> next;
    struct process *result
    int resultDuration = 0;

    while (c != head) {
        if (c -> state == PS_READY) {
            if (resultDuration == 0) {

                result = c;
                resultDuration = c -> cycles_todo;
                printf("rD = 0 | %d\n", resultDuration);
                return result;
            } else {
                printf("rd != 0\n");
                if (c -> cycles_todo < resultDuration) {
                    printf("Neuer kürzester Pr.\n");
                    result = c;
                    resultDuration = c -> cycles_todo;
                }
            }
        }
        c = c -> next;
    }

    if (!result) {
        printf("Irgendwas\n");
        
        printf("%d\n", result -> cycles_todo);
    }

    return result;
}

/* Shortest Process Next */
void spn(struct process *head) {
    shortestProcess(head) -> state = PS_RUNNING;

    for (struct process *c = head -> next; c != head; c = c -> next) {
        printf("Shortest Process: %d | ", shortestProcess(head) -> pid);
        if (c -> state == PS_RUNNING) {
            if (c -> cycles_todo == 0) {
                c -> state = PS_DEAD;
                shortestProcess(head) -> state = PS_RUNNING;
            }
            break;
        }
    }
}
/* Shortest Remaining Time */
void srt(struct process *head){
    printf("srt");
}
/* Highest Response Ration Next */
void hrrn(struct process *head){
    printf("hrrn");
}