/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:53:02 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/26 12:00:13 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, t_stats *stats)
{
	ft_rotate_a(a);
	if (stats)
	{
		stats->ra++;
		stats->total++;
		if (stats->is_bench)
			return ;
	}
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack *b, t_stats *stats)
{
	ft_rotate_b(b);
	if (stats)
	{
		stats->rb++;
		stats->total++;
		if (stats->is_bench)
			return ;
	}
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b, t_stats *stats)
{
	ft_rotate_ab(a, b);
	if (stats)
	{
		stats->rr++;
		stats->total++;
		if (stats->is_bench)
			return ;
	}
	write(1, "rr\n", 3);
}
