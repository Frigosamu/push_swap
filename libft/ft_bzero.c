/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:41:51 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/05 12:40:17 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int	main(void)
{
	char s[20] = "Hola! Mundo.";

	printf("%s\n", s);
	ft_bzero(s, 2);
	printf("%s\n", &s[2]);
	printf("%d", s[0]);
	return (0);
}*/
