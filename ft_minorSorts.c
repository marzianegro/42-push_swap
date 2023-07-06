/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minorSorts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:05:00 by mnegro            #+#    #+#             */
/*   Updated: 2023/04/18 18:05:01 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	ft_resetabc(*stack, &a, &b, &c);
	if (a < b)
	{
		ft_reverserotate(stack, 'a');
		ft_resetabc(*stack, &a, &b, &c);
		if (a > b && b < c)
			ft_swap(*stack, 'a');
	}
	else if (a > b && a > c && b < c)
		ft_rotate(stack, 'a');
	else
	{
		ft_swap(*stack, 'a');
		ft_resetabc(*stack, &a, &b, &c);
		if (b > c)
			ft_reverserotate(stack, 'a');
	}
}

void	ft_sort_four(long int *ints, int size,
		t_stack **stack1, t_stack **stack2)
{
	int	min;

	ft_sortarr(ints, size);
	min = ints[0];
	while (ft_instack(*stack1, min) && !ft_stacksorted(*stack1))
	{
		if ((*stack1)->nbr == min)
			ft_push(stack1, stack2, 'b');
		else
			ft_reverserotate(stack1, 'a');
	}
	if (!ft_stacksorted(*stack1))
		ft_sort_three(stack1);
	ft_push(stack2, stack1, 'a');
}

static void	ft_pushback(t_stack **stack1, t_stack **stack2, int min)
{
	if ((*stack2)->nbr == min)
	{
		ft_push(stack2, stack1, 'a');
		ft_push(stack2, stack1, 'a');
		ft_rotate(stack1, 'a');
	}
	else
	{
		ft_push(stack2, stack1, 'a');
		ft_rotate(stack1, 'a');
		ft_push(stack2, stack1, 'a');
	}
}

void	ft_sort_five(long int *ints, int size,
		t_stack **stack1, t_stack **stack2)
{
	int	min;
	int	max;

	ft_sortarr(ints, size);
	min = ints[0];
	max = ints[4];
	while (ft_instack(*stack1, min) || ft_instack(*stack1, max))
	{
		if ((*stack1)->nbr == min || (*stack1)->nbr == max)
			ft_push(stack1, stack2, 'b');
		else
			ft_reverserotate(stack1, 'a');
	}
	if (!ft_stacksorted(*stack1))
		ft_sort_three(stack1);
	ft_pushback(stack1, stack2, min);
}
