/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:51:56 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/17 18:51:53 by jzackiew         ###   ########.fr       */
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

int	get_node_position(t_stack_node *node)
{
	int	pos;

	pos = 0;
	while (node->prev)
	{
		pos++;
		node = node->prev;
	}
	return (pos);
}

t_stack_node	*get_biggest_node(t_stack_node *head)
{
	t_stack_node	*biggest_node;

	if (!head)
		return (NULL);
	biggest_node = head;
	while (head)
	{
		if (head->number > biggest_node->number)
			biggest_node = head;
		head = head->next;
	}
	return (biggest_node);
}

t_stack_node	*get_smallest_node(t_stack_node *head)
{
	t_stack_node	*smallest_node;

	if (!head)
		return (NULL);
	smallest_node = head;
	while (head)
	{
		if (head->number < smallest_node->number)

			smallest_node = head;
		head = head->next;
	}
	return (smallest_node);
}

t_stack_node	*get_target_node(t_stack_node *node, t_stack_node *head_b)
{
	int				dif;
	t_stack_node	*target_node;

	if (!node || !head_b)
		return (NULL);
	target_node = get_biggest_node(head_b);
	dif = INT_MAX;
	while (head_b)
	{
		if ((node->number - head_b->number) > 0 && (node->number
				- head_b->number) < dif)
		{
			dif = node->number - head_b->number;
			target_node = head_b;
		}
		head_b = head_b->next;
	}
	return (target_node);
}

int	*get_node_distances(t_stack_node *node)
{
	int	pos;
    int list_len;
	int	*distances;

    list_len = get_list_len(node);
	pos = get_node_position(node);
	distances = (int *) malloc(2 * sizeof(int));
	if (!distances)
		return (NULL);
	distances[0] = pos;
	distances[1] = pos - list_len;
	return (distances);
}

int calculate_size(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (ft_abs(a) > ft_abs(b))
			return ft_abs(a);
		else
			return ft_abs(b);
	}
	else
		return ft_abs(a) + ft_abs(b);
}

int *get_best_distances(int *distance_a, int *distance_b)
{
	int *distances;
	int size;
	int i;
	int j;

	size = INT_MAX;
	distances = malloc(2 * sizeof(int));
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			if(calculate_size(distance_a[i], distance_b[j]) < size)
			{
				size = calculate_size(distance_a[i], distance_b[j]);
				distances[0] = distance_a[i];
				distances[1] = distance_b[j];
			}
			j++;
		}
		i++;
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
	else if (distance_a * distance_b >= 0 && distance_a >= distance_b)
		i = ft_abs(distance_a) + 1;
	else if (distance_a * distance_b >= 0 && distance_b >= distance_a)
		i = ft_abs(distance_b) + 1;
	return (i);
}

void	do_operation(t_stack_node **head_a, t_stack_node **head_b,
		char *operation)
{
	if (!ft_strncmp(operation, "pa", 3))
		push(head_a, head_b, 'a');
	else if (!ft_strncmp(operation, "pb", 3))
		push(head_b, head_a, 'b');
	else if (!ft_strncmp(operation, "sa", 3))
		swap(head_a, 'a');
	else if (!ft_strncmp(operation, "sb", 3))
		swap(head_b, 'b');
	else if (!ft_strncmp(operation, "ss", 3))
		swap_both(head_a, head_b);
	else if (!ft_strncmp(operation, "ra", 3))
		rotate(head_a, 'a');
	else if (!ft_strncmp(operation, "rb", 3))
		rotate(head_b, 'b');
	else if (!ft_strncmp(operation, "rr", 3))
		rotate_both(head_a, head_b);
	else if (!ft_strncmp(operation, "rra", 3))
		reverse_rotate(head_a, 'a');
	else if (!ft_strncmp(operation, "rrb", 3))
		reverse_rotate(head_b, 'b');
	else if (!ft_strncmp(operation, "rrr", 3))
		reverse_rotate_both(head_a, head_b);
}

int		get_2d_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
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

char	*get_move(int *distance_a, int *distance_b)
{
	if (*distance_a == 0 && *distance_b == 0)
		return("pb");
	if (*distance_a < 0 && *distance_b < 0)
		return((*distance_a)++, (*distance_b)++, "rrr");
	if (*distance_a > 0 && *distance_b > 0)
		return((*distance_a)--, (*distance_b)--, "rr");
	if (*distance_a < 0)
		return((*distance_a)++, "rra");
	if (*distance_b < 0)
		return((*distance_b)++, "rrb");
	if (*distance_a > 0)
		return((*distance_a)--, "ra");
	if (*distance_b > 0)
		return((*distance_b)--, "rb");
	return (NULL);
}

