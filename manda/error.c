#include "../includes/push_swap.h"

void	free_stacks(t_app *app)
{
	ft_lstclear(&app->stack_a->head, free);
	ft_lstclear(&app->stack_b->head, free);
	free(app->stack_a);
	free(app->stack_b);
}

/**
 * @details print error message and exit
 * @param stack_a stack a
 * @param stack_b stack b
*/
void	error(t_app *app)
{
	free_stacks(app);
	write(2, "Error\n", 6);
	exit(1);
}
