/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:01:36 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/20 18:01:37 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * reverse rotate the stack a
 * @param stack_a stack a
 * @details shift down all elements of stack a by 1
*/
void	reverse_rotate_a(t_stack *stack_a, int print)
{
	t_list	*last;
	t_list	*tmp;

	if (ft_lstsize(stack_a->head) < 2)
		return ;
	last = ft_lstlast(stack_a->head);
	tmp = stack_a->head;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = stack_a->head;
	stack_a->head = last;
	if (print)
		write(1, "rra\n", 4);
}

/**
 * reverse rotate the stack a
 * @param stack_b stack a
 * @details shift down all elements of stack a by 1
*/
void	reverse_rotate_b(t_stack *stack_b, int print)
{
	t_list	*last;
	t_list	*tmp;

	if (ft_lstsize(stack_b->head) < 2)
		return ;
	last = ft_lstlast(stack_b->head);
	tmp = stack_b->head;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = stack_b->head;
	stack_b->head = last;
	if (print)
		write(1, "rrb\n", 4);
}

/**
 * reverse rotate the stack a and b
 * @param stack_a stack a
 * @param stack_b stack b
 * @note reverse_rotate_ab = reverse_rotate_a + reverse_rotate_b
 * @details shift down all elements of stack a and stack b by 1
*/
void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b, int print)
{
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	if (print)
		write(1, "rrr\n", 4);
}