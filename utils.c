/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:50:50 by smeixoei          #+#    #+#             */
/*   Updated: 2023/10/23 10:35:51 by smeixoei         ###   ########.fr       */
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

void	ft_duplicate_arg(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				ft_error("Error. Duplicate argument");
			j++;
		}
		i++;
	}
}

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}
