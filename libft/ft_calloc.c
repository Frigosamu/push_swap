/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:48:20 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/05 12:53:50 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	res;

	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
	res = nmemb * size;
	ptr = malloc(res);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, res);
	return (ptr);
}

/*int	main(void)
{
	char	*c;
	char	*d;

	c = "Hola! Mundo";
	d = ft_calloc(ft_strlen(c) + 1, sizeof(char));
	d = ft_strdup(c);
	printf("%s", d);
	free(d);
	return (0);
}*/
