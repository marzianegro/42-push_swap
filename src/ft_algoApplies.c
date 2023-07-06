/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algoSorts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:05:59 by mnegro            #+#    #+#             */
/*   Updated: 2023/05/14 16:06:01 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* These functions determine the appropriate combo operation based on
	comparisons between 'best' and the results of different operation functions.
	They then apply the corresponding operation using the ft_apply_*
	functions to modify stack_a and stack_b accordingly. */

void	ft_apply_combo_ab(int nbr, t_stack **stack_a,
	t_stack **stack_b, t_vals *vals)
{
	t_stack	*tmp;
	int		best;

	tmp = *stack_a;
	best = ft_combo_ab(nbr, *stack_a, *stack_b, vals);
	while (tmp)
	{
		if (best == ft_ops_r_ab(tmp->nbr, *stack_a, *stack_b, vals))
			ft_apply_r_ab(tmp->nbr, stack_a, stack_b, vals);
		else if (best == ft_ops_rr_ab(tmp->nbr, *stack_a, *stack_b, vals))
			ft_apply_rr_ab(tmp->nbr, stack_a, stack_b, vals);
		else if (best == ft_ops_rrarb_ab(tmp->nbr, *stack_a, *stack_b, vals))
			ft_apply_rrarb_ab(tmp->nbr, stack_a, stack_b, vals);
		else if (best == ft_ops_rrbra_ab(tmp->nbr, *stack_a, *stack_b, vals))
			ft_apply_rrbra_ab(tmp->nbr, stack_a, stack_b, vals);
		else
		{
			tmp = tmp->next;
			continue ;
		}
		break ;
	}
}

void	ft_apply_combo_ba(int nbr, t_stack **stack_b,
	t_stack **stack_a, t_vals *vals)
{
	t_stack	*tmp;
	int		best;

	tmp = *stack_b;
	best = ft_combo_ba(nbr, *stack_b, *stack_a, vals);
	while (tmp)
	{
		if (best == ft_ops_r_ba(tmp->nbr, *stack_a, *stack_b, vals))
			ft_apply_r_ba(tmp->nbr, stack_a, stack_b, vals);
		else if (best == ft_ops_rr_ba(tmp->nbr, *stack_a, *stack_b, vals))
			ft_apply_rr_ba(tmp->nbr, stack_a, stack_b, vals);
		else if (best == ft_ops_rrarb_ba(tmp->nbr, *stack_a, *stack_b, vals))
			ft_apply_rrarb_ba(tmp->nbr, stack_a, stack_b, vals);
		else if (best == ft_ops_rrbra_ba(tmp->nbr, *stack_a, *stack_b, vals))
			ft_apply_rrbra_ba(tmp->nbr, stack_a, stack_b, vals);
		else
		{
			tmp = tmp->next;
			continue ;
		}
		break ;
	}
}
