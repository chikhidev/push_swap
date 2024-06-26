/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:01:34 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/20 18:01:35 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * @details push the first element of stack_b to stack_a
*/
void	push_a(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_list	*tmp;

	if (stack_b->head == NULL)
		return ;
	tmp = stack_b->head;
	stack_b->head = stack_b->head->next;
	if (stack_a->head == NULL)
	{
		tmp->next = NULL;
		stack_a->head = tmp;
	}
	else
	{
		tmp->next = stack_a->head;
		stack_a->head = tmp;
	}
	if (print)
		write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_list	*tmp;

	if (stack_a->head == NULL)
		return ;
	tmp = stack_a->head;
	stack_a->head = stack_a->head->next;
	if (stack_b->head == NULL)
	{
		tmp->next = NULL;
		stack_b->head = tmp;
	}
	else
	{
		tmp->next = stack_b->head;
		stack_b->head = tmp;
	}
	if (print)
		write(1, "pb\n", 3);
}
