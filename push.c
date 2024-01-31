/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:24:12 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/31 10:35:35 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_moves(t_stack **push, t_stack **dst, t_stack *node)
{
	if (ft_lst_size(push) == 1)
		*push = NULL;
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
		ft_putendl_fd("pa", 1);
	else if (c == 'b')
		ft_putendl_fd("pb", 1);
	else
		ft_putendl_fd("Error", 2);
}
