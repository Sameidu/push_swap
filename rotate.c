/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:24:26 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/17 11:49:40 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack, char c)
{
	if (!*stack)
		return ;
	*stack = (*stack)->next;
	if (c == 'a')
		ft_putendl_fd("ra", 2);
	if (c == 'b')
		ft_putendl_fd("rb", 2);
	if (c == 'x')
		return ;
}

void	ft_r_rotate(t_stack **a, t_stack **b)
{
	ft_rotate(a, 'x');
	ft_rotate(b, 'x');
	ft_putendl_fd("rr", 2);
}

void	ft_reverse_rotate(t_stack **stack, char c)
{
	if (!*stack)
		return ;
	*stack = (*stack)->past;
	if (c == 'a')
		ft_putendl_fd("rra", 2);
	if (c == 'b')
		ft_putendl_fd("rrb", 2);
	if (c == 'x')
		return ;
}

void	ft_rr_rotate(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a, 'x');
	ft_reverse_rotate(b, 'x');
	ft_putendl_fd("rrr", 2);
}

void	ft_loop(t_stack **a, t_stack **b, int i, char c)
{
	while (i)
	{
		if (i > 0)
		{
			if (c == 'a')
				ft_rotate(a, c);
			else if (c == 'b')
				ft_rotate(b, c);
			i--;
		}
		else
		{
			if (c == 'a')
				ft_reverse_rotate(a, c);
			else if (c == 'b')
				ft_reverse_rotate(b, c);
			i++;
		}
	}
}
