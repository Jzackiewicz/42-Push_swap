/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:48:44 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/21 15:18:23 by jzackiew         ###   ########.fr       */
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

//				utils
unsigned int	ft_abs(int value);
int				ft_strlen_2d(char **str);
void			free_all_variants(char ***array);
void			free_list(t_stack_node **head);

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
t_stack_node	*get_reverse_target_node(t_stack_node *node, t_stack_node *head_b);

//				choosing_moves_1
int				*get_node_distances(t_stack_node *node);
int				*get_best_distances(int *distance_a, int *distance_b);
int				get_moves_count(int distance_a, int distance_b);
char			***get_all_variants(t_stack_node *head_a, t_stack_node *head_b);

//				choosing_moves_2
char			*get_move(int *distance_a, int *distance_b, char mode);
char			**get_moves(t_stack_node *node_a, t_stack_node *node_b, char mode);
char			**get_fewest_moves(char ***moves_variants);

//				doing_operations
void			do_operations(t_stack_node **head_a, t_stack_node **head_b,
					char **moves);

//				sorting
void			sort_stack(t_stack_node **head_a, t_stack_node **head_b);
void			sort_three(t_stack_node **head);
void			sort_two(t_stack_node **head);

#endif
