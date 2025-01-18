/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:07:56 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/14 15:46:16 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **head, char mode)
{
	t_stack_node	*tmp;

    if (!*head || !(*head)->next)
		return;
	tmp = *head;
	(*head)->next->prev = NULL;
	while ((*head)->next)
		(*head) = (*head)->next;
	tmp->next = NULL;
	tmp->prev = *head;
	(*head)->next = tmp;
	while ((*head)->prev)
		(*head) = (*head)->prev;
	if (mode == 'a')
		ft_printf("ra\n");
	if (mode == 'b')
		ft_printf("rb\n");
}

void	rotate_both(t_stack_node **head_a, t_stack_node **head_b)
{
	rotate(head_a, 0);
	rotate(head_b, 0);
	ft_printf("rr\n");
}

void	reverse_rotate(t_stack_node **head, char mode)
{
	t_stack_node	*tmp;

	while ((*head)->next)
		(*head) = (*head)->next;
	tmp = *head;
	(*head)->prev->next = NULL;
	while ((*head)->prev)
		(*head) = (*head)->prev;
	tmp->prev = NULL;
	tmp->next = *head;
	(*head)->prev = tmp;
	*head = tmp;
	if (mode == 'a')
		ft_printf("rra\n");
	if (mode == 'b')
		ft_printf("rrb\n");
}

void	reverse_rotate_both(t_stack_node **head_a, t_stack_node **head_b)
{
	reverse_rotate(head_a, 0);
	reverse_rotate(head_b, 0);
	ft_printf("rrr\n");
}
