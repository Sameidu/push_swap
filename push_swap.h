/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:20:13 by smeixoei          #+#    #+#             */
/*   Updated: 2023/10/23 10:39:53 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				index;
	int				content;
	struct s_stak	*next;
	struct s_stack	*past;
}	t_stack;

void	ft_error(char *str);
void	ft_isnum(char *str);
void	ft_duplicate_arg(char **str);

//MOVIMIENTOS
void	ft_swap(t_stack **stack, char c);
void	ft_swap_ab(t_stack **a, t_stack **b, char c);
void	ft_pusha(t_stack **stack_a, t_stack **stack_b);
void	ft_pushb(t_stack **stack_a, t_stack **stack_b);

#endif