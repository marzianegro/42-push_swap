/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoMovesBA.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:07:58 by mnegro            #+#    #+#             */
/*   Updated: 2023/05/25 13:07:59 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* All these functions perform a series of operations on the two stacks to
	move a value nbr from one stack to the other. They use stack operations
	to achieve the desired order of elements in the stacks */

int	ft_apply_r_ba(int nbr, t_stack **stack_a, t_stack **stack_b, t_vals *vals)
{
	while ((*stack_b)->nbr != nbr && ft_finddst_ba(nbr, *stack_a, vals) > 0)
		ft_rr(stack_b, stack_a);
	while ((*stack_b)->nbr != nbr)
		ft_rotate(stack_b, 'b');
	while (ft_finddst_ba(nbr, *stack_a, vals) > 0)
		ft_rotate(stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
	ft_updatevals(*stack_a, *stack_b, vals, 'b');
	return (-1);
}

int	ft_apply_rr_ba(int nbr, t_stack **stack_a, t_stack **stack_b, t_vals *vals)
{
	while ((*stack_b)->nbr != nbr && ft_finddst_ba(nbr, *stack_a, vals) > 0)
		ft_rrr(stack_b, stack_a);
	while ((*stack_b)->nbr != nbr)
		ft_reverserotate(stack_b, 'b');
	while (ft_finddst_ba(nbr, *stack_a, vals) > 0)
		ft_reverserotate(stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
	ft_updatevals(*stack_a, *stack_b, vals, 'b');
	return (-1);
}

int	ft_apply_rrarb_ba(int nbr, t_stack **stack_a,
	t_stack **stack_b, t_vals *vals)
{
	while ((*stack_b)->nbr != nbr)
		ft_rotate(stack_b, 'b');
	while (ft_finddst_ba(nbr, *stack_a, vals) > 0)
		ft_reverserotate(stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
	ft_updatevals(*stack_a, *stack_b, vals, 'b');
	return (-1);
}

int	ft_apply_rrbra_ba(int nbr, t_stack **stack_a,
	t_stack **stack_b, t_vals *vals)
{
	while ((*stack_b)->nbr != nbr)
		ft_reverserotate(stack_b, 'b');
	while (ft_finddst_ba(nbr, *stack_a, vals) > 0)
		ft_rotate(stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
	ft_updatevals(*stack_a, *stack_b, vals, 'b');
	return (-1);
}
