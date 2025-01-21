/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:44:04 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/21 17:38:28 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check4duplicates(char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (ft_atoi(numbers[i]) == ft_atoi(numbers[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check4overflow(char *nbr)
{
	char	*str_int_limit;
	int		int_limit_strlen;
	int		nbr_strlen;

	int_limit_strlen = 10;
	nbr_strlen = ft_strlen(nbr);
	if (nbr[0] == '+' || nbr[0] == '-')
		nbr_strlen--;
	if (nbr_strlen > int_limit_strlen)
		return (1);
	else if (nbr_strlen == int_limit_strlen)
	{
		if (nbr[0] == '-')
			str_int_limit = ft_itoa(INT_MIN);
		else
			str_int_limit = ft_itoa(INT_MAX);
		if (ft_strncmp(nbr, str_int_limit, int_limit_strlen) > 0)
			return (free(str_int_limit), 1);
		free(str_int_limit);
	}
	return (0);
}

static int	check4nondigits(char *nbr)
{
	size_t	i;

	i = 0;
	if ((nbr[i] == '-' || nbr[i] == '+'))
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check4error(char **elements)
{
	int	i;

	i = 0;
	while (elements[i])
	{
		if (check4nondigits(elements[i]))
			return (1);
		if (check4overflow(elements[i]))
			return (1);
		i++;
	}
	if (check4duplicates(elements))
		return (1);
	return (0);
}

int	error_exit(char **elements)
{
	if (check4error(elements))
	{
		write(2, "Error\n", 6);
		free_elements(elements);
		return (-1);
	}
	return (0);
}
