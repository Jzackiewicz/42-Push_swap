/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzackiew <jzackiew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:09:57 by jzackiew          #+#    #+#             */
/*   Updated: 2025/01/22 17:39:14 by jzackiew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"

typedef struct s_stack_node
{
	int					number;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}				t_stack_node;

//				utils
void	free_elements(char **elements);
int		ft_strlen_2d(char **str);
void	free_list(t_stack_node **head);

//				error_handling
int		error_exit(char **elements);

//			parsing_numbers
char	**get_elements(int argc, char **argv);

//			list_handling
void	convert2list(t_stack_node **head, char **elements);
int		get_list_len(t_stack_node *node);

//			doing_operations
int		do_operation(t_stack_node **head_a, t_stack_node **head_b,
		char *operation);

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

#endif