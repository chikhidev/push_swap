#include "../includes/push_swap.h"

t_stack  *copy(t_app *app, t_stack *stack)
{
    t_stack *new_stack;
    t_list  *current;
    t_list  *new_node;
    int     *new_content;

    new_stack = malloc(sizeof(t_stack));
    if (!new_stack)
        error(app, "Malloc failed");
    new_stack->head = NULL;
    current = stack->head;
    while (current)
    {
        new_content = malloc(sizeof(int *));
        if (!new_content)
            error(app, "Malloc failed");
        *new_content = *(int *)current->content;
        new_node = ft_lstnew(new_content);
        if (!new_node)
        {
            free(new_content);
            error(app, "Malloc failed");
        }
        ft_lstadd_back(&new_stack->head, new_node);
        current = current->next;
    }
    return (new_stack);
}

int index_of(int *array, int looking_for, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (array[i] == looking_for)
            return (i);
        i++;
    }
    return (-1);
}

void find_cheapest_move(t_app *app) {
    t_list *a_current_copy;
    t_list *a_current_original;
    int *array_b;
    int pos;
    int i = 0;
    int j;

    app->stack_a_copy = copy(app, app->stack_a);
    app->stack_b_copy = copy(app, app->stack_b);


    printf(YELLOW"stack a (copy)\tstack b (copy)\n"RESET);
    t_list *current_a = app->stack_a_copy->head;
    t_list *current_b = app->stack_b_copy->head;

    while (current_a || current_b) {
        if (current_a) {
            printf("%d\t", *(int *)current_a->content);
            current_a = current_a->next;
        }
        else
            printf("\t");
        if (current_b) {
            printf("%d\n", *(int *)current_b->content);
            current_b = current_b->next;
        }
        else
            printf("\n");
    }
    printf("\n\n");



    while (i < ft_lstsize(app->stack_a_copy->head)) {
        a_current_copy = app->stack_a_copy->head;
        a_current_original = app->stack_a->head;
        j = 0;
        while (j < i) { /*find the current a to make the scenario*/
            a_current_copy = a_current_copy->next;
            a_current_original = a_current_original->next;
            j++;
        }
        printf("current: %d----------------------\n", *(int *)a_current_copy->content);
        /*this is inside stack a*/
        a_current_original->moves_needed = 1; /*reset + one required for pb*/
        move_to_top(app, app->stack_a_copy, a_current_copy, &a_current_original->moves_needed);
        push_b(app->stack_a_copy, app->stack_b_copy);

        array_b = stack_to_array(app, app->stack_b_copy);
        /*this is inside stack b*/
        if (*(int *)a_current_copy->content < *(int *)app->stack_b_copy->head->content) {
            pos = index_of(array_b, *(int *)a_current_copy->content, ft_lstsize(app->stack_b_copy->head));
            if (pos < ft_lstsize(app->stack_b_copy->head) / 2)
                move_to_pos(app, app->stack_b_copy, pos, &a_current_copy->moves_needed);
            else
                move_to_pos(app, app->stack_b_copy, pos + 1, &a_current_copy->moves_needed);
        }
        free(array_b);
        printf(BLUE"moves %d\n" RESET, a_current_original->moves_needed);
        i++;

        printf(YELLOW"\n\nstack a (copy)\tstack b (copy)\n"RESET);
        current_a = app->stack_a_copy->head;
        current_b = app->stack_b_copy->head;


        while (current_a || current_b) {
            if (current_a) {
                printf("%d\t", *(int *)current_a->content);
                current_a = current_a->next;
            }
            else
                printf("\t");
            if (current_b) {
                printf("%d\n", *(int *)current_b->content);
                current_b = current_b->next;
            }
            else
                printf("\n");
        }
        printf("\n\n");
    }

    ft_lstclear(&app->stack_a_copy->head, free);
    ft_lstclear(&app->stack_b_copy->head, free);
}

void    sort_three(t_app *app)
{
    int top;
    int mid;
    int bot;

    while (!is_sorted(app->stack_a))
    {
        top = *(int *)app->stack_a->head->content;
        mid = *(int *)app->stack_a->head->next->content;
        bot = *(int *)app->stack_a->head->next->next->content;

        if (top > mid && top > bot)
            rotate_a(app->stack_a);
        else if (top > mid && top < bot)
        {
            swap_a(app->stack_a);
            rotate_a(app->stack_a);
        }
        else if (top < mid && top > bot)
            reverse_rotate_a(app->stack_a);
        else if (top < mid && top < bot)
            swap_a(app->stack_a);
    }
}

void	sort_five(t_app *app)
{
	t_list *tmp;
	t_list	*min;
	
	while (ft_lstsize(app->stack_a->head) > 3)
	{
		tmp = app->stack_a->head;
		min = tmp;
	       	while (tmp)
				{
			if (*(int *)tmp->content < *(int *)min->content)
				min = tmp;
			tmp = tmp->next;
		}
		/*here found the min*/
		move_to_top(app, app->stack_a, min, NULL);
		push_b(app->stack_a, app->stack_b);
	}
    sort_three(app);
    while (app->stack_b->head)
        push_a(app->stack_a, app->stack_b);
}

void    sort_logic(t_app *app)
{
    t_list *current;
    t_list  *cheapest;

    find_cheapest_move(app);
    current = app->stack_a->head;
    cheapest = current;
    while (current)
    {
        if (current->moves_needed < cheapest->moves_needed)
        {
            cheapest = current;
            break ;
        }
        current = current->next;
    }
    printf("cheapest: %d\n", *(int *)cheapest->content);
    move_to_top(app, app->stack_a, cheapest, NULL);
}

void    sort_stack(t_app *app)
{

    if (ft_lstsize(app->stack_a->head) == 2)
    {
        if (*(int *)app->stack_a->head->content > *(int *)app->stack_a->head->next->content)
            swap_a(app->stack_a);
        return ;
    }
    else if (ft_lstsize(app->stack_a->head) == 3)
        sort_three(app);
    else if (ft_lstsize(app->stack_a->head) > 3 && ft_lstsize(app->stack_a->head) <= 5)
        sort_five(app);
    else
        sort_logic(app);
}
