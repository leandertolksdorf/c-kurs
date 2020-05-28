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

/*
Die Hilfsfunktion shortest funktioniert sowohl für SPN als auch SRT.
Bei SPN gilt für alle Ready-Prozesse: cycles_done = 0. Deshalb prüfen wir auch nur
cycles_todo. Bei SRT interessiert auch nur cycles_todo. Deshalb können wir shortest bei
SPN wiederverwenden.
*/
struct process *shortest(struct process *head) {
    int duration;
    int shortest = INFINITY;
    struct process *result = NULL;
    // Iteriere durch Prozesse p
    for (struct process *p = head -> next; p != head; p = p -> next) {
        // Wenn (p READY)
        if (p -> state == PS_READY) {
            // Berechne Dauer von p (= cycles_todo. Wir ignorieren cycles_done, weil es bei spn keine Fragmentierung gibt.)
            duration = p -> cycles_todo;
            // Wenn p kürzer als bisherige -> 
            if (duration < shortest) {
                shortest = duration;
                result = p;
            }
        }
    }
    if (!result) {
        result = head;
    }
    return result;
}

/* Shortest Process Next */

void spn(struct process *head) {
    bool idle = true;
    struct process *shortestProcess = NULL;

    for (struct process *p = head -> next; p != head; p = p -> next) {
        if (p -> state == PS_RUNNING) {
            if (p -> cycles_todo == 0) {
                p -> state = PS_DEAD;
            } else {
                idle = false;
            }
            break;
        }
    }

    if (idle) {
        shortestProcess = shortest(head);
        if (shortestProcess != head) {
            shortestProcess -> state = PS_RUNNING;
        }
    }
}

/* Shortest Remaining Time */

struct process *active(struct process *head) {
    struct process *result = NULL;
    for (struct process *p = head -> next; p != head; p = p -> next) {
        if (p -> state == PS_RUNNING) {
            result = p;
            break;
        }
    }
    return result;
}

void srt(struct process *head) {
    struct process *shortestRem = shortest(head);
    struct process *current = active(head);


    if (!current) {
        current = shortestRem;
        current -> state = PS_RUNNING;
        return;
    }
    if (shortestRem != head) {
        if (current -> cycles_todo == 0) {
            current -> state = PS_DEAD;
            shortestRem -> state = PS_RUNNING;
        } else if ((current -> cycles_todo) > (shortestRem -> cycles_todo)) {
            current -> state = PS_READY;
            shortestRem -> state = PS_RUNNING;
        }
    } else {
        if (current -> cycles_todo == 0) {
            current -> state = PS_DEAD;
        }
    }
}
/* Highest Response Ration Next */

float responseRatio(struct process *p) {
    float waited = (float) (p -> cycles_waited);
    float serviceTime = (float) (p -> cycles_todo);

    return (waited + serviceTime) / serviceTime;
}

struct process *highestRatio(struct process *head) {
    int highest = 0;
    int compare;
    struct process *result = NULL;

    for (struct process *p = head -> next; p != head; p = p -> next) {
        if (p -> state == PS_READY) {
            compare = responseRatio(p);
            if (compare > highest) {
                highest = compare;
                result = p;
            }
        }
    }
    if (!result) {
        result = head;
    }
    return result;
}

void hrrn(struct process *head){
    struct process *current = active(head);
    struct process *next = NULL;

    //printf("%d | ", current -> cycles_todo);

    if (!current) {
        current = highestRatio(head);
        current -> state = PS_RUNNING;
        return;
    }

    if (current -> cycles_todo == 0) {
        next = highestRatio(head);
        if (next != head) {
            current -> state = PS_DEAD;
            next -> state = PS_RUNNING;
            return;
        } else {
            current -> state = PS_DEAD;
        }
    }
}