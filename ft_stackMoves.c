/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackMoves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:21:51 by mnegro            #+#    #+#             */
/*   Updated: 2023/04/21 18:34:12 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first 2 elements at the top of stack a/b */
void	ft_swap(t_stack *stack, char c)
{
	int	tmp;

	if (!stack)
		return ;
	tmp = stack->nbr;
	stack->nbr = stack->next->nbr;
	stack->next->nbr = tmp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
	else if (c == '0')
		return ;
}

/* Take the first element at the top of b/a
	and put it at the top of a/b */
void	ft_push(t_stack **stackfrom, t_stack **stackto, char c)
{
	t_stack	*tmp;

	if (!*stackfrom)
		return ;
	tmp = *stackto;
	*stackto = *stackfrom;
	*stackfrom = (*stackfrom)->next;
	(*stackto)->next = tmp;
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("pb\n", 1);
	else if (c == '0')
		return ;
}

/* Shift up all elements of stack a/b by 1 */
void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*lastnode;

	if (!*stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	lastnode = ft_stacklast(*stack);
	lastnode->next = tmp;
	tmp->next = NULL;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
	else if (c == '0')
		return ;
}

/* Shift down all elements of stack a/b by 1 */
void	ft_reverserotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*lastnode;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	lastnode = ft_stacklast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	(*stack)->next = NULL;
	lastnode->next = tmp;
	*stack = lastnode;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
	else if (c == '0')
		return ;
}
