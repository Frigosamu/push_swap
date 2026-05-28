/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:32:07 by efiguere          #+#    #+#             */
/*   Updated: 2026/04/21 17:28:32 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*aux_s;
	unsigned char	aux_c;
	size_t			i;

	i = 0;
	aux_c = (unsigned char) c;
	aux_s = (unsigned char *)s;
	while (i < n)
	{
		if (aux_s[i] == aux_c)
			return ((void *)&aux_s[i]);
		i++;
	}
	return (NULL);
}
