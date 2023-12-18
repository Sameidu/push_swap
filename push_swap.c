/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:34:28 by smeixoei          #+#    #+#             */
/*   Updated: 2023/12/18 12:44:51 by smeixoei         ###   ########.fr       */
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
	// ft_sort3(&a);
	ft_print_lst(&a);
	printf("size: %d\n", ft_lst_size(&a));
	ft_push_tob(&a, &b);
	ft_print_lst(&b);
	printf("size: %d\n", ft_lst_size(&b));
	// ft_swap(&a, 'x');
	// ft_print_lst(&a);
	// ft_reverse_rotate(&a, 'x');
	// ft_print_lst(&a);
	// ft_rotate(&a, 'x');
	// ft_print_lst(&a);
	
	return (0);
}
