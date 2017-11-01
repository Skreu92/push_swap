/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:45:41 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/25 16:45:42 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>

typedef struct		s_stack
{
	intmax_t		data;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_path
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				total;
}					t_path;


/*
**				libps
*/
void stack_swap_one(t_stack **a);
void stack_swap_ss(t_stack **a, t_stack **b);
void stack_push_to(t_stack **a, t_stack **b);
void stack_rotate(t_stack **a);
void stack_rotate_both(t_stack **a, t_stack **b);
void stack_reverse_rotate(t_stack **a);
void stack_reverse_rotate_both(t_stack **a, t_stack **b);
/*
**					stack_manip.c
*/
void	ft_stack_push_back(t_stack **begin_stack, int data);
void	ft_stack_clear(t_stack **begin_stack);
int			find_min(t_stack **a);
int			measure_stack(t_stack **a);

/*
**					difficult.c
*/
void		sort_advanced(t_stack **a, t_stack **b);
void		refresh_opti(t_path *opti, t_path *temp_w);

/*
**				easy.c
*/
void		sort_select(t_stack **a, t_stack **b);

/*
**				path_a.c
*/
void	find_a_path(t_path *current, int pos, t_stack **a);
void	init_path_tab(t_path *tab);

/*
**				path_b.c
*/
void		find_b_path(t_path *current, int data, t_stack **b);

/*
**				check.c
*/
int		check_sort(t_stack **a, t_stack **b);
int		check_repetition(t_stack **a);
int		check_a(t_stack **a);
int		check_b(t_stack **a);
t_stack		*ft_create_elm(int data);

/*
**				move.c
*/
void		make_moves(t_path *opti, t_stack **a, t_stack **b);
#endif
