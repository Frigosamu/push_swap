/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:46:40 by efiguere          #+#    #+#             */
/*   Updated: 2026/04/30 17:14:15 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*aux_ptr;

	aux_ptr = (unsigned char *)s;
	while (n > 0)
	{
		*(aux_ptr++) = (unsigned char)c;
		n--;
	}
	return (s);
}

/*int	main(void)
{
	char s[20] = "Hola! Mundo.";

	printf("%s\n", s);
	ft_memset(s, 'A', 4);
	printf("%s\n", s);
}*/