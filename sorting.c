/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:51:56 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/23 11:41:45 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack_node **head)
{
	if ((*head)->number > (*head)->next->number)
		rotate(head, 'a');
}

static void	sort_three(t_stack_node **head)
{
	t_stack_node	*smallest_node;
	t_stack_node	*biggest_node;

	smallest_node = get_smallest_node(*head);
	biggest_node = get_biggest_node(*head);
	if (get_node_position(biggest_node) == 1)
	{
		reverse_rotate(head, 'a');
		if (get_node_position(smallest_node) == 1)
			swap(head, 'a');
	}
	if (get_node_position(biggest_node) == 0)
	{
		rotate(head, 'a');
		if (get_node_position(smallest_node) == 1)
			swap(head, 'a');
	}
	if (get_node_position(smallest_node) == 1)
		swap(head, 'a');
}

static void	initial_sort(t_stack_node **head_a, t_stack_node **head_b)
{
	char			***moves_variants;
	char			**best_variant;

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
			moves_variants = get_all_variants(*head_a, *head_b);
			best_variant = get_fewest_moves(moves_variants);
			do_operations(head_a, head_b, best_variant);
			free_all_variants(moves_variants);
		}
	}
}

static void	push_back(t_stack_node **head_a, t_stack_node **head_b)
{
	t_stack_node	*target;

	if (!(*head_b))
		return ;
	while (*head_b)
	{
		target = get_reverse_target_node(*head_b, *head_a);
		while (get_node_position(target) != 0)
		{
			if (get_node_position(target) > get_list_len(*head_a) / 2)
				reverse_rotate(head_a, 'a');
			else
				rotate(head_a, 'a');
		}
		push(head_a, head_b, 'a');
	}
	while (get_node_position(get_smallest_node(*head_a)) != 0)
	{
		if (get_node_position(get_smallest_node(*head_a))
			> get_list_len(*head_a) / 2)
			reverse_rotate(head_a, 'a');
		else
			rotate(head_a, 'a');
	}
}

void	sort_stack(t_stack_node **head_a, t_stack_node **head_b)
{
	if (get_list_len(*head_a) < 2)
		return ;
	else if (get_list_len(*head_a) == 2)
		sort_two(head_a);
	else
	{
		initial_sort(head_a, head_b);
		push_back(head_a, head_b);
	}
	free_list(head_a);
}
