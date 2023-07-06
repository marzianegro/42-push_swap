/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preChecks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:04:51 by mnegro            #+#    #+#             */
/*   Updated: 2023/04/21 18:35:43 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	*ft_conversion(int argc, char **argv)
{
	int			i;
	int			size;
	long int	*ints;

	i = 1;
	size = argc - 1;
	ints = (long int *)ft_calloc(size, sizeof(long));
	if (!ints)
		return (NULL);
	while (i < argc)
	{
		ints[i - 1] = ft_ps_atoi(argv[i]);
		i++;
	}
	return (ints);
}

long int	ft_check4dups(long int *ints, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ints[i] == ints[j])
			{
				ft_putstr_fd("Error\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

long int	ft_check4limits(long int *ints, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ints[i] == FT_ATOI_ERROR)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

long int	*ft_checkchecks(int *argc, char **argv)
{
	long int	*ints;
	int			size;

	if (*argc == 2 && ft_findspace(argv[1]))
	{
		argv = ft_split(argv[1], ' ');
		*argc = ft_mtxlen(argv) + 1;
		ints = ft_conversion_sa(*argc - 1, argv);
		ft_freematrix(argv);
	}
	else
		ints = ft_conversion(*argc, argv);
	size = *argc - 1;
	if (ft_check4dups(ints, size) == 1)
		return (ft_free((void **)&ints));
	if (ft_check4limits(ints, size) == 1)
		return (ft_free((void **)&ints));
	return (ints);
}
