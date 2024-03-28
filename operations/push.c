#include "../includes/push_swap.h"

/**
 * @details push the first element of stack_b to stack_a
*/
void    push_a(t_stack *stack_a, t_stack *stack_b)
{
    t_list  *tmp;

    if (stack_b->head == NULL)
        return ;
    tmp = stack_b->head;
    stack_b->head = stack_b->head->next;
    if (stack_a->head == NULL)
    {
        tmp->next = NULL;
        stack_a->head = tmp;
    }
    else
    {
        tmp->next = stack_a->head;
        stack_a->head = tmp;
    }
    write(1, "pa\n", 3);
}

void    push_b(t_stack *stack_a, t_stack *stack_b)
{
    t_list  *tmp;

    if (stack_a->head == NULL)
        return ;
    tmp = stack_a->head;
    stack_a->head = stack_a->head->next;
    if (stack_b->head == NULL)
    {
        tmp->next = NULL;
        stack_b->head = tmp;
    }
    else
    {
        tmp->next = stack_b->head;
        stack_b->head = tmp;
    }
    write(1, "pb\n", 3);
}
