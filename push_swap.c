/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:34:28 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/22 19:12:08 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;
	t_stack	*prev;

	current = *stack;
	next = ((prev = current->past), current->next);
	if (current->content > next->content && current->content < prev->content)
		ft_swap(stack, 'a');
	else if (current->content < next->content
		&& current->content > prev->content)
		ft_reverse_rotate(stack, 'a');
	else if (current->content < next->content
		&& current->content < prev->content)
	{
		ft_swap(stack, 'a');
		ft_rotate(stack, 'a');
	}
	else if (current->content > next->content
		&& current->content > prev->content)
	{
		ft_rotate(stack, 'a');
		if (next->content > prev->content)
			ft_swap(stack, 'a');
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	a = ft_check(argc, argv);
	if (!a || ft_issorted(&a) == 1)
		return (0);
	b = NULL;
	ft_sort(&a, &b);
	//ft_print_lst(&a);
	ft_free_stack(&a);
	return (0);
}
