/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleArgv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnegro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:01:16 by mnegro            #+#    #+#             */
/*   Updated: 2023/05/25 13:01:17 by mnegro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findspace(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_mtxlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

void	ft_freematrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

long int	*ft_conversion_sa(int argc, char **argv)
{
	int			i;
	int			size;
	long int	*ints;

	i = 0;
	size = argc;
	ints = (long int *)ft_calloc(size, sizeof(long));
	if (!ints)
		return (NULL);
	while (i < argc)
	{
		ints[i] = ft_ps_atoi(argv[i]);
		i++;
	}
	return (ints);
}
