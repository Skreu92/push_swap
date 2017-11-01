/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:45:21 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/25 16:45:22 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	call_sort(t_stack **a, t_stack **b)
{
	int		stack_size;

	stack_size = measure_stack(a);
	if (check_sort(a, b))
		return ;
	if (stack_size > 10)
		sort_advanced(a, b);
	else
	{
		if (stack_size == 3 && (*a)->next->next->data < (*a)->data &&
				(*a)->next->next->data < (*a)->next->data &&
				(*a)->data > (*a)->next->data)
			stack_swap_one(a);
		sort_select(a, b);
	}
}

static int	fill_a(t_stack **a, char *arg)
{
	int		index;

	index = 0;
	while (arg[index])
	{
		while (arg[index] == ' ')
			index++;
		if (ft_atoi(&arg[index]) > INT_MAX || ft_atoi(&arg[index]) < INT_MIN)
			return (0);
		ft_stack_push_back(a, ft_atoi(&arg[index]));
		while (arg[index] && arg[index] != ' ')
			index++;
		while (arg[index] && arg[index] == ' ')
			index++;
	}
	if (!check_repetition(a))
		return (0);
	return (1);
}

static int	convert_args(t_stack **a, int argc, char **argv)
{
	int		index;

	index = 1;
	while (index < argc)
	{
		if (!fill_a(a, argv[index]))
			return (0);
		index++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!convert_args(&a, argc, argv))
	{
		write(2, "Error\n", 6);
		ft_stack_clear(&a);
		return (0);
	}
	call_sort(&a, &b);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}