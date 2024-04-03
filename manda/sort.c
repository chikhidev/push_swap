#include "../includes/push_swap.h"

t_list  *min(t_stack *stack)
{
    t_list *min;

    min = stack->head;
    for (t_list *current = stack->head; current; current = current->next)
    {
        if (*(int *)current->content < *(int *)min->content)
            min = current;
    }
    return (min);
}

t_list  *max(t_stack *stack)
{
    t_list *max;

    max = stack->head;
    for (t_list *current = stack->head; current; current = current->next)
    {
        if (*(int *)current->content > *(int *)max->content)
            max = current;
    }
    return (max);
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

int get_perfect_offset(t_app *app)
{
    if (ft_lstsize(app->stack_a->head) <= 100)
        return 12;
    else if (ft_lstsize(app->stack_a->head) <= 500)
        return 21;
    else
        return 31;
}

int is_in_range(int *array, int start, int end, int num)
{
    for (int i = start; i <= end; i++)
    {
        if (array[i] == num)
            return (1);
    }
    return (0);
}

int contains(t_stack *stack, int *array, int start, int end)
{
    t_list *current;

    current = stack->head;
    while (current)
    {
        if (is_in_range(array, start, end, *(int *)current->content))
            return (1);
        current = current->next;
    }
    return (0);
}

void    sort_logic(t_app *app)
{
    int *array;
    t_list *current;
    t_list  *b_max;
    int     i;
    int     array_size;

    /*step 1 generate array and sort it*/
    array = stack_to_array(app, app->stack_a);
    array_size = ft_lstsize(app->stack_a->head);
    quick_sort(array, 0, array_size - 1);

    /*referance the mid, offset*/
    app->mid = array[(array_size / 2) - 1];
    app->offset = get_perfect_offset(app);
    app->start = app->mid - app->offset;
    app->end = app->mid + app->offset;
    if (app->start < 0)
            app->start = 0;
    if (app->end > array_size - 1)
        app->end = array_size - 1;
    /*step 2 push to stack_b*/

    /*print the array*/
    // printf(BLUE"array: [");
    // for (int i = 0; i < array_size; i++)
    //     printf("%d ", array[i]);
    // printf("]\n"RESET);

    while (app->stack_a->head)
    {
        // printf("start %d, end %d, mid %d, offset %d\n", app->start, app->end, app->mid, app->offset);
        current = app->stack_a->head;
        while (current)
        {
            if (!contains(app->stack_a, array, app->start, app->end))
                break ;
            // printf("current %d\n", *(int *)current->content);
            if (is_in_range(array, app->start, app->end, *(int *)current->content))
            {
                move_to_top(app, app->stack_a, current, NULL);
                push_b(app->stack_a, app->stack_b);
                if (*(int *)current < app->mid && ft_lstsize(app->stack_b->head) > 1)
                    rotate_b(app->stack_b);
            }
            else
                rotate_a(app->stack_a);
            current = app->stack_a->head;

            /*dispay stacks*/
            // printf(YELLOW"stack a\t|\tstack b\n");
            // for (t_list *a = app->stack_a->head, *b = app->stack_b->head; a || b; a = a ? a->next : NULL, b = b ? b->next : NULL)
            // {
            //     if (a)
            //         printf("%d\t|\t", *(int *)a->content);
            //     else
            //         printf("\t|\t");
            //     if (b)
            //         printf("%d\n", *(int *)b->content);
            //     else
            //         printf("\n");
            // }
            // printf("____________________\n"RESET);
            // printf(RESET);
        }

        app->start -= app->offset;
        app->end += app->offset;
        if (app->start < 0)
            app->start = 0;
        // printf("end %d, size %d\n", app->end, array_size - 1);
        if (app->end > array_size - 1)
            app->end = array_size - 1;


        // printf("(new) start %d, end %d, mid %d, offset %d\n", app->start, app->end, app->mid, app->offset);
        // return ;
    }

    // printf(RED"____________________Pushing to stack b done____________________\n"RESET);
    // printf(GREEN"____________________Returning to stack a____________________\n"RESET);

    /*step 3 push biggest and so on from b to a*/
    // // exit(0);
    i = array_size - 1;
    while (app->stack_b->head)
    {
        if (*(int *)app->stack_b->head->content == array[i])
        {
            push_a(app->stack_a, app->stack_b);
            if (ft_lstsize(app->stack_a->head) > 1)
                rotate_a(app->stack_a);
            i--;
        }
        else
        {
            b_max = max(app->stack_b);
            move_to_top(app, app->stack_b, b_max, NULL);
            push_a(app->stack_a, app->stack_b);
        }
    //     /*dispay stacks*/
    //     // printf(YELLOW"stack a\t|\tstack b\n");
    //     // for (t_list *a = app->stack_a->head, *b = app->stack_b->head; a || b; a = a ? a->next : NULL, b = b ? b->next : NULL)
    //     // {
    //     //     if (a)
    //     //         printf("%d\t|\t", *(int *)a->content);
    //     //     else
    //     //         printf("\t|\t");
    //     //     if (b)
    //     //         printf("%d\n", *(int *)b->content);
    //     //     else
    //     //         printf("\n");
    //     // }
    //     // printf("____________________\n"RESET);
    //     // printf(RESET);
    }
    free(array);
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
