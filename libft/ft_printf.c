/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:36:00 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/21 11:07:50 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_filter(&args, format[i + 1]);
			i++;
		}
		else if (format[i] != '%')
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
