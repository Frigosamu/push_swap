/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdupli.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:41:02 by mariredo          #+#    #+#             */
/*   Updated: 2026/05/27 15:46:53 by mariredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checkdupli(t_stack *a)
{
	t_node	*current;
	t_node	*compare;

	current = a->top;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
			{
				ft_free_stack(a);
				ft_error();
			}
			compare = compare->next;
		}
		current = current->next;
	}
}
