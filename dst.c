/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:33:21 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/15 09:59:17 by smeixoei         ###   ########.fr       */
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

// Arreglar, falta último nodo
void ft_get_target(t_stack **a, t_stack **b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
	t_stack *last;
    int		pos;

    tmp_a = *a;
    tmp_b = *b;
    pos = INT_MAX;
	last = *a;
	while (last->next != *a)
		last = last->next;
	while (1)
	{
		if (tmp_a->fpos < pos)
			pos = tmp_a->fpos;
		tmp_b->target = pos;
		printf("tmp_a->content: %d\n", tmp_a->content);
		printf("tmp_a->fpos: %d\n", tmp_a->fpos);
		printf("tmp_b->target: %d\n", tmp_b->target);
		if (tmp_a == last->next)
			break ;
		tmp_a = tmp_a->next;
	}
}

