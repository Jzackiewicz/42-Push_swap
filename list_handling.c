/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:36:41 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/21 17:38:06 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*create_node(int nbr)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	new_node->number = nbr;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

static void	append_to_list(t_stack_node **head, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*tmp;

	new_node = create_node(nbr);
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
}

void	convert2list(t_stack_node **head, char **elements)
{
	int	i;
	int	nbr;

	i = 0;
	while (elements[i])
	{
		nbr = ft_atoi(elements[i]);
		append_to_list(head, nbr);
		i++;
	}
	free_elements(elements);
}

int	get_list_len(t_stack_node *node)
{
	int	len;

	if (!node)
		return (0);
	len = 0;
	while (node->prev)
		node = node->prev;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

int is_list_sorted(t_stack_node *head)
{
    while (head)
    {
        if (head->next)
            if (head->number > head->next->number)
                return (0);
        head = head->next;
    }
    return (1);
}