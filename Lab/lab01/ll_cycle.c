#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    node *tortoise, *hare;
    tortoise = head;
    hare = head;
    while(1){ // 此处根本无需判断终止条件，因为循环内部一定会有return
        if(!hare||!hare->next) return 0;
        tortoise = tortoise->next;
        hare = hare->next->next;
        if(hare == tortoise) return 1;
    }
}