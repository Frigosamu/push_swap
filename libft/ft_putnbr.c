/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:59:20 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/27 11:04:06 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(unsigned int n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789";
	if (n >= 10)
		i += ft_print_nbr(n / 10);
	i += write(1, &base[n % 10], 1);
	return (i);
}

int	ft_putnbr(va_list *args)
{
	int				i;
	int				n;
	unsigned int	num;

	i = 0;
	n = va_arg(*args, int);
	if (n < 0)
	{
		i += write(1, "-", 1);
		num = (unsigned int)(n * -1);
	}
	else
		num = (unsigned int)n;
	i += ft_print_nbr(num);
	return (i);
}

int	ft_nbr_unsigned(va_list *args)
{
	int				i;
	unsigned int	num;

	i = 0;
	num = va_arg(*args, unsigned int);
	i += ft_print_nbr(num);
	return (i);
}

int	ft_print_double(double num)
{
	int			i;
	long long	int_part;
	long long	dec_part;

	i = 0;
	int_part = (long long)num;
	i += ft_print_nbr((unsigned int)int_part);
	i += write(1, ".", 1);
	num -= int_part;
	dec_part = (long long)((num * 100.0) + 0.5);
	if (dec_part < 10)
		i += write(1, "0", 1);
	i += ft_print_nbr((unsigned int)dec_part);
	return (i);
}

int	ft_putdouble(va_list *args)
{
	int		i;
	double	num;

	i = 0;
	num = va_arg(*args, double);
	if (num < 0)
	{
		i += write(1, "-", 1);
		num = -num;
	}
	i += ft_print_double(num);
	return (i);
}
