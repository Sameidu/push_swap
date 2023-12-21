/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:24:49 by smeixoei          #+#    #+#             */
/*   Updated: 2023/12/21 09:48:50 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*head;
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	head = *stack;
	first = head;
	second = head->next;
	first->next = second->next;
	first->next->past = first;
	second->past = first->past;
	second->past->next = second;
	first->past = second;
	second->next = first;
	if (head == first)
		*stack = second;
	if (c == 'a')
		ft_putendl_fd("sa", 2);
	else if (c == 'b')
		ft_putendl_fd("sb", 2);
	else if (c == 'x')
		return;
	else
		ft_putendl_fd("ERROR: BAD STACK", 2);
}


void	ft_swap_ab(t_stack **a, t_stack **b)
{
	ft_swap(a, 'x');
	ft_swap(b, 'x');
	ft_putendl_fd("ss", 2);
}
