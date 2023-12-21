/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:50:50 by smeixoei          #+#    #+#             */
/*   Updated: 2023/12/21 11:01:28 by smeixoei         ###   ########.fr       */
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

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	next = current->next;
	while (next != *stack)
	{
		free(current);
		current = next;
		next = next->next;
	}
	free(current);
}

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (0);
}
