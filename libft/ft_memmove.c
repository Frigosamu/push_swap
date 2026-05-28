/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:35:56 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/04 16:29:41 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*aux_dest;
	unsigned char	*aux_src;
	size_t			i;

	if (!src && !dest)
		return (NULL);
	aux_dest = (unsigned char *)dest;
	aux_src = (unsigned char *)src;
	i = 0;
	if (aux_dest > aux_src)
		while (n-- > 0)
			aux_dest[n] = aux_src[n];
	else
	{
		while (i < n)
		{
			aux_dest[i] = aux_src[i];
			i++;
		}
	}
	return (dest);
}

/*int	main(void)
{
	char	dest[5];
	void	*src = "Hola, Mundo";

	printf("%s", (char *)ft_memmove((void *)dest, (void *)src, 4));
	return (0);
}*/
