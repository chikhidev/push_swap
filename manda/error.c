#include "../includes/push_swap.h"

void    free_stacks(t_app *app)
{
    ft_lstclear(&app->stack_a->head, free);
    ft_lstclear(&app->stack_b->head, free);
    ft_lstclear(&app->stack_a_copy->head, free);
    ft_lstclear(&app->stack_b_copy->head, free);
    free(app->stack_a);
    free(app->stack_b);
    free(app->stack_a_copy);
    free(app->stack_b_copy);
}

/**
 * @details print error message and exit
 * @param stack_a stack a
 * @param stack_b stack b
*/
void    error(t_app *app, char *msg)
{
    free_stacks(app);
    write(2, "Error: ", 8);
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    exit(1);
}
