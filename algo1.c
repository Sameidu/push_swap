/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:18:25 by smeixoei          #+#    #+#             */
/*   Updated: 2023/12/28 12:39:24 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	t_stack	*prev;

	current = *stack;
	next = current->next;
	prev = current->past;
	if (current->content > next->content
		&& current->content < prev->content)
		ft_swap(stack, 'a');
	else if (current->content > next->content
		&& current->content > prev->content)
	{
		ft_swap(stack, 'a');
		ft_reverse_rotate(stack, 'a');
	}
	else if (current->content < next->content
		&& current->content > prev->content)
		ft_rotate(stack, 'a');
	else if (current->content < next->content
		&& current->content < prev->content)
	{
		ft_swap(stack, 'a');
		ft_rotate(stack, 'a');
	}
}

void	ft_calc_moves_ab(t_stack **a, t_stack **b)
{
	t_stack	tmp_a;
	t_stack	tmp_b;
	int		size_a;
	int		size_b;

	size_a = ft_lst_size(a);
	size_b = ft_lst_size(b);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	ft_push_tob(a, b);
	ft_sort3(a);
	while (*b)
	{
		ft_get_index(a);
		ft_get_index(b);
		ft_get_target(a, b);
	}
}