/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smeixoei <smeixoei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:01:32 by smeixoei          #+#    #+#             */
/*   Updated: 2024/01/16 20:55:40 by smeixoei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	if (count == SSIZE_MAX || size == SSIZE_MAX)
		return (NULL);
	s = malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero((void *)s, count * size);
	return ((void *)s);
}
