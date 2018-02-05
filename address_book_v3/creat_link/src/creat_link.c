#include <stdlib.h>
#include "/home/address_book/include/src/all.h"

void creat_link(Link *head)
{
    *head = (Link)malloc(sizeof(Infor));

    (*head)->prior = *head;
    (*head)->next = *head;
}
