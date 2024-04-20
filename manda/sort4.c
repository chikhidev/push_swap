/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:23:38 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/20 18:27:21 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		mvs = node_idx > target_idx ? node_idx : target_idx;
	}
	else if (!is_in_top_mid(app->stack_a, node) &&
				!is_in_top_mid(app->stack_b, target))
	{
		mvs = (len[1] - target_idx) > (len[0] - node_idx) ? (len[1]
				- target_idx) : (len[0] - node_idx);
	}
	else
	{
		if (is_in_top_mid(app->stack_a, node) && !is_in_top_mid(app->stack_b,
				target))
			mvs = node_idx + len[1] - target_idx;
		else
			mvs = target_idx + len[0] - node_idx;
	}
	return (mvs);
}
