/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:59:26 by smeixoei          #+#    #+#             */
/*   Updated: 2023/12/21 11:08:54 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	ft_lst_size(t_stack **stack)
{
	int	lenght;
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
int	ft_find_max(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	int		max;

	current = *stack;
	next = current->next;
	max = current->content;
	while (next != *stack)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
		next = next->next;
	}
	return (max);
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
