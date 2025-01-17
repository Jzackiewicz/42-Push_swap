/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:51:56 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/20 12:52:04 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **head)
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
	else if (get_node_position(biggest_node) == 0)
	{
		rotate(head, 'a');
		if (get_node_position(smallest_node) == 1)
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
	char			**best_variant;
	//t_stack_node	*tmp;

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
	// while (*head_b)
	// {
	// 	tmp = get_target_node(*head_b, *head_a);
	// 	while (*head_a != tmp)
	// 	{
	// 		if (get_node_position(tmp) / 2 > get_list_len(*head_a))
	// 			reverse_rotate(head_a, 'a');
	// 		else
	// 			rotate(head_a, 'a');
	// 	}
	// 	push(head_a, head_b, 'a');
	// }
}
