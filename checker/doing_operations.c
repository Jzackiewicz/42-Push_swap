/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doing_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:09:49 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/22 19:15:02 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	do_operation(t_stack_node **head_a, t_stack_node **head_b,
		char *operation)
{
	if (!ft_strncmp(operation, "pa", 3))
		push(head_a, head_b, 0);
	else if (!ft_strncmp(operation, "pb", 3))
		push(head_b, head_a, 0);
	else if (!ft_strncmp(operation, "sa", 3))
		swap(head_a, 0);
	else if (!ft_strncmp(operation, "sb", 3))
		swap(head_b, 0);
	else if (!ft_strncmp(operation, "ss", 3))
		swap_both(head_a, head_b);
	else if (!ft_strncmp(operation, "ra", 3))
		rotate(head_a, 0);
	else if (!ft_strncmp(operation, "rb", 3))
		rotate(head_b, 0);
	else if (!ft_strncmp(operation, "rr", 3))
		rotate_both(head_a, head_b);
	else if (!ft_strncmp(operation, "rra", 3))
		reverse_rotate(head_a, 0);
	else if (!ft_strncmp(operation, "rrb", 3))
		reverse_rotate(head_b, 0);
	else if (!ft_strncmp(operation, "rrr", 3))
		reverse_rotate_both(head_a, head_b);
	else
		return (0);
	return (1);
}
