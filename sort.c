/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:18:25 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/29 19:24:56 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calc_moves_ab(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	t_stack	*last;
	int		size_a;
	int		size_b;

	tmp_b = ((last = (*b)->past), *b);
	size_a = ft_lst_size(a);
	size_b = ft_lst_size(b);
	while (1)
	{
		tmp_b->moves_b = tmp_b->index;
		if (tmp_b->index > size_b / 2)
			tmp_b->moves_b = (size_b - tmp_b->index) * -1;
		tmp_b->moves_a = tmp_b->target;
		if (tmp_b->target > size_a / 2)
			tmp_b->moves_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
		if (tmp_b == last->next)
			break ;
	}
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
		return (ft_value(tmp->moves_a));
}

void	ft_move(t_stack **a, t_stack **b, int dst_a, int dst_b)
{
	if (dst_a < 0 || dst_b < 0)
	{
		while (dst_a < 0 && dst_b < 0)
		{
			ft_rr_rotate(a, b);
			dst_a++;
			dst_b++;
		}
	}
	else if (dst_a > 0 || dst_b > 0)
	{
		while (dst_a > 0 && dst_b > 0)
		{
			dst_a--;
			dst_b--;
			ft_r_rotate(a, b);
		}
	}
	ft_loops(a, b, dst_a, 'a');
	ft_loops(a, b, dst_b, 'b');
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
	}
	i = ft_pick(stack_b);
	if (i < ft_value(cheap))
	{
		cheap = ((dst_a = stack_b->moves_a), i);
		dst_b = stack_b->moves_b;
	}
	ft_move(a, b, dst_a, dst_b);
}

void	ft_shift(t_stack **a)
{
	int	size;
	int	lowest;

	size = ft_lst_size(a);
	lowest = ft_get_lowest(a);
	if (lowest > size / 2)
	{
		while ((*a)->index != lowest)
			ft_reverse_rotate(a, 'a');
	}
	else
	{
		while ((*a)->index != lowest)
			ft_rotate(a, 'a');
	}
}
