/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:24:49 by smeixoei          #+#    #+#             */
/*   Updated: 2023/10/19 13:00:15 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Puedo pasar por argumento cual de los dos stack quiero haccer que se mueva y así evitar hcer la misma función para cada uno.
void	ft_swap(t_stack **stack, char c)
{
	t_stack	*aux;
	t_stack	*aux_2;

    if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	aux = (*stack);
	aux_2 = (*stack)->next;
	(*stack) = aux_2;
	(*stack)->next = aux;
	if (c == 'a')
		ft_putendl_fd("sa\n", 2);
	else if (c == 'b')
		ft_putendl_fd("sb\n", 2);
	else if (c == 'x')
			return (1);
}

void	ft_swap_ab(t_stack **a, t_stack **b, char c)
{
    ft_swap(a, 'x');
	ft_swap(b, 'x');
	ft_putendl_fd("ss\n", 2);
}
// sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si hay uno o menos elementos.
// sb swap b: Intercambia los dos primeros elementos del stack b. No hace nada si hay uno o menos elementos.
// ss swap a y swap b a la vez.