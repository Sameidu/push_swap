/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:59:26 by smeixoei          #+#    #+#             */
/*   Updated: 2024/10/16 18:21:56 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_stack **stack)
{
	int		lenght;
	t_stack	*lst;

	if (!*stack)
		return (0);
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

void	ft_push_tob(t_stack **a, t_stack **b)
{
	int	size;
	int	push;
	int	i;

	size = ft_lst_size(a);
	push = 0;
	i = 0;
	while (size > 6 && i < size && push < size)
	{
		if ((*a)->fpos < size / 2)
		{
			ft_push(a, b, 'b');
			push++;
		}
		else
			ft_rotate(a, 'a');
		i++;
	}
	while (size - push > 3)
	{
		ft_push(a, b, 'b');
		push++;
	}
}

t_stack	*ft_create_node(char *str)
{
	t_stack	*new;

	new = NULL;
	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new)
		ft_error("Error");
	new->content = ft_atoi(str);
	new->next = NULL;
	new->past = NULL;
	return (new);
}
