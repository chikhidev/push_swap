/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:22:16 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/20 19:22:17 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calculate_moves_top(int node_idx, int target_idx)
{
	if (node_idx > target_idx)
		return (node_idx);
	else
		return (target_idx);
}

int	calculate_moves_bottom(int node_idx, int target_idx, int len[2])
{
	if ((len[1] - target_idx) > (len[0] - node_idx))
		return (len[1] - target_idx);
	else
		return (len[0] - node_idx);
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
	if (in_top(app->stack_a, node) && in_top(app->stack_b, target))
		mvs = calculate_moves_top(node_idx, target_idx);
	else if (!in_top(app->stack_a, node) && !in_top(app->stack_b, target))
		mvs = calculate_moves_bottom(node_idx, target_idx, len);
	else
	{
		if (in_top(app->stack_a, node) && !in_top(app->stack_b, target))
			return (node_idx + len[1] - target_idx);
		else
			return (target_idx + len[0] - node_idx);
	}
	return (mvs);
}
