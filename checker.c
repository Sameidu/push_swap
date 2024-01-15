/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:32:44 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/15 09:19:13 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_isnum(char *str)
{
	long	aux;
	char	*num;

	num = str;
	if (!str)
		ft_error("ERROR: Empty argument");
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		ft_error("ERROR: No number after sign");
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			ft_error("ERROR: Not a number");
		str++;
	}
	aux = ft_atoi(num);
	if (aux > INT_MAX || aux < INT_MIN)
		ft_error("ERROR: Number out of range");
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
			{
				ft_error("ERROR: Duplicate number");
			}
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
	while (last->next != *stack)
		last = last->next;
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
		printf("tmp->content: %d\n", tmp->content);
		printf("tmp->fpos: %d\n", tmp->fpos);
		tmp = tmp->next;
		if (tmp == last->next)
			break ;
	}
}

t_stack	*ft_check(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	t_stack	*new_node;

	i = ((stack = NULL), 1);
	while (i < argc)
	{
		ft_isnum(argv[i]);
		new_node = ft_create_node(argv[i]);
		if (stack == NULL)
		{
			stack = new_node;
			stack->next = ((stack->past = stack), stack);
		}
		else
		{
			new_node->past = ((new_node->next = stack), stack->past);
			stack->past->next = new_node;
			stack->past = new_node;
		}
		i++;
	}
	ft_duplicate(&stack);
	ft_put_pos(&stack);
	return (stack);
}
