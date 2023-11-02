/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:24:26 by smeixoei          #+#    #+#             */
/*   Updated: 2023/11/02 09:09:51 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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
	else
		ft_putendl_fd("ERROR: BAD STACK", 2);
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
		ft_putendl_fd("ra", 2);
	if (c == 'b')
		ft_putendl_fd("rb", 2);
	if (c == 'x')
		return ;
	else
		ft_putendl_fd("ERROR: BAD STACK", 2);
}

void	ft_rr_rotate(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a, 'x');
	ft_reverse_rotate(b, 'x');
	ft_putendl_fd("rrr", 2);
}
