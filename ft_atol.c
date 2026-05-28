/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:37:43 by mariredo          #+#    #+#             */
/*   Updated: 2026/05/18 16:48:41 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *s)
{
	long	res;
	int		i;
	int		neg;

	res = 0;
	i = 0;
	neg = 1;
	if (!s || s[0] == '\0')
		return (0);
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = neg * (-1);
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * neg);
}
