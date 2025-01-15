/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:51:56 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/15 13:22:43 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	get_node_position(t_stack_node *head, t_stack_node *node)
{
	int pos;

	if (!head)
		return (-1);
	pos = 0;
	while(head)
	{
		if (head == node)
			return (pos);
		pos++;
		head = head->next;
	}
} */

t_stack_node	*get_biggest_node(t_stack_node *head)
{
	t_stack_node	*biggest_node;
	int				biggest_number;
	
	if (!head)
		return (NULL);
	biggest_number = INT_MIN;
	while(head)
	{
		if (head->number >= biggest_number)
		{
			biggest_number = head->number;
			biggest_node = head;
		}
		head = head->next;
	}
	return (biggest_node);
}

t_stack_node	*get_smallest_node(t_stack_node *head)
{
	t_stack_node	*smallest_node;
	int				smallest_number;
	
	if (!head)
		return (NULL);
	smallest_number = INT_MIN;
	while(head)
	{
		if (head->number <= smallest_number)
		{
			smallest_number = head->number;
			smallest_node = head;
		}
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
	if (node->number > target_node->number)
		return (target_node);
	dif = INT_MAX;
	while (head_b)
	{
		if ((node->number - head_b->number) > 0 && (node->number - head_b->number) < dif)
		{
			dif = node->number - head_b->number;
			target_node = head_b;
		}
		head_b = head_b->next;
	}
	return(target_node);
}

void	sort_stack(t_stack_node **head_a, t_stack_node **head_b)
{
	t_stack_node	*tmp;
	
	while (get_list_len(*head_b) < 5)
		push(head_b, head_a, 'b');
	tmp = get_target_node(*head_a, *head_b);

}
