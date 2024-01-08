/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:24:12 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/08 18:45:02 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_moves(t_stack **push, t_stack **dst, t_stack *node)
{
	if (*push == NULL)
		return ;
	else
	{
		*push = (*push)->next;
		(*push)->past = node->past;
		(*push)->past->next = *push;
	}
	node->next = NULL;
	if (*dst == NULL)
	{
		node->past = node;
		node->next = node;
		*dst = node;
	}
	else
	{
		node->next = *dst;
		node->past = (*dst)->past;
		(*dst)->past->next = node;
		(*dst)->past = node;
		*dst = node;
	}
}

void	ft_push(t_stack **push, t_stack **dst, char c)
{
	t_stack	*node;

	node = *push;
	ft_push_moves(push, dst, node);
	if (c == 'a')
		ft_putendl_fd("pa", 2);
	else if (c == 'b')
		ft_putendl_fd("pb", 2);
	else
		ft_putendl_fd("ERROR: BAD STACK", 2);
}
