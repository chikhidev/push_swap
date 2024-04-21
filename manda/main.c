/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:18:29 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/21 14:13:40 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init(t_app *app)
{
	app->stack_a = malloc(sizeof(t_stack));
	app->stack_a->head = NULL;
	app->stack_b = malloc(sizeof(t_stack));
	app->stack_b->head = NULL;
}

int	is_sorted(t_stack *stack)
{
	t_list	*current;

	if (ft_lstsize(stack->head) < 2)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_app	app;
	int		i;

	if (ac < 2)
		return (0);
	init(&app);
	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
		{
			split_and_fill_stack(&app, av[i]);
			i++;
		}
	}
	if (is_sorted(app.stack_a))
	{
		free_stacks(&app);
		return (0);
	}
	sort_stack(&app);
	free_stacks(&app);
}
