/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:18:25 by smeixoei          #+#    #+#             */
/*   Updated: 2023/12/18 12:48:39 by smeixoei         ###   ########.fr       */
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

void	ft_push_tob(t_stack **a, t_stack **b)
{
	int	i;
	int	push;
	int	size;

	i = 0;
	push = 0;
	size = ft_lst_size(a);
	while (i < size && push < size)
	{
		if ((*a)->content > (*a)->next->content)
		{
			ft_swap(a, 'a');
			ft_push(a, b, 'b');
			push++;
		}
		else
			ft_rotate(a, 'a');
		i++;
	}
	while (size - push > 3)
	{
		ft_push(a, b, 'b');
		push++;
	}
}
