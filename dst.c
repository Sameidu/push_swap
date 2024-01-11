/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:33:21 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/11 12:26:01 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_index(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	int		i;

	if (!*stack)
		return ;
	i = 0;
	current = *stack;
	next = current->next;
	while (next != *stack)
	{
		current->index = i;
		current = current->next;
		next = next->next;
		i++;
	}
	current->index = i;
	return ;
}

void	ft_get_higher(t_stack **stack)
{
	t_stack	*tmp;
	int		pos;
	int		higher_index;

	tmp = *stack;
	ft_get_index(stack);
	pos = INT_MIN;
	higher_index = tmp->index;
	while (tmp->next != *stack)
	{
		if (tmp->pos > pos)
		{
			pos = tmp->pos;
			higher_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (tmp->pos > pos)
	{
		pos = tmp->pos;
		higher_index = tmp->index;
	}
	return(higher_index);
}

void	ft_get_lowest(t_stack **stack)
{
	t_stack	*tmp;
	int		pos;
	int		lowest_index;

	tmp = *stack;
	ft_get_index(stack);
	pos = INT_MAX;
	lowest_index = tmp->index;
	while (tmp->next != *stack)
	{
		if (tmp->pos < pos)
		{
			pos = tmp->pos;
			lowest_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (tmp->pos < pos)
	{
		pos = tmp->pos;
		lowest_index = tmp->index;
	}
	return(lowest_index);
}

void	ft_get_target(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		index;

	tmp_a = *a;
	tmp_b = *b;
	index = INT_MAX;
	while (tmp_a->next != *a)
	{
		if (tmp_a->index > tmp_b->index && tmp_a->index < index)
			index = tmp_a->index;
		printf("target:%d\n", tmp_b->target);
		tmp_a = tmp_a->next;
	}
	if (index != INT_MAX)
	{
		tmp_b->target = index;
		return ;
	}
	tmp_a = *a;
	index = INT_MAX;
	while (tmp_a->next != *a)
	{
		if (tmp_a->index < index)
			index = tmp_a->index;
		tmp_a = tmp_a->next;
	}
	tmp_b->target = index;
	return ;
}