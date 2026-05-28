/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:32:41 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/26 12:24:58 by mariredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_compute_disorder(t_stack *stack)
{
	double	mistakes;
	double	total_pairs;
	t_node	*current;
	t_node	*compared;

	if (!stack || stack->size <= 1)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	current = stack->top;
	while (current && current->next)
	{
		compared = current->next;
		while (compared)
		{
			total_pairs++;
			if (current->idx > compared->idx)
				mistakes++;
			compared = compared->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}

void	ft_adaptive(t_stack *a, t_stack *b, t_stats *stat)
{
	double	disorder;

	disorder = ft_compute_disorder(a);
	if (disorder < 0.2)
	{
		ft_simple(a, b, stat);
		return ;
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		ft_medium(a, b, stat);
		return ;
	}
	else if (disorder >= 0.5)
	{
		ft_complex_radix(a, b, stat);
		return ;
	}
}
