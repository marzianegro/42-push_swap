/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:05:26 by mnegro            #+#    #+#             */
/*   Updated: 2023/04/21 18:34:52 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_operations(int argc, long int *ints, t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_stacksorted(*stack_a))
		return ;
	else if (argc == 3)
		ft_swap(*stack_a, 'a');
	else if (argc == 4)
		ft_sort_three(stack_a);
	else if (argc == 5)
		ft_sort_four(ints, argc - 1, stack_a, &stack_b);
	else if (argc == 6)
		ft_sort_five(ints, argc - 1, stack_a, &stack_b);
	else
		ft_turk(stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	long int	*ints;
	t_stack		*stack_a;

	ints = ft_checkchecks(&argc, argv);
	if (!ints)
		return (1);
	stack_a = ft_stackcreate(ints, argc - 1);
	ft_operations(argc, ints, &stack_a);
	ft_free((void **)&ints);
	ft_stackfree(&stack_a);
	return (0);
}
