/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:24:12 by smeixoei          #+#    #+#             */
/*   Updated: 2023/10/20 09:50:37 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Puedo pasar por argumento cual de los dos stack quiero haccer que se mueva y así evitar hcer la misma función para cada uno.
// pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack a. No hace nada si b está vacío.
// pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack b. No hace nada si a está vacío.
void	ft_push(t_stack **stack_a, t_stack **stack_b, char c)
{
    t_stack	*aux;
	t_stack *aux2;

	if (stack_a == NULL)
		return ;
	aux = stack_a;
}
