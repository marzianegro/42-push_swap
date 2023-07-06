/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoMovesAB.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:13:46 by mnegro            #+#    #+#             */
/*   Updated: 2023/05/14 15:02:53 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* All these functions perform a series of operations on the two stacks to
	move a value nbr from one stack to the other. They use stack operations
	to achieve the desired order of elements in the stacks */

int	ft_apply_r_ab(int nbr, t_stack **stack_a, t_stack **stack_b, t_vals *vals)
{
	while ((*stack_a)->nbr != nbr && ft_finddst_ab(nbr, *stack_b, vals) > 0)
		ft_rr(stack_a, stack_b);
	while ((*stack_a)->nbr != nbr)
		ft_rotate(stack_a, 'a');
	while (ft_finddst_ab(nbr, *stack_b, vals) > 0)
		ft_rotate(stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	ft_updatevals(*stack_a, *stack_b, vals, 'a');
	return (-1);
}

int	ft_apply_rr_ab(int nbr, t_stack **stack_a, t_stack **stack_b, t_vals *vals)
{
	if (ft_finddst_ab(nbr, *stack_b, vals) < 0)
		return (0);
	while ((*stack_a)->nbr != nbr && ft_finddst_ab(nbr, *stack_b, vals) > 0)
		ft_rrr(stack_a, stack_b);
	while ((*stack_a)->nbr != nbr)
		ft_reverserotate(stack_a, 'a');
	while (ft_finddst_ab(nbr, *stack_b, vals) > 0)
		ft_reverserotate(stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	ft_updatevals(*stack_a, *stack_b, vals, 'a');
	return (-1);
}

int	ft_apply_rrarb_ab(int nbr, t_stack **stack_a,
	t_stack **stack_b, t_vals *vals)
{
	while ((*stack_a)->nbr != nbr)
		ft_reverserotate(stack_a, 'a');
	while (ft_finddst_ab(nbr, *stack_b, vals) > 0)
		ft_rotate(stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	ft_updatevals(*stack_a, *stack_b, vals, 'a');
	return (-1);
}

int	ft_apply_rrbra_ab(int nbr, t_stack **stack_a,
	t_stack **stack_b, t_vals *vals)
{
	while ((*stack_a)->nbr != nbr)
		ft_rotate(stack_a, 'a');
	while (ft_finddst_ab(nbr, *stack_b, vals) > 0)
		ft_reverserotate(stack_b, 'b');
	ft_push(stack_a, stack_b, 'b');
	ft_updatevals(*stack_a, *stack_b, vals, 'a');
	return (-1);
}
