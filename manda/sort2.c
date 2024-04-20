#include "../includes/push_swap.h"

t_list	*cheapest(t_app *app, int *moves)
{
	int		i;
	t_list	*to_find;
	int		min_moves;

	i = 0;
	to_find = app->stack_a->head;
	min_moves = INT_MAX;
	while (i < ft_lstsize(app->stack_a->head))
	{
		if (moves[i] < min_moves)
		{
			min_moves = moves[i];
			to_find = node_at_idx(app->stack_a, i);
		}
		i++;
	}
	return (to_find);
}

t_list	*best(t_app *app, t_target *target, t_list *tmp)
{
	int	idx;
	int	moves[ft_lstsize(app->stack_a->head)];

	tmp = app->stack_a->head;
	idx = 0;
	while (tmp)
	{
		target->target = smaller_and_close(app->stack_b,
											*(int *)tmp->content);
		target->moves = shortest_way(app, tmp, target->target);
		moves[idx] = target->moves;
		tmp = tmp->next;
		idx++;
	}
	return (cheapest(app, moves));
}

void	get_route(t_app *app, t_target *target, t_list *min_mvs_node,
		int len[2])
{
	if (index_of(app->stack_b, target->target) >= (len[1] / 2) &&
		index_of(app->stack_a, min_mvs_node) >= (len[0] / 2))
	{
		while (app->stack_a->head != min_mvs_node
			&& app->stack_b->head != target->target)
		{
			reverse_rotate_ab(app->stack_a, app->stack_b, 1);
		}
	}
	else if (index_of(app->stack_b, target->target) < len[1] / 2 &&
				index_of(app->stack_a, min_mvs_node) < len[0] / 2)
	{
		while (app->stack_a->head != min_mvs_node
			&& app->stack_b->head != target->target)
		{
			rotate_ab(app->stack_a, app->stack_b, 1);
		}
	}
	else if (index_of(app->stack_b, target->target) == 1 &&
				index_of(app->stack_a, min_mvs_node) == 1)
	{
		swap_ab(app->stack_a, app->stack_b, 1);
	}
	move_to_top(app, app->stack_a, min_mvs_node, NULL);
	move_to_top(app, app->stack_b, target->target, NULL);
}

void	turk(t_app *app, t_target *target)
{
	t_list	*min_mvs_node;
	int		len[2];
	t_list	*tmp;

	tmp = NULL;
	while (ft_lstsize(app->stack_a->head) > 3)
	{
		min_mvs_node = best(app, target, tmp);
		target->target = smaller_and_close(app->stack_b,
											*(int *)min_mvs_node->content);
		len[0] = ft_lstsize(app->stack_a->head);
		len[1] = ft_lstsize(app->stack_b->head);
		get_route(app, target, min_mvs_node, len);
		move_to_top(app, app->stack_a, min_mvs_node, NULL);
		move_to_top(app, app->stack_b, target->target, NULL);
		push_b(app->stack_a, app->stack_b, 1);
	}
}

void	sort_logic(t_app *app)
{
	t_target	target;

	push_b(app->stack_a, app->stack_b, 1);
	push_b(app->stack_a, app->stack_b, 1);
	turk(app, &target);
	sort_three(app);
	while (app->stack_b->head)
	{
		target.target = bigger_and_close(app->stack_a,
											*(int *)app->stack_b->head->content);
		move_to_top(app, app->stack_a, target.target, NULL);
		push_a(app->stack_a, app->stack_b, 1);
	}
	if (index_of(app->stack_a,
					min(app->stack_a)) > ft_lstsize(app->stack_a->head) / 2)
	{
		while (app->stack_a->head != min(app->stack_a))
			reverse_rotate_a(app->stack_a, 1);
	}
	else
	{
		while (app->stack_a->head != min(app->stack_a))
			rotate_a(app->stack_a, 1);
	}
}
