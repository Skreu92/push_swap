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

long	ft_atol(char *str)
{
	int		s;
	long	n;
	int		i;

	i = 0;
	s = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * s);
}

static int		fill_a(t_stack **a, char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		while (arg[i] == ' ')
			i++;
		if ((ft_atol(&arg[i]) > INT_MAX || ft_atol(&arg[i]) < INT_MIN))
			return (0);
		ft_stack_push_back(a, ft_atol(&arg[i]));
		while (arg[i] && arg[i] != ' ')
			i++;
		while (arg[i] && arg[i] == ' ')
			i++;
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
