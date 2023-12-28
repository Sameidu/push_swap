/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:20:13 by smeixoei          #+#    #+#             */
/*   Updated: 2023/12/28 12:40:54 by smeixoei         ###   ########.fr       */
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
	int				content; //number
	int				index; //index of the number
	int				target; //target position
	int				pos; //position of the number
	int				moves_a; //moves to the target
	int				moves_b; //moves to the target
	struct s_stack	*next;
	struct s_stack	*past;
}	t_stack;

//CHECKER
void	ft_error(char *str);
void	ft_isnum(char *str);
t_stack	*ft_check(int argc, char **argv);
void	ft_issorted(t_stack **a);
t_stack	*ft_create_node(char *str);
void	ft_print_lst(t_stack **stack);
int		ft_lst_size(t_stack **stack);
void	ft_push_tob(t_stack **a, t_stack **b);

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
void	ft_get_target(t_stack **a, t_stack **b);

#endif