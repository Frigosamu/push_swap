/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 12:21:17 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/21 11:06:27 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(va_list *args)
{
	int		i;
	char	*c;

	i = 0;
	c = va_arg(*args, char *);
	if (!c)
		return (write(1, "(null)", 6));
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	return (i);
}
