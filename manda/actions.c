/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:01:08 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/20 18:01:09 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	index_of(t_stack *stack, t_list *node)
{
	t_list	*current;
	int		i;

	current = stack->head;
	i = 0;
	while (current)
	{
		if (current == node)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

void	move_to_top(t_app *app, t_stack *stack, t_list *node,
		int *moves_counter)
{
	if (stack->head == node)
		return ;
	if (index_of(stack, node) <= ft_lstsize(stack->head) / 2)
	{
		while (stack->head != node)
		{
			if (stack == app->stack_a)
				rotate_a(stack, 1);
			else
				rotate_b(stack, 1);
			if (moves_counter)
				(*moves_counter)++;
		}
	}
	else
	{
		while (stack->head != node)
		{
			if (stack == app->stack_a)
				reverse_rotate_a(stack, 1);
			else
				reverse_rotate_b(stack, 1);
			if (moves_counter)
				(*moves_counter)++;
		}
	}
}

/**
 * 5        34
 * 6        23
 * 42       -13
 * 83       60
* -234      -89
 * 24
*/