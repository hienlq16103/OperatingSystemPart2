#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
	q->proc[q->size] = proc;
	q->size ++;	
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
	int max_prio = q->proc[0]->priority;
    int max_slot = 0;
    for (int i = 1; i < q->size; i++) {
        if (q->proc[i]->priority > max_prio) {
            max_prio = q->proc[i]->priority;
            max_slot = i;
        }
    }
    struct pcb_t *proc = q->proc[max_slot];
    for (int i = max_slot; i < q->size - 1; i++) {
        q->proc[i] = q->proc[i + 1];
    }
    q->size--;
    return proc;
	
	return NULL;
}

