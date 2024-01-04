/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarameixoeiro <sarameixoeiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:50:50 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/04 11:33:46 by sarameixoei      ###   ########.fr       */
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

int	ft_value(int nbr)
{
	if (nbr < 0)
		return (nbr * (-1));
	return (nbr);
}

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit (0);
}
