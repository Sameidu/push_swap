/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:32:44 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/31 10:29:09 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *str)
{
	long	aux;
	char	*num;

	num = str;
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	aux = ft_atol(num);
	if (aux > INT_MAX || aux < INT_MIN)
		return (0);
	return (1);
}

void	ft_duplicate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = *stack;
	if (!current)
		return ;
	while (current != (*stack)->past)
	{
		compare = current->next;
		while (compare != *stack)
		{
			if (current->content == compare->content)
				ft_error("Error");
			compare = compare->next;
		}
		current = current->next;
	}
}

void	ft_put_pos(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*aux;
	int		pos;

	tmp = ((last = *stack), *stack);
	last = (*stack)->past;
	while (1)
	{
		aux = *stack;
		pos = 1;
		while (aux->next != *stack)
		{
			if (tmp->content > aux->content)
				pos++;
			aux = aux->next;
		}
		if (tmp->content > aux->content)
			pos++;
		tmp->fpos = pos;
		tmp = tmp->next;
		if (tmp == last->next)
			break ;
	}
}

t_stack	*ft_check(char **args)
{
	int		i;
	t_stack	*stack;
	t_stack	*new_node;

	i = ((stack = NULL), 0);
	while (args[i])
	{
		if (ft_isnum(args[i]) == 0)
			ft_error("Error");
		new_node = ft_create_node(args[i]);
		if (stack == NULL)
		{
			stack = new_node;
			stack->next = ((stack->past = stack), stack);
		}
		else
		{
			new_node->past = ((new_node->next = stack), stack->past);
			stack->past = ((stack->past->next = new_node), new_node);
		}
		i++;
	}
	ft_duplicate(&stack);
	ft_put_pos(&stack);
	return (stack);
}
