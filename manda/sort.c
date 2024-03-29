#include "../includes/push_swap.h"

t_list  *min(t_stack *stack)
{
    t_list *min;

    min = stack->head;
    for (t_list *current = stack->head; current; current = current->next)
    {
        if (*(int *)current->content < *(int *)min->content)
            min = current;
    }
    return (min);
}

void    move_min_to_top(t_stack *stack, int *moves)
{
    t_list  *min_num;
    int     min_index;
    t_list  *tmp;

    min_num = min(stack);
    min_index = 0;
    tmp = stack->head;
    while (tmp != min_num)
    {
        tmp = tmp->next;
        min_index++;
    }
    if (min_index == 0)
        return ;
    else if (min_index == 1)
    {
        swap_a(stack);
        *moves += 1;
    }
    else if (min_index == ft_lstsize(stack->head) - 1)
    {
        reverse_rotate_a(stack);
        *moves += 1;
    }
    else if (min_index < ft_lstsize(stack->head) / 2)
    {
        while (stack->head != min_num)
        {
            rotate_a(stack);
            *moves += 1;
        }
    }
    else
    {
        while (stack->head != min_num)
        {
            reverse_rotate_a(stack);
            *moves += 1;
        }
    }
}

void    sort_logic(t_app *app)
{
    int moves;

    moves = 0;
    while (app->stack_a->head)
    {
        move_min_to_top(app->stack_a, &moves);
        push_b(app->stack_a, app->stack_b);
        moves += 1;
    }
    while (app->stack_b->head)
    {
        push_a(app->stack_a, app->stack_b);
        moves += 1;
    }
    printf("moves: %d\n", moves);
    return ;
}

void    sort_stack(t_app *app)
{

    if (ft_lstsize(app->stack_a->head) == 2)
    {
        if (*(int *)app->stack_a->head->content > *(int *)app->stack_a->head->next->content)
            swap_a(app->stack_a);
        return ;
    }
    else if (ft_lstsize(app->stack_a->head) == 3)
    {
        if (*(int *)app->stack_a->head->content > *(int *)app->stack_a->head->next->content &&
            *(int *)app->stack_a->head->content > *(int *)app->stack_a->head->next->next->content)
            rotate_a(app->stack_a);
        if (*(int *)app->stack_a->head->content > *(int *)app->stack_a->head->next->content)
            swap_a(app->stack_a);
    }
    else
        sort_logic(app);
}
