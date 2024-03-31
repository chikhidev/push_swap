#include "../includes/push_swap.h"

void    move_to_top(t_app *app, t_stack *stack, t_list *node, int *moves_counter)
{
    int *array;

    array = stack_to_array(app, stack);
    if (index_of(array, *(int *)node->content, ft_lstsize(stack->head)) < ft_lstsize(stack->head) / 2)
    {
        while (stack->head != node)
        {
            rotate_a(stack);
            if (moves_counter)
                (*moves_counter)++;
        }
    }
    else
    {
        while (stack->head != node)
        {
            reverse_rotate_a(stack);
            if (moves_counter)
                (*moves_counter)++;
        }
    }
    free(array);
}

void    move_to_pos(t_app *app, t_stack *stack, int pos, int *moves_counter)
{
    int *array;

    array = stack_to_array(app, stack);
    if (pos < ft_lstsize(stack->head) / 2)
    {
        while (pos--)
        {
            rotate_a(stack);
            (*moves_counter)++;
        }
    }
    else
    {
        while (pos++ < ft_lstsize(stack->head))
        {
            reverse_rotate_a(stack);
            (*moves_counter)++;
        }
    }
    free(array);
}
