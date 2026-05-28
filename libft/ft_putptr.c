/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 18:14:57 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/21 11:06:40 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(va_list *args)
{
	void	*ptr;
	int		i;

	ptr = va_arg(*args, void *);
	i = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	i += write(1, "0x", 2);
	i += ft_print_base((unsigned long long)ptr, "0123456789abcdef");
	return (i);
}

int	ft_print_base(unsigned long long n, char *base)
{
	int		i;

	i = 0;
	if (n >= 16)
		i += ft_print_base(n / 16, base);
	i += write(1, &base[n % 16], 1);
	return (i);
}
