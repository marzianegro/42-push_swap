/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miscUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:03:18 by mnegro            #+#    #+#             */
/*   Updated: 2023/05/14 15:03:19 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_free(void **intptr)
{
	if (*intptr)
		free(*intptr);
	*intptr = NULL;
	return (NULL);
}

void	ft_resetabc(t_stack *stack, int *a, int *b, int *c)
{
	*a = stack->nbr;
	*b = stack->next->nbr;
	*c = stack->next->next->nbr;
}

long int	ft_ps_atoi(const char *nptr)
{
	int				i;
	long int		res;
	int				sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	if (!nptr[i])
		return (FT_ATOI_ERROR);
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (FT_ATOI_ERROR);
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	if (res * sign < INT_MIN || res * sign > INT_MAX)
		return (FT_ATOI_ERROR);
	return (res * sign);
}

void	ft_sortarr(long int *arr, int size)
{
	int			i;
	long int	tmp;

	i = 1;
	while (i < size)
	{
		if (arr[i - 1] > arr[i])
		{
			tmp = arr[i - 1];
			arr[i - 1] = arr[i];
			arr[i] = tmp;
			i = 0;
		}
		i++;
	}
}

void	ft_updatevals(t_stack *stack_a, t_stack *stack_b, t_vals *vals, char c)
{
	if (c == 'a')
	{
		vals->size_a--;
		vals->size_b++;
	}
	else if (c == 'b')
	{
		vals->size_b--;
		vals->size_a++;
	}
	vals->min_a = ft_findmin(stack_a);
	vals->max_a = ft_findmax(stack_a);
	vals->min_b = ft_findmin(stack_b);
	vals->max_b = ft_findmax(stack_b);
	if (c == '0')
		return ;
}
