/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:24:12 by smeixoei          #+#    #+#             */
/*   Updated: 2023/10/24 17:39:53 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **push, t_stack **dst, char c)
{
	t_stack	*node;

	if (*push == NULL)
		return ;
	*push = ((node = *push), (*push)->next);
	node->next = NULL;
	if (*dst == NULL)
	{
		*dst = node;
		node = ((node->next), node->past);
	}
	else
	{
		node->next = (*dst);
		node->past = (*dst)->past;
		(*dst)->past->next = node;
		(*dst)->past = node;
		*dst = node;
	}
	if (c == 'a')
		ft_putendl_fd("pa", 2);
	else if (c == 'b')
		ft_putendl_fd("pb", 2);
	else
		ft_putendl_fd("ERROR: BAD STACK", 2);
}
