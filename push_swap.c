/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:34:28 by smeixoei          #+#    #+#             */
/*   Updated: 2023/11/21 17:45:10 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	a = NULL;
	a = ft_check(argc, argv);
	ft_issorted(&a);
	b = NULL;
	ft_print_lst(&a);
		// Si no está ordenada iniciaar operaciones.
	return (0);
}
