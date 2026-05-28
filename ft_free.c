/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:56:45 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/27 15:54:31 by mariredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_node	*aux_node;

	while (stack && stack->top)
	{
		aux_node = stack->top;
		stack->top = aux_node->next;
		free(aux_node);
	}
	stack->bottom = NULL;
	stack->size = 0;
}
