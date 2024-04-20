#include "../includes/push_swap.h"

t_list	*min(t_stack *stack)
{
	t_list	*min;

	min = stack->head;
	for (t_list *current = stack->head; current; current = current->next)
	{
		if (*(int *)current->content < *(int *)min->content)
			min = current;
	}
	return (min);
}

t_list	*max(t_stack *stack)
{
	t_list	*max;

	max = stack->head;
	for (t_list *current = stack->head; current; current = current->next)
	{
		if (*(int *)current->content > *(int *)max->content)
			max = current;
	}
	return (max);
}

void	sort_three(t_app *app)
{
	t_list	*max_node;

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
	t_list	*tmp;
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

t_list	*smaller_and_close(t_stack *stack, int num)
{
	t_list	*close_one;
	t_list	*curr;
	int		closest_value;
	int		curr_value;

	close_one = NULL;
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
	if ((!close_one) && (stack->head))
		close_one = max(stack);
	return (close_one);
}

t_list	*bigger_and_close(t_stack *stack, int num)
{
	t_list	*close_one;
	t_list	*curr;
	int		closest_value;
	int		curr_value;

	close_one = NULL;
	closest_value = INT_MAX;
	curr = stack->head;
	while (curr)
	{
		curr_value = *(int *)curr->content;
		if (curr_value > num && curr_value < closest_value)
		{
			close_one = curr;
			closest_value = curr_value;
		}
		curr = curr->next;
	}
	if ((!close_one) && (stack->head))
		close_one = min(stack);
	return (close_one);
}

int	is_in_top_mid(t_stack *stack, t_list *node)
{
	int	len;
	int	idx;

	len = ft_lstsize(stack->head);
	idx = index_of(stack, node);
	if (idx < len / 2)
		return (1);
	return (0);
}

int	shortest_way(t_app *app, t_list *node, t_list *target)
{
	int	mvs;
	int	len[2];
	int	node_idx;
	int	target_idx;

	len[0] = ft_lstsize(app->stack_a->head);
	len[1] = ft_lstsize(app->stack_b->head);
	node_idx = index_of(app->stack_a, node);
	target_idx = index_of(app->stack_b, target);
	if (node_idx == 0 && target_idx == 0)
		return (0);
	if (is_in_top_mid(app->stack_a, node) &&
		is_in_top_mid(app->stack_b, target))
	{
		//logic of the shortest way to have the target and the node in top of both stacks
		mvs = node_idx > target_idx ? node_idx : target_idx;
	}
	else if (!is_in_top_mid(app->stack_a, node) &&
				!is_in_top_mid(app->stack_b, target))
	{
		//logic of the shortest way to have the target and the node in top both stacks but this time they are in the bottom mid range of both of the stacks
		mvs = (len[1] - target_idx) > (len[0] - node_idx) ? (len[1]
				- target_idx) : (len[0] - node_idx);
	}
	else
	{
		//logic
		if (is_in_top_mid(app->stack_a, node) && !is_in_top_mid(app->stack_b,
				target))
			mvs = node_idx + len[1] - target_idx;
		else
			mvs = target_idx + len[0] - node_idx;
	}
	return (mvs);
}

t_list	*node_at_idx(t_stack *stack, int idx)
{
	t_list	*node;
	int		i;

	i = 0;
	node = stack->head;
	while (i < idx)
	{
		node = node->next;
		i++;
	}
	return (node);
}

void	print_stacks(t_app *app)
{
	t_list	*a;
	t_list	*b;

	a = app->stack_a->head;
	b = app->stack_b->head;
	printf(MAGENTA "stack a:\tstack b:\n");
	while (a || b)
	{
		if (a)
		{
			printf("%d\t\t", *(int *)a->content);
			a = a->next;
		}
		else
			printf("\t\t");
		if (b)
		{
			printf("%d\n", *(int *)b->content);
			b = b->next;
		}
		else
			printf("\n");
	}
	write(1, RESET, ft_strlen(RESET));
}

void	sort_logic(t_app *app)
{
	t_target	target;
	t_list		*tmp;
	int			moves[ft_lstsize(app->stack_a->head)];
	int			idx;
	t_list		*min_mvs_node;
	int			min_moves;
	int			len[2];

	push_b(app->stack_a, app->stack_b, 1);
	push_b(app->stack_a, app->stack_b, 1);
	// print_stacks(app);//---------------------------------------------
	while (ft_lstsize(app->stack_a->head) > 3)
	{
		tmp = app->stack_a->head;
		idx = 0;
		while (tmp)
		{
			target.target = smaller_and_close(app->stack_b,
												*(int *)tmp->content);
			target.moves = shortest_way(app, tmp, target.target);
			// printf("to go to %d from %d it takes %d moves\n",
					*(int *)target.target->content, *(int *)tmp->content,
					target.moves);
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
		// printf("so best move is to go to %d from %d takes %d\n",
				*(int *)target.target->content, *(int *)min_mvs_node->content,
				min_moves);
				target.target = smaller_and_close(app->stack_b,
													*(int *)min_mvs_node->content);
				len[0] = ft_lstsize(app->stack_a->head);
				len[1] = ft_lstsize(app->stack_b->head);
				if (index_of(app->stack_b, target.target) >= (len[1] / 2) &&
					index_of(app->stack_a, min_mvs_node) >= (len[0] / 2))
				{
					while (app->stack_a->head != min_mvs_node
						&& app->stack_b->head != target.target)
					{
						reverse_rotate_ab(app->stack_a, app->stack_b, 1);
					}
					while (app->stack_a->head != min_mvs_node)
					{
						reverse_rotate_a(app->stack_a, 1);
					}
					while (app->stack_b->head != target.target)
					{
						reverse_rotate_b(app->stack_b, 1);
					}
				}
				else if (index_of(app->stack_b, target.target) < len[1] / 2 &&
							index_of(app->stack_a, min_mvs_node) < len[0] / 2)
				{
					while (app->stack_a->head != min_mvs_node
						&& app->stack_b->head != target.target)
					{
						rotate_ab(app->stack_a, app->stack_b, 1);
					}
					while (app->stack_a->head != min_mvs_node)
					{
						rotate_a(app->stack_a, 1);
					}
					while (app->stack_b->head != target.target)
					{
						rotate_b(app->stack_b, 1);
					}
				}
				else if (index_of(app->stack_b, target.target) == 1 &&
							index_of(app->stack_a, min_mvs_node) == 1)
				{
					swap_ab(app->stack_a, app->stack_b, 1);
				}
				move_to_top(app, app->stack_a, min_mvs_node, NULL);
				move_to_top(app, app->stack_b, target.target, NULL);
				push_b(app->stack_a, app->stack_b, 1);
				// print_stacks(app);//---------------------------------------------
	}
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

void	sort_stack(t_app *app)
{
	if (ft_lstsize(app->stack_a->head) == 2)
	{
		if (*(int *)app->stack_a->head->content > *(int *)app->stack_a->head->next->content)
			swap_a(app->stack_a, 1);
		return ;
	}
	else if (ft_lstsize(app->stack_a->head) == 3)
		sort_three(app);
	else if (ft_lstsize(app->stack_a->head) > 3
			&& ft_lstsize(app->stack_a->head) <= 5)
		sort_five(app);
	else
		sort_logic(app);
}
