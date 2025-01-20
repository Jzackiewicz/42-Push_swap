/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:01:18 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/20 18:11:47 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_both_lists(t_stack_node *head_a, t_stack_node *head_b)
{
	ft_printf("A stack:\n");
	print_list(head_a);
	ft_printf("B stack:\n");
	print_list(head_b);
}

int	main(int argc, char **argv)
{
	char			**elements;
	t_stack_node	*head_a;
	t_stack_node	*head_b;
	int 			list_len;
	
	if (argc < 2)
		return (0);
	elements = get_elements(argc, &argv[1]);
	if (check4error(elements))
	{
		write(2, "Error\n", 6);
		free_elements(elements);
		return (-1);
	}
	head_a = NULL;
	head_b = NULL;
	convert2list(&head_a, elements);
	//free_elements(elements);
	list_len = get_list_len(head_a);
	if (list_len < 4)
	{
		if (list_len == 3)
			sort_three(&head_a);
		else if (list_len == 2)
			sort_two(&head_a);
		free_list(&head_a);
		free_list(&head_b);
		return (0);
	}
	sort_stack(&head_a, &head_b);
    print_both_lists(head_a, head_b);
	free_list(&head_a);
	free_list(&head_b);
	return (0);
}

// ./push_swap -2 1 923 2 -1 3
