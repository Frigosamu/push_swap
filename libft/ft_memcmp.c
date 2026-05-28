/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:29:02 by efiguere          #+#    #+#             */
/*   Updated: 2026/04/21 18:04:21 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;
	size_t			i;

	i = 0;
	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	while (n > i)
	{
		if (aux_s1[i] != aux_s2[i])
			return (aux_s1[i] - aux_s2[i]);
		i++;
	}
	return (0);
}
