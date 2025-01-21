/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:53:13 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/21 15:18:19 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_position(t_stack_node *node)
{
	int	pos;

	if (!node)
		return (-1);
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

t_stack_node	*get_target_node(t_stack_node *node, t_stack_node *head)
{
	int				dif;
	t_stack_node	*target_node;

	if (!node || !head)
		return (NULL);
	target_node = get_biggest_node(head);
	dif = INT_MAX;
	while (head)
	{
		if ((node->number - head->number) > 0 && (node->number
				- head->number) < dif)
		{
			dif = node->number - head->number;
			target_node = head;
		}
		head = head->next;
	}
	return (target_node);
}

t_stack_node	*get_reverse_target_node(t_stack_node *node, t_stack_node *head)
{
	int				dif;
	t_stack_node	*target_node;

	if (!node || !head)
		return (NULL);
	target_node = get_smallest_node(head);
	dif = INT_MAX;
	while (head)
	{
		if ((head->number - node->number) > 0 && (head->number
				- node->number) < dif)
		{
			dif = head->number - node->number;
			target_node = head;
		}
		head = head->next;
	}
	return (target_node);
}
