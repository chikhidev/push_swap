/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:22:19 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/20 20:53:10 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_app *app)
{
	t_list	*max_node;

	max_node = max(app->stack_a);
	if (max_node == app->stack_a->head)
		rotate_a(app->stack_a, 1);
	else if (max_node == app->stack_a->head->next)
		reverse_rotate_a(app->stack_a, 1);
	if (*(int *)app->stack_a->head->content
		> *(int *)app->stack_a->head->next->content)
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
		move_to_top(app, app->stack_a, min, NULL);
		push_b(app->stack_a, app->stack_b, 1);
	}
	sort_three(app);
	while (app->stack_b->head)
		push_a(app->stack_a, app->stack_b, 1);
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

void	sort_stack(t_app *app)
{
	if (ft_lstsize(app->stack_a->head) == 2)
	{
		if (*(int *)app->stack_a->head->content
			> *(int *)app->stack_a->head->next->content)
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
