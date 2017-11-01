/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:56:12 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/25 16:56:13 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_a_path(t_path *current, int pos, t_stack **a)
{
	int	stack_size;

	stack_size = measure_stack(a);
	if (pos > stack_size - pos)
	{
		current->rra = stack_size - pos + 1;
		current->ra = 0;
	}
	else
	{
		current->ra = pos - 1;
		current->rra = 0;
	}
}

void	init_path_tab(t_path *tab)
{
	tab->ra = 0;
	tab->rb = 0;
	tab->rra = 0;
	tab->rrb = 0;
	tab->total = 0;
}
