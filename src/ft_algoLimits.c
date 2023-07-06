/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoChecks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:53:06 by mnegro            #+#    #+#             */
/*   Updated: 2023/04/29 19:53:07 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The number at the top of stack_a is going to be
	the new biggest number in stack_b */
void	ft_newmax_ab(t_stack **stack_a, t_stack **stack_b, t_vals *vals)
{
	if ((*stack_a)->nbr < vals->max_b)
		return ;
	while ((*stack_b)->nbr != vals->max_b)
		ft_rotate(stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	vals->max_b = (*stack_b)->nbr;
	vals->size_a--;
	vals->size_b++;
}

/* The number at the top of stack_a is going to be
	the new smallest number in stack_b */
void	ft_newmin_ab(t_stack **stack_a, t_stack **stack_b, t_vals *vals)
{
	if ((*stack_a)->nbr > vals->min_b)
		return ;
	while (vals->max_b != (*stack_b)->nbr)
		ft_rotate(stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	vals->min_b = (*stack_b)->nbr;
	vals->size_a--;
	vals->size_b++;
}

/* The number at the top of stack_a is going to be
	the new biggest number in stack_b */
void	ft_newmax_ba(t_stack **stack_b, t_stack **stack_a, t_vals *vals)
{
	if (vals->size_b > 0)
	{
		if ((*stack_b)->nbr < vals->max_a)
			return ;
		while (vals->max_a != (*stack_a)->nbr)
			ft_rotate(stack_a, 'a');
		ft_push(stack_b, stack_a, 'a');
		vals->max_a = (*stack_a)->nbr;
		vals->size_b--;
		vals->size_a++;
	}
}

/* The number at the top of stack_b is going to be
	the new smallest number in stack_a */
void	ft_newmin_ba(t_stack **stack_b, t_stack **stack_a, t_vals *vals)
{
	if (vals->size_b > 0)
	{
		if ((*stack_b)->nbr > vals->min_a)
			return ;
		while (vals->min_a != (*stack_a)->nbr)
			ft_rotate(stack_a, 'a');
		ft_push(stack_b, stack_a, 'a');
		vals->min_a = (*stack_a)->nbr;
		vals->size_b--;
		vals->size_a++;
	}
}
