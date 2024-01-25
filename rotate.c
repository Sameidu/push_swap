/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:24:26 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/25 13:19:14 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack, char c)
{
	if (!*stack)
		return ;
	*stack = (*stack)->next;
	if (c == 'a')
		ft_putendl_fd("ra", 1);
	if (c == 'b')
		ft_putendl_fd("rb", 1);
	if (c == 'x')
		return ;
}

void	ft_r_rotate(t_stack **a, t_stack **b)
{
	ft_rotate(a, 'x');
	ft_rotate(b, 'x');
	ft_putendl_fd("rr", 1);
}

void	ft_reverse_rotate(t_stack **stack, char c)
{
	if (!*stack)
		return ;
	*stack = (*stack)->past;
	if (c == 'a')
		ft_putendl_fd("rra", 1);
	if (c == 'b')
		ft_putendl_fd("rrb", 1);
	if (c == 'x')
		return ;
}

void	ft_rr_rotate(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a, 'x');
	ft_reverse_rotate(b, 'x');
	ft_putendl_fd("rrr", 1);
}

void	ft_loops(t_stack **a, t_stack **b, int i, char c)
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
