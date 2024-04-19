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

t_list  *max(t_stack *stack)
{
    t_list *max;

    max = stack->head;
    for (t_list *current = stack->head; current; current = current->next)
    {
        if (*(int *)current->content > *(int *)max->content)
            max = current;
    }
    return (max);
}

void    sort_three(t_app *app)
{
    t_list *max_node;

    max_node = max(app->stack_a);
    
    if (max_node == app->stack_a->head)
        rotate_a(app->stack_a, 1);
    else if (max_node == app->stack_a->head->next)
        reverse_rotate_a(app->stack_a, 1);

    if (*(int *)app->stack_a->head->content > *(int *)app->stack_a->head->next->content)
        swap_a(app->stack_a, 1);
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
		push_b(app->stack_a, app->stack_b, 1);
	}
    sort_three(app);
    while (app->stack_b->head)
        push_a(app->stack_a, app->stack_b, 1);
}

t_list *smaller_and_close(t_stack *stack ,int num)
{
    t_list *close_one;
    t_list *curr;
    int closest_value;
    int curr_value;

    close_one = stack->head;
    closest_value = INT_MIN;
    curr = stack->head;
    while (curr)
    {
        curr_value = *(int *)curr->content;
        if (curr_value < num && curr_value > closest_value)
        {
            close_one = curr;
            closest_value = curr_value;
        }
        curr = curr->next;
    }
    return close_one;
}

int shortest_way(t_stack *stack, t_list *node)
{
    int index;
    int size;

    size = ft_lstsize(stack->head);
    index = index_of(stack, node);
    if (index > size / 2)
        return (size - index);
    return (index);
}

t_list  *node_at_idx(t_stack *stack, int idx)
{
    t_list *node;
    int i;

    i = 0;
    node = stack->head;
    while (i < idx)
    {
        node = node->next;
        i++;
    }
    return (node);
}

void    sort_logic(t_app *app)
{
    t_target target;
    t_list *tmp;
    int     moves[ft_lstsize(app->stack_a->head)];
    int     idx;
    t_list  *min_mvs_node;
    int     min_moves;

    push_b(app->stack_a, app->stack_b, 1);
    push_b(app->stack_a, app->stack_b, 1);

    while (app->stack_a->head)
    {
        tmp = app->stack_a->head;
        idx = 0;
        while (tmp)
        {
            target.target = smaller_and_close(app->stack_b, *(int *)tmp->content);
            target.moves =  shortest_way(app->stack_b, target.target) +
                            shortest_way(app->stack_a, tmp) + 1;
            moves[idx] = target.moves;
            tmp = tmp->next;
            idx++;
        }

        idx = 0;
        min_mvs_node = app->stack_a->head;
        min_moves = INT_MAX;
        while (idx < ft_lstsize(app->stack_a->head))
        {
            if (moves[idx] < min_moves)
            {
                min_moves = moves[idx];
                min_mvs_node = node_at_idx(app->stack_a, idx);
            }
            idx++;
        }


        target.target = smaller_and_close(app->stack_b, *(int *)min_mvs_node->content);
        move_to_top(app, app->stack_b, target.target, NULL);
        move_to_top(app, app->stack_a, min_mvs_node, NULL);
        push_b(app->stack_a, app->stack_b, 1);
    }

    while (app->stack_b->head)
    {
        t_list *max_node;

        max_node = max(app->stack_b);
        move_to_top(app, app->stack_b, max_node, NULL);
        push_a(app->stack_a, app->stack_b, 1);
    }
}

void    sort_stack(t_app *app)
{
    if (ft_lstsize(app->stack_a->head) == 2)
    {
        if (*(int *)app->stack_a->head->content > *(int *)app->stack_a->head->next->content)
            swap_a(app->stack_a, 1);
        return ;
    }
    else if (ft_lstsize(app->stack_a->head) == 3)
        sort_three(app);
    else if (ft_lstsize(app->stack_a->head) > 3 && ft_lstsize(app->stack_a->head) <= 5)
        sort_five(app);
    else
        sort_logic(app);
}
