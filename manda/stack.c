#include "../includes/push_swap.h"

/**
 * @details Adds a number to the stack.
 * @param stack The stack to add the number to.
 * @param num The number to add to the stack.
*/
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

/**
 * @details Fills the stack with the numbers from the arguments.
 * @param ac The number of arguments.
 * @param av The arguments.
 * @param stack_a The stack to fill.
 * @param stack_b The other stack.
*/
void	fill_stack_a(t_app *app, int ac, char **av, int start)
{
	int	curr;
	int	i;

	i = start;
	while (i < ac)
	{
		if (!is_num(av[i]))
			error(app);
		curr = ft_atoi(av[i]);
		if (is_overflowed_num(av[i], curr))
			error(app);
		if (is_in_stack(app->stack_a, curr))
			error(app);
		add_num(app, app->stack_a, curr);
		i++;
	}
}

void	split_and_fill_stack(t_app *app, char **av)
{
	char	**splitted;
	int		i;

	splitted = ft_split(av[1], ' ');
	if (!splitted)
		error(app);
	i = 0;
	while (splitted[i])
		i++;
	fill_stack_a(app, i, splitted, 0);
	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}
