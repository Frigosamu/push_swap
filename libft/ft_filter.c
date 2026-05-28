/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:02:48 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/27 11:19:36 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_filter(va_list *args, char type)
{
	if (type == 'c')
		return (ft_putchar_args(args));
	else if (type == 's')
		return (ft_putstr(args));
	else if (type == 'p')
		return (ft_putptr(args));
	else if (type == 'x' || type == 'X')
		return (ft_puthex(args, type));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(args));
	else if (type == 'u')
		return (ft_nbr_unsigned(args));
	else if (type == '%')
		return (write(1, "%", 1));
	else if (type == 'f')
		return (ft_putdouble(args));
	return (0);
}
