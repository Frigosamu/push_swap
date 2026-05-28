/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_medium.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:52:51 by mariredo          #+#    #+#             */
/*   Updated: 2026/05/27 12:10:34 by mariredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find max number
int	get_max(t_stack *b)
{
	t_node	*current;
	int		max;

	current = b->top;
	max = current->idx;
	while (current)
	{
		if (current->idx > max)
			max = current->idx;
		current = current->next;
	}
	return (max);
}

// get max number position
int	get_max_position(t_stack *b)
{
	int		max;
	int		pos;
	t_node	*current;

	current = b->top;
	max = get_max(b);
	pos = 0;
	while (current)
	{
		if (current->idx == max)
			return (pos);
		current = current->next;
		pos++;
	}
	return (pos);
}

void	push_chunks_to_b(t_stack **stack_list, int min, int max, t_stats *stat)
{
	int		size;
	t_stack	*a;
	t_stack	*b;

	a = stack_list[0];
	b = stack_list[1];
	size = a->size;
	while (size > 0)
	{
		if (a->top->idx >= min && a->top->idx <= max)
		{
			ft_pb(a, b, stat);
			if (b->top->idx < (min + max) / 2)
				ft_rb(b, stat);
		}
		else
			ft_ra(a, stat);
		size--;
	}
}

void	move_to_a(t_stack *a, t_stack *b, t_stats *stat)
{
	int	max;
	int	pos;

	while (b->size > 0)
	{
		max = get_max(b);
		pos = get_max_position(b);
		if (pos <= b->size / 2)
		{
			while (b->top->idx != max)
				ft_rb(b, stat);
		}
		else
		{
			while (b->top->idx != max)
				ft_rrb(b, stat);
		}
		ft_pa(a, b, stat);
	}
}

void	ft_medium(t_stack *a, t_stack *b, t_stats *stat)
{
	int		min;
	int		max;
	int		chunk_size;
	int		size;
	t_stack	**stack_list;

	size = a->size;
	chunk_size = ft_chunk_size(a);
	stack_list = init_stack_list(a, b);
	if (!stack_list)
		return ;
	ft_idx_stack(a);
	min = 0;
	max = chunk_size - 1;
	while (min < size)
	{
		push_chunks_to_b(stack_list, min, max, stat);
		min += chunk_size;
		max += chunk_size;
	}
	free(stack_list);
	move_to_a(a, b, stat);
}
