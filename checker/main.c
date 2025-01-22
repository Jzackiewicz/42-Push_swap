/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:09:50 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/22 19:22:40 by jzackiew         ###   ########.fr       */
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
		//ft_printf("line: %s", line);
		line = ft_split(line, '\n')[0];
		line = ft_split(line, 0)[0];
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

void	print_list(t_stack_node *head)
{
	while (head)
	{
		printf("nbr: %d\n", head->number);
		head = head->next;
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
				print_list(head_a);
				ft_printf("KO\n");
				return ;
			}
		}
		head_a = head_a->next;
	}
	ft_printf("OK\n");
}

int	main(int argc, char **argv)
{
	char			**elements;
	//char			**operations;
	t_stack_node	*head_a;
	t_stack_node	*head_b;

	if (argc < 2)
		return (0);
	elements = get_elements(argc, &argv[1]);
	if (error_exit(elements))
		return (-1);
	head_a = NULL;
	head_b = NULL;
	convert2list(&head_a, elements);
	if (get_list_len(head_a) == 1)
		return (0);
	check_operations(&head_a, &head_b);
	is_list_sorted(head_a, head_b);
	free_list(&head_a);
	return (0);
}