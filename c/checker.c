/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:49:55 by etranchi          #+#    #+#             */
/*   Updated: 2017/11/08 23:49:56 by etranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		fill_a(t_stack **a, char *arg)
{
	int		index;

	index = 0;
	while (arg[index])
	{
		while (arg[index] == ' ')
			index++;
		if (!ft_isdigit(arg[index]) ||
			(ft_atoi(&arg[index]) > INT_MAX || ft_atoi(&arg[index]) < INT_MIN))
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

static int		convert_args(t_stack **a, int argc, char **argv)
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

int				main(int argc, char **argv)
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
	read_moves(&a, &b);
	return (0);
}
