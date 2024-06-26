/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:22:12 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/25 20:17:10 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*min(t_stack *stack)
{
	t_list	*min;
	t_list	*current;

	min = stack->head;
	current = stack->head;
	while (current)
	{
		if (*(int *)current->content < *(int *)min->content)
			min = current;
		current = current->next;
	}
	return (min);
}

t_list	*max(t_stack *stack)
{
	t_list	*max;
	t_list	*current;

	max = stack->head;
	current = stack->head;
	while (current)
	{
		if (*(int *)current->content > *(int *)max->content)
			max = current;
		current = current->next;
	}
	return (max);
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
		if (curr_value <= num && curr_value >= closest_value)
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
		if (curr_value >= num && curr_value <= closest_value)
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

int	in_top(t_stack *stack, t_list *node)
{
	int	len;
	int	idx;

	len = ft_lstsize(stack->head);
	idx = index_of(stack, node);
	if (idx < len / 2)
		return (1);
	return (0);
}
