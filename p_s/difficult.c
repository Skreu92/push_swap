/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difficult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:53:45 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/25 16:53:46 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		refresh_opti(t_path *opti, t_path *temp_w)
{
	opti->ra = temp_w->ra;
	opti->rra = temp_w->rra;
	opti->rb = temp_w->rb;
	opti->rrb = temp_w->rrb;
	opti->total = temp_w->total;
}

void		find_lowest_path(t_path *opti, t_stack **a, t_stack **b)
{
	int			a_size;
	int			pos;
	t_path	temp_w;
	t_stack		*temp_s;

	temp_s = *a;
	init_path_tab(&temp_w);
	pos = 1;
	find_a_path(opti, pos, a);
	find_b_path(opti, temp_s->data, b);
	a_size = measure_stack(a);
	while (temp_s)
	{
		find_a_path(&temp_w, pos, a);
		find_b_path(&temp_w, temp_s->data, b);
		if (temp_w.total < opti->total)
			refresh_opti(opti, &temp_w);
		temp_s = temp_s->next;
		pos++;
	}
}

static void	fill_a(int b_size, t_stack **a, t_stack **b)
{
	int		min;

	min = find_min(b);
	if (b_size - min > min)
	{
		while (min + 1)
		{
			stack_rotate(b);
			write(1, "rb\n", 3);
			min--;
		}
	}
	else
	{
		while (min < b_size - 1)
		{
			stack_reverse_rotate(b);
			write(1, "rrb\n", 4);
			min++;
		}
	}
	while (*b)
	{
		stack_push_to(a, b);
		write(1, "pa\n", 3);
	}
}

void		sort_advanced(t_stack **a, t_stack **b)
{
	int			b_size;
	int			weight;
	t_path	opti;

	weight = 0;
	stack_push_to(b, a);
	stack_push_to(b, a);
	write(1, "pb\npb\n", 6);
	if ((*b)->data < (*b)->next->data)
	{
		stack_reverse_rotate(b);
		write(1, "rrb\n", 4);
	}
	while (*a)
	{
		init_path_tab(&opti);
		find_lowest_path(&opti, a, b);
		make_moves(&opti, a, b);
	}
	b_size = measure_stack(b);
	fill_a(b_size, a, b);
}
