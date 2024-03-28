#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>

#define SUCESS 0
#define ERROR 1

#include "../libft/libft.h"

/*____________structures____________*/

typedef struct s_stack
{
    t_list  *head;
}	t_stack;

typedef struct s_app
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     *array;
}	t_app;

/*____________prototypes____________*/

/*error*/
void    error(t_app *app, char *msg);
void    free_stacks(t_app *app);

/*validation*/
int     is_overflowed_num(char  *expected, int  actual);
int     is_num(char *str);

/*stack*/
void    add_num(t_app *app, t_stack *stack, int num);
void    fill_stack_a(t_app *app, int ac, char **av);

/*sort*/
void    sort_stack(t_app *app);


/*____actions____*/

/*push actions*/
void    push_a(t_stack *stack_a, t_stack *stack_b);
void    push_b(t_stack *stack_a, t_stack *stack_b);

/*swap actions*/
void    swap_a(t_stack *stack_a);
void    swap_b(t_stack *stack_b);
void    swap_ab(t_stack *stack_a, t_stack *stack_b);

/*rotate actions*/
void    rotate_a(t_stack *stack_a);
void    rotate_b(t_stack *stack_b);
void    rotate_ab(t_stack *stack_a, t_stack *stack_b);

/*reverse rotate actions*/
void    reverse_rotate_a(t_stack *stack_a);
void    reverse_rotate_b(t_stack *stack_b);
void    reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);

#endif