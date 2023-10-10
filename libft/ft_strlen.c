/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:13:06 by smeixoei          #+#    #+#             */
/*   Updated: 2023/09/22 09:37:11 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	size_t  lenght = ft_strlen(argv[1]);
	printf("Longitud: %zu\n", lenght);
	return (0);
}
