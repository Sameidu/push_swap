/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:50:50 by smeixoei          #+#    #+#             */
/*   Updated: 2023/10/11 12:26:47 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_isnum(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < 48 && str[i] > 57)
			ft_error("Error\n");
		i++;
	}
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (0);
}
