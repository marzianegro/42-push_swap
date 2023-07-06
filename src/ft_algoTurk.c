/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mechanicalTurk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:05:15 by mnegro            #+#    #+#             */
/*   Updated: 2023/04/18 18:05:16 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Push the first two elements at the top of
	stack_a to stack_b, withouth checking anything */
void	ft_pushtwo(t_stack **stack_a, t_stack **stack_b, t_vals *vals)
{
	ft_push(stack_a, stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	vals->size_a = ft_stacksize(*stack_a);
	vals->size_b = ft_stacksize(*stack_b);
	if ((*stack_b)->nbr > (*stack_b)->next->nbr)
	{
		vals->max_b = (*stack_b)->nbr;
		vals->min_b = (*stack_b)->next->nbr;
	}
	else
	{
		vals->max_b = (*stack_b)->next->nbr;
		vals->min_b = (*stack_b)->nbr;
	}
}

void	ft_sortboth(t_stack **stack_a, t_stack **stack_b, t_vals *vals)
{
	while (vals->size_a > 3 && !ft_stacksorted(*stack_a))
		ft_apply_combo_ab((*stack_a)->nbr, stack_a, stack_b, vals);
	if (!ft_stacksorted(*stack_a))
		ft_sort_three(stack_a);
	vals->min_a = ft_findmin(*stack_a);
	vals->max_a = ft_findmax(*stack_a);
	while (vals->size_b > 0)
		ft_apply_combo_ba((*stack_b)->nbr, stack_b, stack_a, vals);
}

void	ft_turk(t_stack **stack_a, t_stack **stack_b)
{
	t_vals	vals;

	ft_pushtwo(stack_a, stack_b, &vals);
	ft_sortboth(stack_a, stack_b, &vals);
	vals.min_a = ft_findmin(*stack_a);
	vals.max_a = ft_findmax(*stack_a);
	if (vals.size_a > 2 && !ft_stacksorted(*stack_a))
	{
		if (ft_findidx(vals.min_a, *stack_a)
			< ft_stacksize(*stack_a) - vals.min_a)
		{
			while ((*stack_a)->nbr != vals.min_a)
				ft_rotate(stack_a, 'a');
		}
		else
		{
			while ((*stack_a)->nbr != vals.min_a)
				ft_reverserotate(stack_a, 'a');
		}
	}
}
