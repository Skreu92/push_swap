/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:14:52 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/25 17:14:53 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_sort(t_stack **a, t_stack **b)
{
	t_stack *first;
	t_stack *second;

	if (*b)
		return (0);
	first = *a;
	second = (*a)->next;
	while (second)
	{
		if (first->data > second->data)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}

int		check_repetition(t_stack **a)
{
	int		temp_index;
	int		current_index;
	t_stack *temp;
	t_stack	*current;

	current_index = 1;
	current = *a;
	while (current)
	{
		temp = *a;
		temp_index = 1;
		while (temp->next)
		{
			if (current_index != temp_index && temp->data == current->data)
				return (0);
			temp_index++;
			temp = temp->next;
		}
		current = current->next;
		current_index++;
	}
	return (1);
}

int		check_a(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (!*a)
		return (1);
	first = *a;
	second = (*a)->next;
	while (second)
	{
		if (first->data > second->data)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}

int		check_b(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	if (!*b)
		return (1);
	first = *b;
	second = (*b)->next;
	while (second)
	{
		if (first->data < second->data)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}

t_stack		*ft_create_elm(int data)
{
	t_stack	*new;

	if (!(new = malloc(sizeof(t_stack))))
		return (new);
	new->data = data;
	new->next = NULL;
	return (new);
}
