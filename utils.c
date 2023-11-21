/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:50:50 by smeixoei          #+#    #+#             */
/*   Updated: 2023/11/21 17:42:54 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_issorted(t_stack **a)
{
	t_stack	*current;
	t_stack	*next;

	current = *a;
	next = current->next;
	while (next != *a)
	{
		if (current->content > next->content)
			return ;
		current = current->next;
		next = next->next;
	}
	exit (0);
}

int	ft_find_max(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	int		max;

	current = *stack;
	next = current->next;
	max = current->content;
	while (next != *stack)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
		next = next->next;
	}
	return (max);
}

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (0);
}
