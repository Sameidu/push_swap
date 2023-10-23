/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:24:12 by smeixoei          #+#    #+#             */
/*   Updated: 2023/10/23 09:52:48 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Puedo pasar por argumento cual de los dos stack quiero haccer que se mueva y así evitar hcer la misma función para cada uno.
// pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack a. No hace nada si b está vacío.
// pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack b. No hace nada si a está vacío.
void	ft_pusha(t_stack **stack_a, t_stack **stack_b)
{
    t_stack	*node;

	if (*stack_b == NULL)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	node->next = NULL;
	if ((*stack_a)->next == NULL)
		*stack_a = node;
	else
	{
		node->next = (*stack_a);
		node->past = (*stack_a)->past;
		(*stack_a)->past->next = node;
		*stack_a = (*stack_a)->next;
		*stack_a = node;
	}
}

void	ft_pushb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack	*node;

	if (*stack_a == NULL)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = NULL;
	if ((*stack_b)->next == NULL)
		*stack_b = node;
	else
	{
		node->next = (*stack_b);
		node->past = (*stack_b)->past;
		(*stack_b)->past->next = node;
		*stack_b = (*stack_b)->next;
		*stack_b = node;
	}
}
