/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:46:50 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/15 09:05:14 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_elements(int argc, char **argv)
{
	char	**elements;
	int		i;
	int		elems_len;

	if (argc == 2)
	{
		i = 0;
		while (argv[0][i] == ' ')
			i++;
		elements = ft_split(&argv[0][i], ' ');
	}
	else
	{
		elems_len = 0;
		while (argv[elems_len])
			elems_len++;
		elements = (char **)ft_calloc(sizeof(char *), (elems_len + 1));
		i = -1;
		while (argv[++i])
			elements[i] = ft_strdup(argv[i]);
	}
	return (elements);
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
