#include "../includes/push_swap.h"

void     stack_to_array(t_app *app, t_stack *stack)
{
    t_list  *current;
    int     i;
    int     stack_size;

    stack_size = ft_lstsize(stack->head);
    app->array = malloc(sizeof(int) * stack_size);
    if (!app->array)
        error(app, "Malloc failed\n");
    i = 0;
    current = stack->head;
    while (current)
    {
        app->array[i] = *(int *)current->content;
        current = current->next;
        i++;
    }
}

void    swap(int *a, int *b)
{
    int     tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    quick_sort(int *array, int start, int end, int stack_size)
{
    int     pivot;
    int     left;
    int     right;

    if (end <= start || start < 0 || end > 0 ||
        end >= stack_size || start >= stack_size)
        return ;
    pivot = array[end];
    left = start;
    right = end - 1;
    while (left <= right)
    {
        while (array[left] < pivot)
            left++;
        while (array[right] > pivot)
            right--;
        if (left <= right)
        {
            swap(&array[left], &array[right]);
            left++;
            right--;
        }
    }
    swap(&array[left], &array[end]);
    quick_sort(array, start, left - 1, stack_size);
    quick_sort(array, left + 1, end, stack_size);
}

void    sort_stack(t_app *app)
{
    stack_to_array(app, app->stack_a);

    if (ft_lstsize(app->stack_a->head) == 2)
    {
        if (app->array[0] > app->array[1])
            swap_a(app->stack_a);
        return ;
    }
    else if (ft_lstsize(app->stack_a->head) == 3)
    {
        if (*(int *)app->stack_a->head->content > *(int *)app->stack_a->head->next->content &&
            *(int *)app->stack_a->head->content > *(int *)app->stack_a->head->next->next->content)
            rotate_a(app->stack_a);
        if (*(int *)app->stack_a->head->content > *(int *)app->stack_a->head->next->content)
            swap_a(app->stack_a);
    }

    quick_sort(app->array, 0, ft_lstsize(app->stack_a->head) - 1, ft_lstsize(app->stack_a->head));

    //debug
    for (int i = 0; i < ft_lstsize(app->stack_a->head); i++)
        printf("%d\n", app->array[i]);
}

