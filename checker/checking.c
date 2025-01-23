/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:42:44 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/23 11:43:00 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_operations(t_stack_node **head_a, t_stack_node **head_b)
{
	char			*line;
	
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		if (!do_operation(head_a, head_b, line))
		{
			free(line);
			write(2, "Error\n", 6);
			exit(1);
		}
		if (line)
			free(line);
	}
}

void	is_list_sorted(t_stack_node *head_a, t_stack_node *head_b)
{
	if (!head_a)
	{
		ft_printf("KO\n");
		return ;
	}
	if (get_list_len(head_b))
	{
		free_list(&head_b);
		ft_printf("KO\n");
		return ;
	}
	while (head_a)
	{
		if(head_a->next)
		{
			if (head_a->number > head_a->next->number)
			{
				ft_printf("KO\n");
				return ;
			}
		}
		head_a = head_a->next;
	}
	ft_printf("OK\n");
}