char	**get_moves(t_stack_node *node_a, t_stack_node *node_b)
{
	int		moves_len;
	int		i;
	char	**moves;
	int		distance_a;
	int		distance_b;

	i = 0;
//	distance_a = get_node_distance(node_a, node_b);
//	distance_b = get_node_distance(node_b, node_a);
	distance_a = get_best_distances(get_node_distances(node_a), get_node_distances(node_b))[0];
	distance_b = get_best_distances(get_node_distances(node_a), get_node_distances(node_b))[1];
	moves_len = get_moves_count(distance_a, distance_b);
	moves = (char **)ft_calloc(sizeof(char *), (moves_len + 1));
	while (i < moves_len)
	{
		moves[i] = get_move(&distance_a, &distance_b);
		i++;
	}
	return (moves);
}

char	***get_all_variants(t_stack_node *head_a, t_stack_node *head_b)
{
	t_stack_node	*tmp;
	char			***moves_variants;
	int				list_len;
	int				i;
	
	list_len = get_list_len(head_a);
	moves_variants = (char ***)ft_calloc(sizeof(char **), list_len + 1);
	i = 0;

	while (head_a)
	{
		tmp = get_target_node(head_a, head_b);
		moves_variants[i++] = get_moves(head_a, tmp);
		head_a = head_a->next;
	}
	return (moves_variants);
}

void	free_3d_array(char ***array)
{
	int	i;
	int j;

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

char	**get_fewest_moves(t_stack_node *head_a, t_stack_node *head_b)
{
	char			***moves_variants;
	char			**best_variant;
	int				i;
	int				num_of_moves;
	
	i = 0;
	moves_variants = get_all_variants(head_a, head_b);
	num_of_moves = get_2d_strlen(moves_variants[i]);
	best_variant = moves_variants[i];
	while (moves_variants[i])
	{
		if (get_2d_strlen(moves_variants[i]) < num_of_moves)
		{
			num_of_moves = get_2d_strlen(moves_variants[i]);
			best_variant = moves_variants[i];
		}
		i++;
	}

	//free_3d_array(moves_variants);
	return (best_variant);
}

void	do_operations(t_stack_node **head_a, t_stack_node **head_b, char **moves)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		do_operation(head_a, head_b, moves[i]);
		i++;
	}
}

void	print_node_numbers(t_stack_node *node)
{
	if (node->prev)
		ft_printf("prev: %d | ", node->prev->number);
	else
		ft_printf("prev: NONE | ");
	ft_printf("curr: %d | ", node->number);
	if (node->next)
		ft_printf("next: %d", node->next->number);
	else
		ft_printf("next: NONE");
	ft_printf("\n");
}

void	sort_three(t_stack_node **head)
{
	t_stack_node *smallest_node;
	t_stack_node *biggest_node;

	smallest_node = get_smallest_node(*head);
	biggest_node = get_biggest_node(*head);
	if (get_node_position(biggest_node) == 1)
	{
		reverse_rotate(head, 'a');
		if (get_node_position(smallest_node) == 1)
			swap(head, 'a');
	}
	else if (get_node_position(biggest_node) == 0)
	{
		rotate(head, 'a');
		if(get_node_position(smallest_node) == 1)
			swap(head, 'a');
	}
	else if (get_node_position(smallest_node) == 1)
		swap(head, 'a');
}

void	sort_two(t_stack_node **head)
{
	if ((*head)->number > (*head)->next->number)
		rotate(head, 'a');
}

void	sort_stack(t_stack_node **head_a, t_stack_node **head_b)
{
	char            **best_variant;
	//t_stack_node 	tmp;

    while (*head_a)
	{
		if (get_list_len(*head_a) == 3)
		{
			sort_three(head_a);
			break ;
		}
		if (get_list_len(*head_b) < 2)
			push(head_b, head_a, 'b');
		else
		{
			best_variant = get_fewest_moves(*head_a, *head_b);
			do_operations(head_a, head_b, best_variant);
		}
	}
//	ft_printf("-------------------\n");
//	while (*head_b)
//	{
//		tmp = get_target_node(*head_b, *head_a);
//		while (*head_a != tmp)
//
//		do_operations(head_b, head_a, best_variant);
//	}
}