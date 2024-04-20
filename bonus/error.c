#include "../includes/push_swap.h"

int is_num(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int is_overflowed_num(char  *expected, int  actual)
{
    char    *got;

    got = ft_itoa(actual);

    if (!got)
        return (1);

    if ((ft_strncmp(expected, got, ft_strlen(expected)) != 0 &&
        (ft_strlen(expected) == ft_strlen(got))) ||
        ft_strlen(expected) != ft_strlen(got))
    {
        free(got);
        return (1);
    }

    free(got);
    return (0);
}

void    free_stacks(t_app *app)
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
void    error(t_app *app)
{
    free_stacks(app);
    write(2, "Error\n", 6);
    exit(1);
}
