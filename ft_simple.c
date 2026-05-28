/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 11:43:30 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/26 16:11:30 by mariredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple(t_stack *a, t_stack *b, t_stats *stat)
{
	t_node	*min;
	int		idx;

	while (a->size > 0)
	{
		min = ft_get_min(a);
		idx = ft_get_position(a, min);
		if (idx <= (a->size / 2))
		{
			while (a->top != min)
				ft_ra(a, stat);
		}
		else
		{
			while (a->top != min)
				ft_rra(a, stat);
		}
		ft_pb(a, b, stat);
	}
	while (b->size > 0)
		ft_pa(a, b, stat);
}

t_node	*ft_get_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	min = stack->top;
	while (current)
	{
		if (current->idx < min->idx)
			min = current;
		current = current->next;
	}
	return (min);
}

int	ft_get_position(t_stack *stack, t_node *target)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = stack->top;
	while (current && current != target)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}
