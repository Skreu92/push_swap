/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:31:56 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/04 20:31:57 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_rotate_a(t_stack **a)
{
	t_stack *temp_start;
	t_stack *temp_end;

	if (!*a || !(*a)->next)
		return ;
	temp_start = (*a)->next;
	temp_end = *a;
	while (temp_end->next)
		temp_end = temp_end->next;
	temp_end->next = *a;
	(*a)->next = NULL;
	*a = temp_start;
	write(1, "ra\n", 3);
}

void	stack_rotate_b(t_stack **a)
{
	t_stack *temp_start;
	t_stack *temp_end;

	if (!*a || !(*a)->next)
		return ;
	temp_start = (*a)->next;
	temp_end = *a;
	while (temp_end->next)
		temp_end = temp_end->next;
	temp_end->next = *a;
	(*a)->next = NULL;
	*a = temp_start;
	write(1, "rb\n", 3);
}

void	stack_rotate(t_stack **a)
{
	t_stack *temp_start;
	t_stack *temp_end;

	if (!*a || !(*a)->next)
		return ;
	temp_start = (*a)->next;
	temp_end = *a;
	while (temp_end->next)
		temp_end = temp_end->next;
	temp_end->next = *a;
	(*a)->next = NULL;
	*a = temp_start;
}

void	stack_rotate_both(t_stack **a, t_stack **b)
{
	stack_rotate(a);
	stack_rotate(b);
}
