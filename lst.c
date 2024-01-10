/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:59:26 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/10 12:53:14 by smeixoei         ###   ########.fr       */
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

	size = ft_lst_size(a);
	while (size > 3)
	{
		ft_push(a, b, 'b');
		size = ft_lst_size(a);
	}
}

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
		printf("index_a:%d\n", tmp_a->index);
		printf("index_a_next:%d\n", tmp_a->next->index);
		printf("index_a_past:%d\n", tmp_a->past->index);
		if (tmp_a->index > tmp_b->index && tmp_a->index < index)
			index = tmp_a->index;
		tmp_b->target = index;
		tmp_a = tmp_a->next;
	}
	if (index != INT_MAX)
		return ;
	tmp_a = *a;
	while (tmp_a->next != *a)
	{
		if (tmp_a->index < index)
			index = tmp_a->index;
		tmp_b->target = index;
		tmp_a = tmp_a->next;
	}
	return ;
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
