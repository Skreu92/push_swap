/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:50:04 by etranchi          #+#    #+#             */
/*   Updated: 2017/11/08 23:50:06 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_move(char *move, t_stack **a, t_stack **b)
{
	if (ft_strcmp("pb", move) == 0)
		stack_push_to(b, a);
	else if (ft_strcmp("sa", move) == 0)
		stack_swap(a);
	else if (ft_strcmp("pa", move) == 0)
		stack_push_to(a, b);
	else if (ft_strcmp("sb", move) == 0)
		stack_swap(b);
	else if (ft_strcmp("ss", move) == 0)
		stack_swap_ss(a, b);
	else if (ft_strcmp("ra", move) == 0)
		stack_rotate(a);
	else if (ft_strcmp("rb", move) == 0)
		stack_rotate(b);
	else if (ft_strcmp("rr", move) == 0)
		stack_rotate_both(a, b);
	else if (ft_strcmp("rra", move) == 0)
		stack_reverse_rotate(a);
	else if (ft_strcmp("rrb", move) == 0)
		stack_reverse_rotate(b);
	else if (ft_strcmp("rrr", move) == 0)
		stack_reverse_rotate_both(a, b);
	else
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	free(move);
}

void ft_kill(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

void	read_moves(t_stack **a, t_stack **b)
{
	char *move;
	int i;

	i = -1;
	while (get_next_line(STDIN_FILENO, &move))
	{
		while(move[++i])
			if(move[i] == ' ')
				ft_kill("Errora\n");
		make_move(move, a, b);
	}
	if (check_sort(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "Error\n", 6);
}
