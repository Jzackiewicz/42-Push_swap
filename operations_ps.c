/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:07:39 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/22 18:57:53 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **head, char mode)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = *head;
	second = (*head)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;	
	if (mode == 'a')
		ft_printf("sa\n");
	if (mode == 'b')
		ft_printf("sb\n");
}

void	swap_both(t_stack_node **head_a, t_stack_node **head_b)
{
	swap(head_a, 0);
	swap(head_b, 0);
	ft_printf("ss\n");
}

void	push(t_stack_node **head_to, t_stack_node **head_from, char mode)
{
	t_stack_node	*tmp;

	if (!(*head_from))
		return ;
	tmp = *head_from;
	if ((*head_from)->next)
		(*head_from)->next->prev = NULL;
	(*head_from) = (*head_from)->next;
	if (*head_to)
	{
		(*head_to)->prev = tmp;
		tmp->next = (*head_to);
	}
	else
		tmp->next = NULL;
	*head_to = tmp;
	if (mode == 'a')
		ft_printf("pa\n");
	if (mode == 'b')
		ft_printf("pb\n");
}
