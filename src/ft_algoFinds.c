/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoFinds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:02:47 by mnegro            #+#    #+#             */
/*   Updated: 2023/05/14 15:02:48 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function finds the current position of a number in the stack */
int	ft_findidx(int nbr, t_stack *stack)
{
	int	idx;

	idx = 0;
	while (stack && stack->nbr != nbr)
	{
		idx++;
		stack = stack->next;
	}
	return (idx);
}

/* This function handles different cases based on the relationship between
	nbr and the top, last, minimum, and maximum values of stack_b and,
	depending on the case, it determines whether rotations are required
	or not and calculates the correct position in stack_b */
int	ft_finddst_ab(int nbr, t_stack *stack_b, t_vals *vals)
{
	int	dst;

	dst = 1;
	if (nbr > stack_b->nbr && nbr < ft_stacklast(stack_b)->nbr)
		dst = 0;
	else if (nbr < vals->min_b || nbr > vals->max_b)
		dst = ft_findidx(vals->max_b, stack_b);
	else
	{
		while (nbr > stack_b->nbr || nbr < stack_b->next->nbr)
		{
			dst++;
			stack_b = stack_b->next;
		}
	}
	return (dst);
}

/* This function handles different cases based on the relationship between
	nbr and the top, last, minimum, and maximum values of stack_a and,
	depending on the case, it determines whether rotations are required
	or not and calculates the correct position in stack_a */
int	ft_finddst_ba(int nbr, t_stack *stack_a, t_vals *vals)
{
	int	dst;

	dst = 1;
	if (nbr < stack_a->nbr && nbr > ft_stacklast(stack_a)->nbr)
		dst = 0;
	else if (nbr < vals->min_a || nbr > vals->max_a)
		dst = ft_findidx(vals->min_a, stack_a);
	else
	{
		while (nbr < stack_a->nbr || nbr > stack_a->next->nbr)
		{
			dst++;
			stack_a = stack_a->next;
		}
	}
	return (dst);
}

/* This functoin finds the smallest number in the stack */
int	ft_findmin(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = stack->nbr;
	while (stack)
	{
		if (i > stack->nbr)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

/* This function finds the biggest number in the stack */
int	ft_findmax(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = stack->nbr;
	while (stack)
	{
		if (i < stack->nbr)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}
