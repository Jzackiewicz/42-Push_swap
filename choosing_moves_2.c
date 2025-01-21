/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choosing_moves_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:03:59 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/21 14:18:47 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_move(int *distance_a, int *distance_b, char mode)
{
	if (*distance_a == 0 && *distance_b == 0)
	{
		if (mode == 'a')
			return("pa");
		else
			return("pb");	
	}
	else if (*distance_a < 0 && *distance_b < 0)
		return ((*distance_a)++, (*distance_b)++, "rrr");
	else if (*distance_a > 0 && *distance_b > 0)
		return ((*distance_a)--, (*distance_b)--, "rr");
	else if (*distance_a < 0)
		return ((*distance_a)++, "rra");
	else if (*distance_b < 0)
		return ((*distance_b)++, "rrb");
	else if (*distance_a > 0)
		return ((*distance_a)--, "ra");
	else if (*distance_b > 0)
		return ((*distance_b)--, "rb");
	return (NULL);
}

char	**get_moves(t_stack_node *node_a, t_stack_node *node_b, char mode)
{
	int		moves_len;
	int		i;
	char	**moves;
	int		*distances;

	i = 0;
	distances = get_best_distances(get_node_distances(node_a),
			get_node_distances(node_b));
	moves_len = get_moves_count(distances[0], distances[1]);
	moves = (char **)ft_calloc(sizeof(char *), (moves_len + 1));
	while (i < moves_len)
	{
		moves[i] = get_move(&distances[0], &distances[1], mode);
		i++;
	}
	free(distances);
	return (moves);
}

char	**get_fewest_moves(char ***moves_variants)
{
	char	**best_variant;
	int		i;
	int		num_of_moves;

	i = 0;
	num_of_moves = ft_strlen_2d(moves_variants[i]);
	best_variant = moves_variants[i];
	while (moves_variants[i])
	{
		if (ft_strlen_2d(moves_variants[i]) < num_of_moves)
		{
			num_of_moves = ft_strlen_2d(moves_variants[i]);
			best_variant = moves_variants[i];
		}
		i++;
	}
	return (best_variant);
}
