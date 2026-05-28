/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:55:59 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/26 12:00:54 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, t_stats *stats)
{
	ft_reverse_rotate_a(a);
	if (stats)
	{
		stats->rra++;
		stats->total++;
		if (stats->is_bench)
			return ;
	}
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack *b, t_stats *stats)
{
	ft_reverse_rotate_b(b);
	if (stats)
	{
		stats->rrb++;
		stats->total++;
		if (stats->is_bench)
			return ;
	}
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b, t_stats *stats)
{
	ft_reverse_rotate_ab(a, b);
	if (stats)
	{
		stats->rrr++;
		stats->total++;
		if (stats->is_bench)
			return ;
	}
	write(1, "rrr\n", 4);
}
