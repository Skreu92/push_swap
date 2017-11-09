/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:20:05 by Etienne           #+#    #+#             */
/*   Updated: 2017/10/25 17:20:06 by Etienne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	perform_rr(t_path **opti, t_stack **a, t_stack **b)
{
	while ((*opti)->ra && (*opti)->rb)
	{
		stack_rotate_both(a, b);
		write(1, "rr\n", 3);
		(*opti)->ra--;
		(*opti)->rb--;
	}
}

void	perform_rrr(t_path **opti, t_stack **a, t_stack **b)
{
	while ((*opti)->rra && (*opti)->rrb)
	{
		stack_reverse_rotate_both(a, b);
		write(1, "rrr\n", 4);
		(*opti)->rra--;
		(*opti)->rrb--;
	}
}

void	make_moves_end(t_stack **a, t_stack **b)
{
	stack_push_b(b, a);
}

void	make_moves(t_path *opti, t_stack **a, t_stack **b)
{
	if (opti->ra && opti->rb)
		perform_rr(&opti, a, b);
	if (opti->rra && opti->rrb)
		perform_rrr(&opti, a, b);
	while (opti->ra--)
		stack_rotate_a(a);
	while (opti->rb--)
		stack_rotate_b(b);
	while (opti->rra--)
		stack_reverse_rotate_a(a);
	while (opti->rrb--)
		stack_reverse_rotate_b(b);
	make_moves_end(a, b);
}
