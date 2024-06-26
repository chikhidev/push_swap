/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:01:42 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/20 18:01:43 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * swap two top elements in the stack a
 * @param stack_a stack a
 * @details swaps the first 2 elements at the top of stack a
*/
void	swap_a(t_stack *stack_a, int print)
{
	void	*head_content;
	void	*next_content;

	if (ft_lstsize(stack_a->head) < 2)
		return ;
	head_content = stack_a->head->content;
	next_content = stack_a->head->next->content;
	stack_a->head->content = next_content;
	stack_a->head->next->content = head_content;
	if (print)
		write(1, "sa\n", 3);
}

/**
 * swap two top elements in the stack b
 * @param stack_b stack b
 * @details swaps the first 2 elements at the top of stack b
*/
void	swap_b(t_stack *stack_b, int print)
{
	void	*head_content;
	void	*next_content;

	if (ft_lstsize(stack_b->head) < 2)
		return ;
	head_content = stack_b->head->content;
	next_content = stack_b->head->next->content;
	stack_b->head->content = next_content;
	stack_b->head->next->content = head_content;
	if (print)
		write(1, "sb\n", 3);
}

/**
 * swap two top elements in the stack a and b
 * @param stack_a stack a
 * @param stack_b stack b
 * @note swap_ab = swap_a + swap_b
 * @details swaps the first 2 elements at the top of stack a and stack b
*/
void	swap_ab(t_stack *stack_a, t_stack *stack_b, int print)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	if (print)
		write(1, "ss\n", 3);
}
