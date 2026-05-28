/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:10:05 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/26 12:01:48 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, t_stats *stats)
{
	ft_swap_a(a);
	if (stats)
	{
		stats->sa++;
		stats->total++;
		if (stats->is_bench)
			return ;
	}
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b, t_stats *stats)
{
	ft_swap_b(b);
	if (stats)
	{
		stats->sb++;
		stats->total++;
		if (stats->is_bench)
			return ;
	}
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b, t_stats *stats)
{
	ft_swap_ab(a, b);
	if (stats)
	{
		stats->ss++;
		stats->total++;
		if (stats->is_bench)
			return ;
	}
	write(1, "ss\n", 3);
}
