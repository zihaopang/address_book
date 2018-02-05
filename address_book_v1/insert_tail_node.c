#include <stdio.h>

#include "voice.h"

void insert_tail_node(Link *head,Link *newnode)
{
    (*head)->prior->next = *newnode;
    (*newnode)->prior = (*head)->prior;

    (*head)->prior = *newnode;
    (*newnode)->next = *head;
}

