/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:34:28 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/30 12:08:42 by smeixoei         ###   ########.fr       */
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

void	ft_sort(t_stack **a, t_stack **b)
{
	ft_push_tob(a, b);
	if (ft_issorted(a) == 0)
		ft_sort3(a);
	while (*b)
	{
		ft_get_index(a);
		ft_get_index(b);
		ft_set_target(a, b);
		ft_calc_moves_ab(a, b);
		ft_do_cheap(a, b);
	}
	ft_shift(a);
}

char	**ft_argsplit(char **argv)
{
	char	**args;
	char	*tmp;
	int		i;

	i = 1;
	args = NULL;
	tmp = ft_strdup("");
	while (argv[i])
	{
		tmp = ft_strjoin(tmp, argv[i]);
		tmp = ft_strjoin(tmp, " ");
		i++;
	}
	args = ft_split(tmp, ' ');
	free(tmp);
	if (!args)
		ft_error("Error");
	return (args);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	if (argc < 2)
		return (0);
	args = ft_argsplit(argv);
	a = NULL;
	a = ft_check(args);
	if (!a || ft_issorted(&a) == 1)
		return (0);
	b = NULL;
	ft_sort(&a, &b);
	ft_print_lst(&a);
	ft_free_stack(&a);
	return (0);
}
