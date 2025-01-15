/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:51:56 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/15 11:54:04 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_position(t_stack_node *head, t_stack_node *node)
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
}

t_stack_node	*get_biggest_node(t_stack_node *head)
{
	t_stack_node	*biggest_node;
	int				biggest_number;
	
	if (!head)
		return (NULL);
	biggest_number = INT_MIN;
	while(head)
	{
		if (head->number > biggest_number)
		{
			biggest_number = head->number;
			biggest_node = head;
		}
		head = head->next;
	}
	return (biggest_node);
}

void	sort_stack(t_stack_node **head_a, t_stack_node **head_b)
{
	t_stack_node	*tmp;
	
	while (get_list_len(*head_b) < 2)
		push(head_b, head_a, 'b');
	tmp = get_biggest_node(*head_b);
	ft_printf("Biggest in B: %d\n", tmp->number);
	tmp = get_biggest_node(*head_a);
	ft_printf("Biggest in A: %d\n", tmp->number);
}
