#include "DS.h"

void s_push(Stack *p, int x)
{
        Elm *ptr;
        ptr = (Elm *)malloc(sizeof(Elm));
        ptr->x = x;
        ptr->next = p->top;
        p->top = ptr;
        p->len++;
}

void s_pop(Stack *p)
{
        p->top = p->top->next;
        p->len--;
}

void s_print(Stack *p)
{
        Elm *temp = p->top;
        while (temp != NULL)
        {
                printf("%d\n", temp->x);
                temp = temp->next;
        }
}