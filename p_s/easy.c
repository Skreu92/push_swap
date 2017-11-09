/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:54:16 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/25 16:54:17 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			compare_data(int current, t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (current > temp->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int			check_piles(t_stack **a, t_stack **b)
{
	if (check_a(a) && check_b(b))
		return (1);
	return (0);
}

int			check_swap_first(t_stack **a)
{
	int		first;
	int		second;
	t_stack	*temp;

	temp = *a;
	first = temp->data;
	temp = temp->next;
	second = temp->data;
	if (second > first)
		return (0);
	temp = temp->next;
	while (temp)
	{
		if (temp->data < first || temp->data < second)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void		sort_select(t_stack **a, t_stack **b)
{
	int		min;

	while (!check_piles(a, b))
	{
		min = find_min(a);
		if (min && check_swap_first(a))
			stack_swap_a(a);
		else
		{
			if (min > measure_stack(a) - min && (min = measure_stack(a) - min))
			{
				while (!check_piles(a, b) && min--)
					stack_reverse_rotate_a(a);
			}
			else
			{
				while (!check_piles(a, b) && min--)
					stack_rotate_a(a);
			}
		}
		if (!check_piles(a, b))
			stack_push_b(b, a);
	}
	while (*b)
		stack_push_a(a, b);
}
