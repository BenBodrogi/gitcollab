#include "DS.h"
#include <stdlib.h>

void cb_push(CBTree *p, int x)
{
        p->cb_arr[p->cb_len] = x;
        p->cb_len++;
}

void cb_preorder(const CBTree *p, int idx)
{
        Stack *st = malloc(sizeof(Stack));
        st->top = NULL;
        st->len = 0;
        s_push(st, idx); // ehnii utgiig push hiiv
        while (st->len > 0)
        {
                int index = st->top->x; // stackiin suulin utgiig hadgalj avna
                s_pop(st);
                if (index < p->cb_len)
                {
                        printf("%d\n", p->cb_arr[index]);
                        s_push(st, 2 * index + 2); // baruun huugd stackd hiin
                        s_push(st, 2 * index + 1); // zuun huug stackd hiine
                }
        }
}

void cb_inorder(const CBTree *p, int idx)
{
        Stack *st = malloc(sizeof(Stack));
        st->top = NULL;
        st->len = 0;
        while (1)
        {
                if (idx < p->cb_len)
                {
                        // ehleed idx zangilaani buh zuun huug tackda hagdalna
                        s_push(st, idx);
                        idx = 2 * idx + 1;
                }
                else
                {
                        if (st->len > 0)
                        {
                                idx = st->top->x;
                                s_pop(st);
                                // zuun huug n hevlecgheed baruun huu ruuge shiljin hevlene
                                printf("%d\n", p->cb_arr[idx]);
                                idx = 2 * idx + 2;
                        }
                        else
                        {
                                break;
                        }
                }
        }
}

void cb_postorder(const CBTree *p, int idx)
{
        Stack *st1 = malloc(sizeof(Stack));
        st1->top = NULL;
        st1->len = 0;
        Stack *st2 = malloc(sizeof(Stack));
        st2->top = NULL;
        st2->len = 0;
        s_push(st1, idx); // st1 d ehnii zalngailaani utgig avna
        int index;        //  suulin element hadgalah huvisagch
        while (st1->len > 0)
        {
                // Ehnii stackaas ehnii utga avan pop hiij daraagiin stackad push hiine
                index = st1->top->x;
                s_pop(st1);
                s_push(st2, index);
                if (2 * index + 1 < p->cb_len)
                        s_push(st1, 2 * index + 1); // st2 d hiin
                if (2 * index + 2 < p->cb_len)
                        s_push(st1, 2 * index + 2); // st 2d hiine
        }
        // Hoyor dahi stackiin buh zangilaag hevlene
        while (st2->len > 0)
        {
                // stackiig suules n hevlene
                index = st2->top->x;
                s_pop(st2);
                printf("%d\n", p->cb_arr[index]);
        }
}