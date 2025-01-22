/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:01:18 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/22 11:52:07 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	sort_stack(&head_a, &head_b);
	return (0);
}
