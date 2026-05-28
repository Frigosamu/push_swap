/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:28:42 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/05 14:15:08 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(long n);

char	*ft_itoa(int n)
{
	char	*dest;
	size_t	size;
	long	nbr;

	nbr = n;
	size = num_len(nbr);
	dest = malloc(size + 1);
	if (!dest)
		return (NULL);
	dest[size] = '\0';
	if (nbr == 0)
		dest[0] = '0';
	if (nbr < 0)
	{
		dest[0] = '-';
		nbr = nbr * (-1);
	}
	while (nbr > 0)
	{
		dest[--size] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (dest);
}

static size_t	num_len(long n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
	{
		size++;
		if (n < 0)
			n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

/*int	main(void)
{
	int	n;

	n = 123;
	printf("%s", ft_itoa(n));
	return (0);
}*/
