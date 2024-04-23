/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:01:53 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/21 20:56:14 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_num(t_app *app, t_stack *stack, int num)
{
	t_list	*node;
	int		*content;

	content = (int *)malloc(sizeof(int));
	if (!content)
		error(app);
	*content = num;
	node = ft_lstnew(content);
	if (!node)
		error(app);
	if (!stack->head)
		stack->head = node;
	else
		ft_lstadd_back(&stack->head, node);
}

int	is_in_stack(t_stack *stack, int num)
{
	t_list	*current;

	current = stack->head;
	while (current)
	{
		if (*(int *)current->content == num)
			return (1);
		current = current->next;
	}
	return (0);
}

void	create_node(t_app *app, char *data)
{
	int	content;

	if (!is_num(data))
		error(app);
	content = ft_atoi(data);
	if (is_overflowed_num(data, content))
		error(app);
	if (is_in_stack(app->stack_a, content))
		error(app);
	add_num(app, app->stack_a, content);
}

void	split_and_fill_stack(t_app *app, char *param)
{
	int		i;

	app->split = ft_split(param, ' ');
	if (!app->split)
		error(app);
	i = 0;
	while (app->split[i])
		i++;
	i = 0;
	while (app->split[i])
	{
		create_node(app, app->split[i]);
		i++;
	}
	i = 0;
	while (app->split[i])
	{
		free(app->split[i]);
		app->split[i] = NULL;
		i++;
	}
	free(app->split);
	app->split = NULL;
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
