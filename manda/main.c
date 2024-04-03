#include "../includes/push_swap.h"

void    init(t_app *app)
{
    app->stack_a = malloc(sizeof(t_stack));
    app->stack_a->head = NULL;
    app->stack_b = malloc(sizeof(t_stack));
    app->stack_b->head = NULL;
}

int is_sorted(t_stack *stack)
{
    t_list *current;

    current = stack->head;
    while (current->next)
    {
        if (*(int *)current->content > *(int *)current->next->content)
            return (0);
        current = current->next;
    }
    return (1);
}

int main(int ac, char **av)
{
    t_app   app;

    if (ac < 2)
        error(&app, "Invalid number of arguments\n");

    else if (ac == 2)
        return (0);

    init(&app);

    fill_stack_a(&app, ac, av);
    if (is_sorted(app.stack_a))
    {
        free_stacks(&app);
        return (0);
    }


    sort_stack(&app);

    // printf("_____________\nafter sort--------------\n");

    // for (t_list *current = app.stack_a->head; current; current = current->next)
    // {
    //     printf("%d\n", *(int *)current->content);
    // }

    is_sorted(app.stack_a) ? printf(GREEN"OK\n") : printf(RED"KO\n");
    printf(RESET);

    free_stacks(&app);

}
