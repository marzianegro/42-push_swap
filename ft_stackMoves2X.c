/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackMoves2X.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:03:30 by mnegro            #+#    #+#             */
/*   Updated: 2023/05/14 15:03:31 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa and sb at the same time */
void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a, '0');
	ft_swap(stack_b, '0');
	ft_putstr_fd("ss\n", 1);
}

/* ra and rb at the same time */
void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, '0');
	ft_rotate(stack_b, '0');
	ft_putstr_fd("rr\n", 1);
}

/* rra and rrb at the same time */
void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverserotate(stack_a, '0');
	ft_reverserotate(stack_b, '0');
	ft_putstr_fd("rrr\n", 1);
}
