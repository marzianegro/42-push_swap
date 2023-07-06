/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackOps1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:03:39 by mnegro            #+#    #+#             */
/*   Updated: 2023/07/06 16:53:01 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int nbr)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->nbr = nbr;
	newnode->next = NULL;
	return (newnode);
}

void	ft_stackaddback(t_stack **stack, t_stack *newnode)
{
	t_stack	*lastnode;

	if (!*stack)
	{
		*stack = newnode;
		return ;
	}
	lastnode = *stack;
	while (lastnode->next)
		lastnode = lastnode->next;
	lastnode->next = newnode;
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_stackcreate(long int *intptr, int size)
{
	t_stack	*stack;
	t_stack	*newnode;
	int		i;

	i = 0;
	stack = NULL;
	while (i < size)
	{
		newnode = ft_stacknew(intptr[i]);
		ft_stackaddback(&stack, newnode);
		i++;
	}
	return (stack);
}

void	ft_stackfree(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
