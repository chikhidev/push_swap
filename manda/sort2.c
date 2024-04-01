#include "../includes/push_swap.h"

void    quick_sort(int *array, int start, int end)
{
    int pivot;
    int i;
    int j;
    int temp;

    if (start < end)
    {
        pivot = start;
        i = start;
        j = end;
        while (i < j)
        {
            while (array[i] <= array[pivot] && i < end)
                i++;
            while (array[j] > array[pivot])
                j--;
            if (i < j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;
        quick_sort(array, start, j - 1);
        quick_sort(array, j + 1, end);
    }
}

int *stack_to_array(t_app *app, t_stack *stack)
{
    int *array;
    t_list *current;
    int i;

    array = malloc(sizeof(int) * ft_lstsize(stack->head));
    if (!array)
        error(app, "Malloc failed");
    i = 0;
    current = stack->head;
    while (current)
    {
        array[i] = *(int *)current->content;
        current = current->next;
        i++;
    }
    return (array);
}
