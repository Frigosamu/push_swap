/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:27:36 by mariredo          #+#    #+#             */
/*   Updated: 2026/05/26 17:10:14 by mariredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

void	init_stat(t_stats *stat)
{
	stat->is_bench = 0;
	stat->sa = 0;
	stat->sb = 0;
	stat->ss = 0;
	stat->pa = 0;
	stat->pb = 0;
	stat->ra = 0;
	stat->rb = 0;
	stat->rr = 0;
	stat->rra = 0;
	stat->rrb = 0;
	stat->rrr = 0;
	stat->total = 0;
}

t_stack	**init_stack_list(t_stack *a, t_stack *b)
{
	t_stack	**stack_list;

	stack_list = malloc(sizeof(t_stack *) * 2);
	if (!stack_list)
		return (NULL);
	stack_list[0] = a;
	stack_list[1] = b;
	return (stack_list);
}
