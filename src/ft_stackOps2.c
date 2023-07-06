/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackOps2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:03:46 by mnegro            #+#    #+#             */
/*   Updated: 2023/05/14 15:03:47 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackprint(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->nbr);
		stack = stack->next;
	}
}

int	ft_stacksorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->nbr < stack->next->nbr)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int	ft_instack(t_stack *stack, int val)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->nbr == val)
			return (1);
		else
			stack = stack->next;
	}
	return (0);
}

int	ft_stacksize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
