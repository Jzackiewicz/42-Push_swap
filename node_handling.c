/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:53:13 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/20 13:50:36 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack_node	*get_reverse_target_node(t_stack_node *node, t_stack_node *head_b)
{
	int				dif;
	t_stack_node	*target_node;

	if (!node || !head_b)
		return (NULL);
	target_node = get_smallest_node(head_b);
	dif = INT_MAX;
	while (head_b)
	{
		if ((head_b->number - node->number) > 0 && (head_b->number
				- node->number) < dif)
		{
			dif = head_b->number - node->number;
			target_node = head_b;
		}
		head_b = head_b->next;
	}
	return (target_node);
}
