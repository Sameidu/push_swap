/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarameixoeiro <sarameixoeiro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:33:21 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/16 12:24:58 by sarameixoei      ###   ########.fr       */
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

int ft_get_target(t_stack **a, int b_pos, int max, int pos)
{
	t_stack *tmp_a;
	t_stack *last;

	tmp_a = *a;
	last = *a;
	while (last->next != *a)
		last = last->next;
	while (1)
	{
		if (tmp_a->fpos > b_pos && tmp_a->fpos < max)
		{
			max = tmp_a->fpos;
			pos = tmp_a->index;
		}
		tmp_a = tmp_a->next;
		if (tmp_a == last->next)
			break ;
	}
	if (max != INT_MAX)
		return (pos);
	tmp_a = *a;
	while (1)
	{
		if (tmp_a->fpos < max)
		{
			max = tmp_a->fpos;
			pos = tmp_a->index;
		}
		tmp_a = tmp_a->next;
		if (tmp_a == last->next)
			break ;
	}
	return (pos);
}


void	ft_set_target(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		t_pos;

	t_pos = 0;
	tmp_b = *b;
	while (tmp_b->next != *b)
	{
		t_pos = ft_get_target(a, tmp_b->fpos, INT_MAX, t_pos);
		tmp_b->target = t_pos;
		tmp_b = tmp_b->next;
	}
}