/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:56:40 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/26 16:33:13 by mariredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_bits(t_stack *stack)
{
	int	max_bits;
	int	max;

	max_bits = 0;
	max = stack->size - 1;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_complex_radix(t_stack *a, t_stack *b, t_stats *stat)
{
	int		size;
	int		max_bits;
	int		i;

	max_bits = ft_max_bits(a);
	i = 0;
	while (max_bits-- > 0)
	{
		size = a->size;
		while (size-- > 0)
		{
			if (((a->top->idx >> i) & 1) == 0)
				ft_pb(a, b, stat);
			else
				ft_ra(a, stat);
		}
		while (b->size > 0)
			ft_pa(a, b, stat);
		i++;
	}
}
