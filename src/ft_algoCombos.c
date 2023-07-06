/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoCalcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:04:34 by mnegro            #+#    #+#             */
/*   Updated: 2023/05/14 15:04:35 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function iterates through each element in stack_a and calculates
	the minimum number of operations required to bring each element from
	stack_a to stack_b using different rotation methods, and returns the
	overall minimum number of operations among all elements in stack_a */
int	ft_combo_ab(int nbr, t_stack *stack_a, t_stack *stack_b, t_vals *vals)
{
	t_stack	*tmp;
	int		best;

	tmp = stack_a;
	best = ft_ops_rr_ab(nbr, stack_a, stack_b, vals);
	while (tmp)
	{
		if (best > ft_ops_r_ab(tmp->nbr, stack_a, stack_b, vals))
			best = ft_ops_r_ab(tmp->nbr, stack_a, stack_b, vals);
		if (best > ft_ops_rr_ab(tmp->nbr, stack_a, stack_b, vals))
			best = ft_ops_rr_ab(tmp->nbr, stack_a, stack_b, vals);
		if (best > ft_ops_rrbra_ab(tmp->nbr, stack_a, stack_b, vals))
			best = ft_ops_rrbra_ab(tmp->nbr, stack_a, stack_b, vals);
		if (best > ft_ops_rrarb_ab(tmp->nbr, stack_a, stack_b, vals))
			best = ft_ops_rrarb_ab(tmp->nbr, stack_a, stack_b, vals);
		tmp = tmp->next;
	}
	return (best);
}

/* This function iterates through each element in stack_b and calculates
	the minimum number of operations required to bring each element from
	stack_b to stack_a using different rotation methods, and returns the
	overall minimum number of operations among all elements in stack_b */
int	ft_combo_ba(int nbr, t_stack *stack_b, t_stack *stack_a, t_vals *vals)
{
	t_stack	*tmp;
	int		best;

	tmp = stack_b;
	best = ft_ops_rr_ba(nbr, stack_a, stack_b, vals);
	while (tmp)
	{
		if (best > ft_ops_r_ba(nbr, stack_a, stack_b, vals))
			best = ft_ops_r_ba(nbr, stack_a, stack_b, vals);
		if (best > ft_ops_rr_ba(nbr, stack_a, stack_b, vals))
			best = ft_ops_rr_ba(nbr, stack_a, stack_b, vals);
		if (best > ft_ops_rrbra_ba(nbr, stack_a, stack_b, vals))
			best = ft_ops_rrbra_ba(nbr, stack_a, stack_b, vals);
		if (best > ft_ops_rrarb_ba(nbr, stack_a, stack_b, vals))
			best = ft_ops_rrarb_ba(nbr, stack_a, stack_b, vals);
		tmp = tmp->next;
	}
	return (best);
}
