/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:44 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/17 13:58:24 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

typedef struct s_stack_node
{
	int					number;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}				t_stack_node;

//				error handling
int				check4error(char **argc);

//				loading_numbers
char			**get_elements(int argc, char **argv);
void			free_elements(char **elements);

//				list handling
t_stack_node	*create_node(int nbr);
void			append_to_list(t_stack_node **head, int nbr);
void			convert2list(t_stack_node **head, char **elements);
void			print_list(t_stack_node *head);
int				get_list_len(t_stack_node *head);
void			free_list(t_stack_node **head);

//				operations
void			swap(t_stack_node **head, char which_set);
void			swap_both(t_stack_node **head_a, t_stack_node **head_b);
void			push(t_stack_node **head_to, t_stack_node **head_from,
					char mode);
void			reverse_rotate(t_stack_node **head, char mode);
void			reverse_rotate_both(t_stack_node **head_a,
					t_stack_node **head_b);
void			rotate(t_stack_node **head, char mode);
void			rotate_both(t_stack_node **head_a, t_stack_node **head_b);

//				sorting
void			sort_stack(t_stack_node **head_a, t_stack_node **head_b);
t_stack_node	*get_biggest_node(t_stack_node *head);
t_stack_node	*get_smallest_node(t_stack_node *head);


void	print_both_lists(t_stack_node *head_a, t_stack_node *head_b);
void	print_node_numbers(t_stack_node *node);
void	remove_node(t_stack_node **node);
#endif
