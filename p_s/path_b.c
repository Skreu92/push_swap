/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:03:27 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/25 17:03:28 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	assign_b_path(t_path **current, int pos, t_stack **b)
{
	int		stack_size;

	stack_size = measure_stack(b);
	if (pos > stack_size - pos)
	{
		(*current)->rb = 0;
		(*current)->rrb = stack_size - pos + 1;
	}
	else
	{
		(*current)->rrb = 0;
		(*current)->rb = pos - 1;
	}
}

static void	assign_inv_b_path(t_path **current, int pos, t_stack **b)
{
	int		stack_size;

	stack_size = measure_stack(b);
	if (pos > stack_size - pos)
	{
		(*current)->rb = 0;
		(*current)->rrb = stack_size - pos;
	}
	else
	{
		(*current)->rrb = 0;
		(*current)->rb = pos;
	}
}

static void	find_closest_sup(t_path **current, int data, t_stack **b)
{
	t_stack	*temp;
	int		current_pos;
	int		save_pos;
	long	dif;

	temp = *b;
	dif = LONG_MIN;
	current_pos = 1;
	save_pos = 1;
	while (temp)
	{
		if (temp->data > data && data - temp->data > dif)
		{
			dif = data - temp->data;
			save_pos = current_pos;
		}
		temp = temp->next;
		current_pos++;
	}
	assign_inv_b_path(current, save_pos, b);
}

void		find_b_path(t_path *current, int data, t_stack **b)
{
	t_stack	*temp;
	int		current_pos;
	int		save_pos;
	long	dif;

	temp = *b;
	dif = LONG_MAX;
	current_pos = 1;
	save_pos = 1;
	while (temp)
	{
		if (temp->data < data && data - temp->data < dif)
		{
			dif = data - temp->data;
			save_pos = current_pos;
		}
		temp = temp->next;
		current_pos++;
	}
	if (dif == LONG_MAX)
		find_closest_sup(&current, data, b);
	else
		assign_b_path(&current, save_pos, b);
	current->total = current->ra + current->rra + current->rb + current->rrb;
}

