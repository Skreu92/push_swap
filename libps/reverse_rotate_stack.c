/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:13:19 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/04 20:13:21 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void stack_reverse_rotate(t_stack **a)
{
	t_stack	*temp_start;
	t_stack	*temp_end;

	if (!*a || !(*a)->next)
		return ;
	temp_start = (*a)->next;
	temp_end = *a;
	while (temp_start->next)
	{
		temp_start = temp_start->next;
		temp_end = temp_end->next;
	}
	temp_start->next = *a;
	temp_end->next = NULL;
	*a = temp_start;
}

void stack_reverse_rotate_both(t_stack **a, t_stack **b)
{
	stack_rotate(a);
	stack_rotate(b);
}
