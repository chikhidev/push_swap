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

void    sort_three(t_app *app)
{
    int top;
    int mid;
    int bot;

    while (!is_sorted(app->stack_a))
    {
        top = *(int *)app->stack_a->head->content;
        mid = *(int *)app->stack_a->head->next->content;
        bot = *(int *)app->stack_a->head->next->next->content;

        if (top > mid && top > bot)
            rotate_a(app->stack_a);
        else if (top > mid && top < bot)
        {
            swap_a(app->stack_a);
            rotate_a(app->stack_a);
        }
        else if (top < mid && top > bot)
            reverse_rotate_a(app->stack_a);
        else if (top < mid && top < bot)
            swap_a(app->stack_a);
    }
}

void	sort_five(t_app *app)
{
	t_list *tmp;
	t_list	*min;
	
	while (ft_lstsize(app->stack_a->head) > 3)
	{
		tmp = app->stack_a->head;
		min = tmp;
	       	while (tmp)
				{
			if (*(int *)tmp->content < *(int *)min->content)
				min = tmp;
			tmp = tmp->next;
		}
		/*here found the min*/
		move_to_top(app, app->stack_a, min, NULL);
		push_b(app->stack_a, app->stack_b);
	}
    sort_three(app);
    while (app->stack_b->head)
        push_a(app->stack_a, app->stack_b);
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
        sort_three(app);
    else if (ft_lstsize(app->stack_a->head) > 3 && ft_lstsize(app->stack_a->head) <= 5)
        sort_five(app);
    else
        sort_logic(app);
}
