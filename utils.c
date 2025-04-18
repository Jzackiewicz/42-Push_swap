/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:55:12 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/21 17:34:44 by jzackiew         ###   ########.fr       */
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

int	ft_strlen_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_elements(char **elements)
{
	int	i;

	i = 0;
	while (elements[i])
	{
		free(elements[i]);
		i++;
	}
	free(elements);
}

void	free_all_variants(char ***array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free (array);
}

void	free_list(t_stack_node **head)
{
	t_stack_node	*tmp;

	while ((*head)->prev)
		*head = (*head)->prev;
	while (*head)
	{
		tmp = (*head)->next;
		free (*head);
		*head = tmp;
	}
	*head = NULL;
}
