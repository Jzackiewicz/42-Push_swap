/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:01:18 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/15 12:53:14 by jzackiew         ###   ########.fr       */
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
	t_stack_node	*a_head;
	t_stack_node	*b_head;
	
	if (argc < 2)
		return (0);
	elements = get_elements(argc, &argv[1]);
	if (check4error(elements))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	a_head = NULL;
	b_head = NULL;
	convert2list(&a_head, elements);
	// ft_printf("Before sort: \n");
	// print_both_lists(a_head, b_head);
	sort_stack(&a_head, &b_head);
	//ft_printf("After sort: \n");
	print_both_lists(a_head, b_head);
	free_list(&a_head);
	free_list(&b_head);
	return (0);
}
