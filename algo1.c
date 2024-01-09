/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:18:25 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/09 20:34:06 by smeixoei         ###   ########.fr       */
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
	if (current->content > next->content
		&& current->content < prev->content)
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
	ft_print_lst(stack);
}

void	ft_calc_moves_ab(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_b = *b;
	size_a = ft_lst_size(a);
	size_b = ft_lst_size(b);
	while (tmp_b->next != *b)
	{
		tmp_b->moves_b = tmp_b->index;
		if (tmp_b->index > size_b / 2)
			tmp_b->moves_b = (size_b - tmp_b->index) * -1;
		tmp_b->moves_a = tmp_b->index;
		if (tmp_b->target > size_a / 2)
			tmp_b->moves_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
	tmp_b->moves_b = tmp_b->index;
	if (tmp_b->index > size_b / 2)
		tmp_b->moves_b = (size_b - tmp_b->index) * -1;
	tmp_b->moves_a = tmp_b->index;
	if (tmp_b->target > size_a / 2)
		tmp_b->moves_a = (size_a - tmp_b->target) * -1;
	return ;
}

int	ft_pick(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (tmp->moves_a * tmp->moves_b < 0)
		return (ft_value(tmp->moves_a) + ft_value(tmp->moves_b));
	else if (tmp->moves_a * tmp->moves_b > 0)
	{
		if (ft_value(tmp->moves_a) >= ft_value(tmp->moves_b))
			return (ft_value(tmp->moves_a));
		else
			return (ft_value(tmp->moves_b));
	}
	else if (tmp->moves_a == 0)
		return (ft_value(tmp->moves_b));
	else
		printf("moves_a: %d\n", tmp->moves_a);
		return (ft_value(tmp->moves_a));
}

void	ft_move(t_stack **a, t_stack **b, int dst_a, int dst_b)
{
	// printf("dst_a: %d\n", dst_a);
	// printf("dst_b: %d\n", dst_b);
	if (dst_a < 0 && dst_b < 0)
	{
		while (dst_a < 0 && dst_b < 0)
		{
			ft_rr_rotate(a, b);
			dst_a++;
			dst_b++;
		}
	}
	else if (dst_a > 0 && dst_b > 0)
	{
		while (dst_a > 0 && dst_b > 0)
		{
			dst_a--;
			dst_b--;
			ft_r_rotate(a, b);
		}
	}
	if (*b)
		ft_push(b, a, 'a');
}

void	ft_do_cheap(t_stack **a, t_stack **b)
{
	t_stack	*stack_b;
	int		cheap;
	int		i;
	int		dst_a;
	int		dst_b;

	stack_b = ((cheap = INT_MAX), *b);

	while (stack_b->next != *b)
	{
		i = ft_pick(stack_b);
		if (i < ft_value(cheap))
		{
			cheap = ((dst_a = stack_b->moves_a), i);
			dst_b = stack_b->moves_b;
		}
		stack_b = stack_b->next;
			printf("movess_b:%d\n", dst_b);
		printf("movess_a:%d\n", dst_a);
		printf("cheap:%d\n", cheap);
	}
	i = ft_pick(stack_b);
	if (i < ft_value(cheap))
	{
		cheap = ((dst_a = stack_b->moves_a), i);
		dst_b = stack_b->moves_b;
	}
	ft_move(a, b, dst_a, dst_b);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	ft_push_tob(a, b);
	if (ft_issorted(a) == 0)
		ft_sort3(a);
	while (*b)
	{
		ft_get_index(a);
		ft_get_index(b);
		ft_get_target(a, b);
		ft_calc_moves_ab(a, b);
		ft_do_cheap(a, b);
		ft_print_lst(a);
	}
}
