/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:55:12 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/20 11:17:42 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_abs(int value)
{
	unsigned int	abs_value;
	int				sign;

	sign = 1;
	abs_value = (unsigned int)value;
	if (value < 0)
		sign *= -1;
	return (abs_value * sign);
}

void	ft_printf_2d_array(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_printf("[%d]: %s | ", i, str[i]);
		i++;
	}
	ft_printf("\n");
}

void	free_3d_array(char ***array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			free(array[i][j]);
			j++;
		}
		i++;
	}
	free(array);
}
