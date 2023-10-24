/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:24:49 by smeixoei          #+#    #+#             */
/*   Updated: 2023/10/24 15:28:17 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*aux;
	t_stack	*aux_2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	aux = (*stack);
	aux_2 = (*stack)->next;
	(*stack) = aux_2;
	(*stack)->next = aux;
	if (c == 'a')
		ft_putendl_fd("sa", 2);
	else if (c == 'b')
		ft_putendl_fd("sb", 2);
	else if (c == 'x')
		return ;
	else
		ft_putendl_fd("ERROR: BAD STACK", 2);
}

void	ft_swap_ab(t_stack **a, t_stack **b, char c)
{
	ft_swap(a, 'x');
	ft_swap(b, 'x');
	ft_putendl_fd("ss", 2);
}
