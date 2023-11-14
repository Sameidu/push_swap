/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:18:25 by smeixoei          #+#    #+#             */
/*   Updated: 2023/11/14 12:14:19 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_sort3(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	t_stack	*prev;

	current = *stack;
	next = current->next;
	prev = current->past;
	if (current->content > next->content && current->content < prev->content)
		ft_swap(stack, 'a');
	else if (current->content > next->content && current->content > prev->content)
	{
		ft_swap(stack, 'a');
		ft_reverse_rotate(stack, 'a');
	}
	else if (current->content < next->content && current->content > prev->content)
		ft_rotate(stack, 'a');
	else if (current->content < next->content && current->content < prev->content)
	{
		ft_swap(stack, 'a');
		ft_rotate(stack, 'a');
	}
}

