/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:59:26 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/29 16:46:09 by smeixoei         ###   ########.fr       */
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

void	ft_print_lst(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	next = current->next;
	while (next != *stack)
	{
		ft_putnbr_fd(current->content, 1);
		ft_putchar_fd(' ', 1);
		current = current->next;
		next = next->next;
	}
	ft_putnbr_fd(current->content, 1);
	ft_putchar_fd('\n', 1);
	return ;
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
		if ((*a)->content < size / 2)
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
		ft_push(a, b , 'b');
		push++;
	}
}

t_stack	*ft_create_node(char *str)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		ft_error("ERROR: Malloc failed");
	new->content = ft_atoi(str);
	new->next = NULL;
	new->past = NULL;
	return (new);
}
