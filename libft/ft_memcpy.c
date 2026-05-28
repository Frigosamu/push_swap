/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:42:34 by efiguere          #+#    #+#             */
/*   Updated: 2026/04/21 12:51:16 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*aux_dest;
	unsigned char	*aux_src;

	if (!src && !dest)
		return (NULL);
	aux_dest = (unsigned char *)dest;
	aux_src = (unsigned char *)src;
	while (n > 0)
	{
		*(aux_dest++) = *(aux_src++);
		n--;
	}
	return (dest);
}
