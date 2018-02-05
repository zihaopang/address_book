#include <stdlib.h>
#include "voice.h"

void creat_link(Link *head)
{
    *head = (Link)malloc(sizeof(Infor));

    (*head)->prior = *head;
    (*head)->next = *head;
}
