/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:20:13 by smeixoei          #+#    #+#             */
/*   Updated: 2023/10/20 18:33:26 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
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
void	ft_swap(t_stack **stack, char c);
void	ft_swap_ab(t_stack **a, t_stack **b);

#endif