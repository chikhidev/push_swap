#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define RESET "\033[0m"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

#include "../libft/libft.h"

/*____________structures____________*/

typedef struct s_stack
{
    t_list  *head;
}	t_stack;

typedef struct s_target
{
    t_list *target;
    int moves;
}	t_target;

typedef struct s_app
{
    t_stack *stack_a;
    t_stack *stack_b;
}	t_app;

/*____________prototypes____________*/

/*error*/
void    error(t_app *app, char *msg);
void    free_stacks(t_app *app);

/*validation*/
int     is_overflowed_num(char  *expected, int  actual);
int     is_num(char *str);
int     is_sorted(t_stack *stack);

/*stack*/
void    add_num(t_app *app, t_stack *stack, int num);
void    fill_stack_a(t_app *app, int ac, char **av);

/*sort*/
void    sort_stack(t_app *app);
void    sort_logic(t_app *app);

/*sort utils*/
void    quick_sort(int *array, int start, int end);
int     *stack_to_array(t_app *app, t_stack *stack);

/*____actions____*/
int     index_of(t_stack *stack, t_list *node);
void    move_to_top(t_app *app, t_stack *stack, t_list *node, int *moves_counter);

/*push actions*/
void    push_a(t_stack *stack_a, t_stack *stack_b, int print);
void    push_b(t_stack *stack_a, t_stack *stack_b, int print);

/*swap actions*/
void    swap_a(t_stack *stack_a, int print);
void    swap_b(t_stack *stack_b, int print);
void    swap_ab(t_stack *stack_a, t_stack *stack_b, int print);

/*rotate actions*/
void    rotate_a(t_stack *stack_a, int print);
void    rotate_b(t_stack *stack_b, int print);
void    rotate_ab(t_stack *stack_a, t_stack *stack_b, int print);

/*reverse rotate actions*/
void    reverse_rotate_a(t_stack *stack_a, int print);
void    reverse_rotate_b(t_stack *stack_b, int print);
void    reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b, int print);

#endif