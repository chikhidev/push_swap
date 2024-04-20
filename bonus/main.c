#include "../get_next_line/get_next_line.h"
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

void	helper(t_app *app, char *line)
{
	if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0 && ft_strlen(line) == 3)
		rotate_b(app->stack_b, 0);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0
			&& ft_strlen(line) == 3)
		rotate_ab(app->stack_a, app->stack_b, 0);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0
			&& ft_strlen(line) == 4)
		reverse_rotate_a(app->stack_a, 0);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0
			&& ft_strlen(line) == 4)
		reverse_rotate_b(app->stack_b, 0);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0
			&& ft_strlen(line) == 4)
		reverse_rotate_ab(app->stack_a, app->stack_b, 0);
	else
	{
		free(line);
		line = get_next_line(STDIN_FILENO, 1);
		free(line);
		error(&app);
	}
}

void	handle_input(t_app *app)
{
	char	*line;

	line = get_next_line(STDIN_FILENO, 0);
	while (line)
	{
		if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0
			&& ft_strlen(line) == 3)
			swap_a(app->stack_a, 0);
		else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0
				&& ft_strlen(line) == 3)
			swap_b(app->stack_b, 0);
		else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0
				&& ft_strlen(line) == 3)
			swap_ab(app->stack_a, app->stack_b, 0);
		else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0
				&& ft_strlen(line) == 3)
			push_a(app->stack_a, app->stack_b, 0);
		else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0
				&& ft_strlen(line) == 3)
			push_b(app->stack_a, app->stack_b, 0);
		else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0
				&& ft_strlen(line) == 3)
			rotate_a(app->stack_a, 0);
		else
			helper(app, line);
		free(line);
		line = get_next_line(STDIN_FILENO, 0);
	}
}

int	main(int ac, char **av)
{
	t_app	app;
	char	*line;

	if (ac < 2)
		return (0);
	init(&app);
	if (ac == 2)
		split_and_fill_stack(&app, av);
	else
		fill_stack_a(&app, ac, av, 1);
	if (app.stack_a->head == NULL || is_sorted(app.stack_a))
	{
		free_stacks(&app);
		return (0);
	}
	handle_input(&app);
	if (is_sorted(app.stack_a) && app.stack_b->head == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(&app);
	return (0);
}
