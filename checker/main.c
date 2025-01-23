/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:09:50 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/23 12:30:17 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	char			**elements;
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
	if (get_list_len(head_a) < 2)
		return (0);
	check_operations(&head_a, &head_b);
	is_list_sorted(head_a, head_b);
	free_list(&head_a);
	return (0);
}
