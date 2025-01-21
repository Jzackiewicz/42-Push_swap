/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choosing_moves_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:58:49 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/21 17:32:30 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_size(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (ft_abs(a) > ft_abs(b))
			return (ft_abs(a));
		else
			return (ft_abs(b));
	}
	else
		return (ft_abs(a) + ft_abs(b));
}

int	*get_best_distances(int *distance_a, int *distance_b)
{
	int	*distances;
	int	size;
	int	i;
	int	j;

	size = INT_MAX;
	distances = malloc(2 * sizeof(int));
	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			if (calculate_size(distance_a[i], distance_b[j]) < size)
			{
				size = calculate_size(distance_a[i], distance_b[j]);
				distances[0] = distance_a[i];
				distances[1] = distance_b[j];
			}
		}
	}
	free(distance_a);
	free(distance_b);
	return (distances);
}

int	get_moves_count(int distance_a, int distance_b)
{
	unsigned int	i;

	i = 0;
	if (distance_a * distance_b <= 0)
		i = ft_abs(distance_a) + ft_abs(distance_b) + 1;
	else if (distance_a * distance_b >= 0 && ft_abs(distance_a)
		>= ft_abs(distance_b))
		i = ft_abs(distance_a) + 1;
	else if (distance_a * distance_b >= 0 && ft_abs(distance_b)
		>= ft_abs(distance_a))
		i = ft_abs(distance_b) + 1;
	return (i);
}

int	*get_node_distances(t_stack_node *node)
{
	int	pos;
	int	list_len;
	int	*distances;

	list_len = get_list_len(node);
	pos = get_node_position(node);
	distances = (int *)malloc(2 * sizeof(int));
	if (!distances)
		return (NULL);
	distances[0] = pos;
	distances[1] = pos - list_len;
	return (distances);
}
