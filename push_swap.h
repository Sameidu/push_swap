/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:20:13 by smeixoei          #+#    #+#             */
/*   Updated: 2023/11/03 10:08:30 by smeixoei         ###   ########.fr       */
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
	int				index;
	int				content;
	struct s_stack	*next;
	struct s_stack	*past;
}	t_stack;

//CHECKER
void	ft_error(char *str);
void	ft_isnum(char *str);
t_stack	*ft_check(int argc, char **argv);
void	ft_issorted(t_stack **a);

//MOVIMIENTOS
void	ft_swap(t_stack **stack, char c);
void	ft_swap_ab(t_stack **a, t_stack **b);
void	ft_push(t_stack **push, t_stack **dst, char c);
void	ft_rotate(t_stack **stack, char c);
void	ft_r_rotate(t_stack **a, t_stack **b);
void	ft_reverse_rotate(t_stack **stack, char c);
void	ft_rr_rotate(t_stack **a, t_stack **b);

#endif