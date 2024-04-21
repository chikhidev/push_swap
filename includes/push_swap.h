/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:57:04 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/21 20:56:32 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>

# include "../libft/libft.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

/*____________structures____________*/

typedef struct s_stack
{
	t_list	*head;
}			t_stack;

typedef struct s_target
{
	t_list	*target;
	int		moves;
}			t_target;

typedef struct s_app
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**split;
}			t_app;

/*____________prototypes____________*/

/*error*/
void		error(t_app *app);
void		free_stacks(t_app *app);

/*validation*/
int			is_overflowed_num(char *expected, int actual);
int			is_num(char *str);
int			is_sorted(t_stack *stack);

/*stack*/
void		add_num(t_app *app, t_stack *stack, int num);
void		split_and_fill_stack(t_app *app, char *param);

/*sort*/
void		sort_stack(t_app *app);
void		sort_logic(t_app *app);
void		sort_three(t_app *app);

/*sort utils*/
t_list		*min(t_stack *stack);
t_list		*max(t_stack *stack);
t_list		*smaller_and_close(t_stack *stack, int num);
t_list		*bigger_and_close(t_stack *stack, int num);
int			in_top(t_stack *stack, t_list *node);
int			shortest_way(t_app *app, t_list *node, t_list *target);
t_list		*node_at_idx(t_stack *stack, int idx);

/*____actions____*/
int			index_of(t_stack *stack, t_list *node);
void		move_to_top(t_app *app, t_stack *stack, t_list *node,
				int *moves_counter);

/*push actions*/
void		push_a(t_stack *stack_a, t_stack *stack_b, int print);
void		push_b(t_stack *stack_a, t_stack *stack_b, int print);

/*swap actions*/
void		swap_a(t_stack *stack_a, int print);
void		swap_b(t_stack *stack_b, int print);
void		swap_ab(t_stack *stack_a, t_stack *stack_b, int print);

/*rotate actions*/
void		rotate_a(t_stack *stack_a, int print);
void		rotate_b(t_stack *stack_b, int print);
void		rotate_ab(t_stack *stack_a, t_stack *stack_b, int print);

/*reverse rotate actions*/
void		reverse_rotate_a(t_stack *stack_a, int print);
void		reverse_rotate_b(t_stack *stack_b, int print);
void		reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b, int print);

#endif