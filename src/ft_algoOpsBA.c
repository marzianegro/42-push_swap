/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoOpsBA.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:43:48 by mnegro            #+#    #+#             */
/*   Updated: 2023/05/13 15:43:49 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function calculates the number of rotations required to bring the
	value nbr to its correct position in the two stacks, and returns the
	minimum number of rotations needed between them */
int	ft_ops_r_ba(int nbr, t_stack *stack_a, t_stack *stack_b, t_vals *vals)
{
	int	ops;

	ops = ft_finddst_ba(nbr, stack_a, vals);
	if (ops < ft_findidx(nbr, stack_b))
		ops = ft_findidx(nbr, stack_b);
	return (ops);
}

/* This function calculates the number of reverse rotations required to
	bring the value nbr to its correct position in the two stacks. It
	compares the number of reverse rotations needed for stack_a and
	stack_b, and returns the minimum number of reverse rotations
	needed between the two stacks */
int	ft_ops_rr_ba(int nbr, t_stack *stack_a, t_stack *stack_b, t_vals *vals)
{
	int	ops;

	ops = 0;
	if (ft_finddst_ba(nbr, stack_a, vals))
		ops = ft_stacksize(stack_a) - ft_finddst_ba(nbr, stack_a, vals);
	if ((ops < (ft_stacksize(stack_a) - ft_findidx(nbr, stack_b)))
		&& ft_findidx(nbr, stack_b))
		ops = ft_stacksize(stack_b) - ft_findidx(nbr, stack_b);
	return (ops);
}

/* This function calculates the total number of reverse rotations for
	stack_a and rotations for stack_b required to bring the value nbr
	to its correct position in the two stacks. It considers the index
	of nbr in stack_a and the position where nbr should be inserted in
	stack_b. By summing up these values, it provides the total number of 
	rotation operations needed for both stacks */
int	ft_ops_rrarb_ba(int nbr, t_stack *stack_a, t_stack *stack_b, t_vals *vals)
{
	int	ops;

	ops = 0;
	if (ft_findidx(nbr, stack_b))
		ops = ft_stacksize(stack_b) - ft_findidx(nbr, stack_b);
	ops = ft_finddst_ba(nbr, stack_a, vals) + ops;
	return (ops);
}

/* This function calculates the total number of reverse rotations for
	stack_b and rotations for stack_a required to bring the value nbr
	to its correct position in the two stacks. It considers the position
	where nbr should be inserted in stack_b and the index of nbr in stack_a.
	By summing up these values, it provides the total number of rotations
	needed for both stacks */
int	ft_ops_rrbra_ba(int nbr, t_stack *stack_a, t_stack *stack_b, t_vals *vals)
{
	int	ops;

	ops = 0;
	if (ft_finddst_ba(nbr, stack_a, vals))
		ops = ft_stacksize(stack_a) - ft_finddst_ba(nbr, stack_a, vals);
	ops = ft_findidx(nbr, stack_b) + ops;
	return (ops);
}
