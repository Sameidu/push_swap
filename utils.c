/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:50:50 by smeixoei          #+#    #+#             */
/*   Updated: 2023/10/26 12:15:31 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_isnum(char *str)
{
	long	aux;
	char	*num;

	num = str;
	if (!str)
		ft_error("Error. Empty argument");
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		ft_error("Error. No number after sign");
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			ft_error("Error. Not a number");
		str++;
	}
	aux = ft_atoi(num);
	if (aux > INT_MAX || aux < INT_MIN)
		ft_error("Error. Number out of range");
}

void	ft_duplicate_arg(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		while (next != stack)
		{
			if (current->content == next->content)
				ft_error("Error. Duplicate argument");
			next = next->next;
		}
		current = current->next;
	}
}

t_stack *ft_create_stack(char *str, t_stack **stack, int i)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		ft_error("Error. Malloc failed");
	new->content = ft_atoi(str);
	new->index = i;
	new = ((new->next), new->past);
	if (*stack == NULL)
	{
		*stack = new;
		return (new);
	}
	new->next = *stack;
	new->past = (*stack)->past;
	(*stack)->past->next = new;
	(*stack)->past = new;
	return (new);
}

t_stack	*ft_check(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		ft_isnum(argv[i]);
		ft_push(&stack, ft_create_stack(argv[i], &stack, i), 'a');
		i++;
	}
	ft_duplicate_arg(stack);
	return (stack);
}

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}
