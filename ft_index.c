/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:55:41 by mariredo          #+#    #+#             */
/*   Updated: 2026/05/26 16:31:39 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *a, int value)
{
	t_node	*current;
	int		index;

	current = a->top;
	index = 0;
	while (current)
	{
		if (current->value < value)
			index++;
		current = current->next;
	}
	return (index);
}

void	ft_idx_stack(t_stack *a)
{
	t_node	*current;

	if (!a || a->size == 0)
		return ;
	current = a->top;
	while (current)
	{
		current->idx = get_index(a, current->value);
		current = current->next;
	}
}
