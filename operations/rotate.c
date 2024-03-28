#include "../includes/push_swap.h"

/**
 * rotate the stack a
 * @param stack_a stack a
 * @details shift up all elements of stack a by 1
*/
void    rotate_a(t_stack *stack_a)
{
    t_list  *last;
    t_list  *tmp;

    if (ft_lstsize(stack_a->head) < 2)
        return ;
    tmp = stack_a->head->next;
    last = ft_lstlast(stack_a->head);
    stack_a->head->next = NULL;
    last->next = stack_a->head;
    stack_a->head = tmp;
    write(1, "ra\n", 3);
}

/**
 * rotate the stack a
 * @param stack_b stack a
 * @details shift up all elements of stack a by 1
*/
void    rotate_b(t_stack *stack_b)
{
    t_list  *last;
    t_list  *tmp;

    if (ft_lstsize(stack_b->head) < 2)
        return ;
    tmp = stack_b->head->next;
    last = ft_lstlast(stack_b->head);
    stack_b->head->next = NULL;
    last->next = stack_b->head;
    stack_b->head = tmp;
    write(1, "rb\n", 3);
}


/**
 * rotate the stack a and b
 * @param stack_a stack a
 * @param stack_b stack b
 * @note rotate_ab = rotate_a + rotate_b
 * @details shift up all elements of stack a and stack b by 1
*/
void    rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
    write(1, "rr\n", 3);
}
