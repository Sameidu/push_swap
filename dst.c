/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarameixoeiro <sarameixoeiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:33:21 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/15 11:46:47 by sarameixoei      ###   ########.fr       */
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

int	ft_get_higher(t_stack **stack)
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
		if (tmp->fpos > pos)
		{
			pos = tmp->fpos;
			higher_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (tmp->fpos > pos)
	{
		pos = tmp->fpos;
		higher_index = tmp->index;
	}
	return (higher_index);
}

int	ft_get_lowest(t_stack **stack)
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
		if (tmp->fpos < pos)
		{
			pos = tmp->fpos;
			lowest_index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (tmp->fpos < pos)
	{
		pos = tmp->fpos;
		lowest_index = tmp->index;
	}
	return (lowest_index);
}

void ft_get_target(t_stack **a, t_stack **b)
{

}

void	ft_set_target(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		pos;

	pos = 0;
	tmp_b = *b;
	while (tmp_b->next != *b)
	{
		pos = ft_get_target(a, , INT_MAX, pos);
		tmp_b->target = pos;
		tmp_b = tmp_b->next;
	}
}