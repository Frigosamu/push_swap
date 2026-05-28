/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:47:57 by efiguere          #+#    #+#             */
/*   Updated: 2026/04/21 16:05:30 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;
	char	aux;

	i = 0;
	ptr = NULL;
	aux = (char)c;
	while (s[i])
	{
		if (s[i] == aux)
			ptr = (char *) &s[i];
		i++;
	}
	if (aux == '\0')
		return ((char *) &s[i]);
	return (ptr);
}
