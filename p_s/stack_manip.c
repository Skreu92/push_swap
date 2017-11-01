/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:51:41 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/25 16:51:43 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stack_push_back(t_stack **begin_stack, int data)
{
	t_stack	*new;

	if (begin_stack == NULL)
		return ;
	if (*begin_stack == NULL)
	{
		*begin_stack = ft_create_elm(data);
		return ;
	}
	new = *begin_stack;
	while (new->next != NULL)
	{
		new = new->next;
	}
	new->next = ft_create_elm(data);
}

void	ft_stack_clear(t_stack **begin_stack)
{
	t_stack	*point;
	t_stack	*remove;

	if (begin_stack == NULL)
		return ;
	if (*begin_stack == NULL)
		return ;
	point = *begin_stack;
	while (point->next != NULL)
	{
		remove = point;
		point = point->next;
		free(remove);
	}
	free(point);
	*begin_stack = NULL;
}

int		measure_stack(t_stack **a)
{
	int		size;
	t_stack	*temp;

	if (!*a)
		return (0);
	size = 1;
	temp = *a;
	while (temp->next)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}


static int	compare_data(int current, t_stack **a)
{
	t_stack *temp;

	temp = *a;
	while (temp)
	{
		if (current > temp->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int			find_min(t_stack **a)
{
	int		min;
	t_stack	*temp;

	temp = *a;
	min = 0;
	while (temp)
	{
		if (compare_data(temp->data, a))
			break ;
		min++;
		temp = temp->next;
	}
	return (min);
}
