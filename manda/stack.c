#include "../includes/push_swap.h"

/**
 * @details Adds a number to the stack.
 * @param stack The stack to add the number to.
 * @param num The number to add to the stack.
*/
void    add_num(t_app *app, t_stack *stack, int num)
{
    t_list  *node;
    int     *content;

    content = (int *)malloc(sizeof(int));
    if (!content)
        error(app, "Memory allocation failed");
    *content = num;
    node = ft_lstnew(content);
    if (!node)
        error(app, "Memory allocation failed");
    if (!stack->head)
        stack->head = node;
    else
        ft_lstadd_back(&stack->head, node);
}

int is_in_stack(t_stack *stack, int num)
{
    t_list *current;

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
void    fill_stack_a(t_app *app, int ac, char **av)
{
    int     curr;
    int     i;

    i = 1;
    while (i < ac)
    {
        if (!is_num(av[i])) error(app, "Invalid argument");
        curr = ft_atoi(av[i]);
        if (is_overflowed_num(av[i], curr)) error(app, "Found overflowed or miss formatted number");
        if (is_in_stack(app->stack_a, curr)) error(app, "Duplicate number");
        add_num(app, app->stack_a, curr);
        i++;
    }
}
