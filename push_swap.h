/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:44 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/29 08:44:11 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack_node
{
	int					number;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}				t_stack_node;

//				utils
unsigned int	ft_abs(int value);
int				ft_strlen_2d(char **str);
void			free_elements(char **elements);
void			free_all_variants(char ***array);
void			free_list(t_stack_node **head);

//				error handling
int				check4error(char **argc);
int				error_exit(char **elements);

//				parsing_numbers
char			**get_elements(int argc, char **argv);

//				list handling
void			convert2list(t_stack_node **head, char **elements);
int				get_list_len(t_stack_node *head);
int				is_list_sorted(t_stack_node *head);

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

//				node_handling
int				get_node_position(t_stack_node *node);
t_stack_node	*get_biggest_node(t_stack_node *head);
t_stack_node	*get_smallest_node(t_stack_node *head);
t_stack_node	*get_target_node(t_stack_node *node, t_stack_node *head_b);
t_stack_node	*get_reverse_target_node(t_stack_node *node,
					t_stack_node *head_b);

//				choosing_moves_1
int				*get_node_distances(t_stack_node *node);
int				*get_best_distances(int *distance_a, int *distance_b);
int				get_moves_count(int distance_a, int distance_b);

//				choosing_moves_2
char			***get_all_variants(t_stack_node *head_a, t_stack_node *head_b);
char			**get_moves(t_stack_node *node_a, t_stack_node *node_b,
					char mode);
char			**get_fewest_moves(char ***moves_variants);

//				doing_operations
void			do_operations(t_stack_node **head_a, t_stack_node **head_b,
					char **moves);

//				sorting
void			sort_stack(t_stack_node **head_a, t_stack_node **head_b);

#endif
