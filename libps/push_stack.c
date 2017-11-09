/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:51:36 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/04 19:51:38 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_push_a(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!*b)
		return ;
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		temp = *a;
		*a = *b;
		*b = (*b)->next;
		(*a)->next = temp;
	}
	write(1, "pa\n", 3);
}

void	stack_push_to(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!*b)
		return ;
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		temp = *a;
		*a = *b;
		*b = (*b)->next;
		(*a)->next = temp;
	}
}

void	stack_push_b(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!*b)
		return ;
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		temp = *a;
		*a = *b;
		*b = (*b)->next;
		(*a)->next = temp;
	}
	write(1, "pb\n", 3);
}
