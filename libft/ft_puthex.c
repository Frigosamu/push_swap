/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:08:37 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/21 11:06:59 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(va_list *args, char type)
{
	unsigned int	n;
	int				i;

	i = 0;
	n = va_arg(*args, unsigned int);
	if (n == 0)
		return (write(1, "0", 1));
	if (type == 'x')
		i += ft_print_base(n, "0123456789abcdef");
	else if (type == 'X')
		i += ft_print_base(n, "0123456789ABCDEF");
	return (i);
}
