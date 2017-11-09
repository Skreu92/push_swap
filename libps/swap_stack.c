/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:46:16 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/04 19:46:17 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_swap_a(t_stack **a)
{
	t_stack *second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	second = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
	write(1, "sa\n", 3);
}

void	stack_swap_b(t_stack **a)
{
	t_stack *second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	second = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
	write(1, "sb\n", 3);
}

void	stack_swap(t_stack **a)
{
	t_stack *second;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	second = (*a)->next;
	(*a)->next = second->next;
	second->next = *a;
	*a = second;
}

void	stack_swap_ss(t_stack **a, t_stack **b)
{
	stack_swap(a);
	stack_swap(b);
}
