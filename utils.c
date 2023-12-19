/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:50:50 by smeixoei          #+#    #+#             */
/*   Updated: 2023/12/19 12:39:34 by smeixoei         ###   ########.fr       */
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

int	ft_lst_size(t_stack **stack)
{
	int	lenght;
	t_stack	*lst;

	lenght = 0;
	lst = *stack;
	while (lst->next != *stack)
	{
		lenght++;
		lst = lst->next;
	}
	++lenght;
	return (lenght);
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
