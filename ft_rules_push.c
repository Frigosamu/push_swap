/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:50:10 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/26 12:10:24 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b, t_stats *stats)
{
	ft_push_a(a, b);
	if (stats)
	{
		stats->pa++;
		stats->total++;
		if (stats->is_bench)
			return ;
	}
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b, t_stats *stats)
{
	ft_push_b(a, b);
	if (stats)
	{
		stats->pb++;
		stats->total++;
		if (stats->is_bench)
			return ;
	}
	write(1, "pb\n", 3);
}
