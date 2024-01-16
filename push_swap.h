/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarameixoeiro <sarameixoeiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:20:13 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/16 09:57:53 by sarameixoei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				target;
	int				fpos;
	int				moves_a;
	int				moves_b;
	struct s_stack	*next;
	struct s_stack	*past;
}	t_stack;

//CHECKER
void	ft_error(char *str);
void	ft_isnum(char *str);
t_stack	*ft_check(int argc, char **argv);
int		ft_issorted(t_stack **a);
t_stack	*ft_create_node(char *str);
void	ft_print_lst(t_stack **stack);
int		ft_lst_size(t_stack **stack);
void	ft_push_tob(t_stack **a, t_stack **b);
int		ft_value(int nbr);

//MOVMENTS
void	ft_swap(t_stack **stack, char c);
void	ft_swap_ab(t_stack **a, t_stack **b);
void	ft_push(t_stack **push, t_stack **dst, char c);
void	ft_push_tob(t_stack **a, t_stack **b);
void	ft_rotate(t_stack **stack, char c);
void	ft_r_rotate(t_stack **a, t_stack **b);
void	ft_reverse_rotate(t_stack **stack, char c);
void	ft_rr_rotate(t_stack **a, t_stack **b);

//ALGO
void	ft_sort(t_stack **a, t_stack **b);
void	ft_sort3(t_stack **stack);
void	ft_get_index(t_stack **stack);
void	ft_set_target(t_stack **a, t_stack **b);

#endif