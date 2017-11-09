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

void	refresh_opti(t_path *opti, t_path *temp_w)
{
	opti->ra = temp_w->ra;
	opti->rra = temp_w->rra;
	opti->rb = temp_w->rb;
	opti->rrb = temp_w->rrb;
	opti->total = temp_w->total;
}

void	find_lowest_path(t_path *opti, t_stack **a, t_stack **b)
{
	int			a_size;
	int			pos;
	t_path		temp_w;
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

void	fill_a_end(t_stack **a, t_stack **b)
{
	stack_push_a(a, b);
}

void	fill_aa(int b_size, t_stack **a, t_stack **b)
{
	int		min;

	min = find_min(b);
	if (b_size - min > min)
	{
		while (min + 1)
		{
			stack_rotate_b(b);
			min--;
		}
	}
	else
	{
		while (min < b_size - 1)
		{
			stack_reverse_rotate_b(b);
			min++;
		}
	}
	while (*b)
		fill_a_end(a, b);
}

void	sort_advanced(t_stack **a, t_stack **b)
{
	int			b_size;
	int			weight;
	t_path		opti;

	weight = 0;
	stack_push_b(b, a);
	stack_push_b(b, a);
	if ((*b)->data < (*b)->next->data)
		stack_reverse_rotate_b(b);
	while (*a)
	{
		init_path_tab(&opti);
		find_lowest_path(&opti, a, b);
		make_moves(&opti, a, b);
	}
	b_size = measure_stack(b);
	fill_aa(b_size, a, b);
}
