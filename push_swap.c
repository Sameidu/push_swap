/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:34:28 by smeixoei          #+#    #+#             */
/*   Updated: 2023/12/21 11:36:40 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_print_lst(&a);
	printf("size_B: %d\n", ft_lst_size(&b));
	printf("size_A: %d\n", ft_lst_size(&a));
	return (0);
}
