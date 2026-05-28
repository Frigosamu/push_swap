/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:52:12 by mariredo          #+#    #+#             */
/*   Updated: 2026/05/27 15:21:25 by mariredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk_size(t_stack *a)
{
	int	chunk;

	chunk = 0;
	if (a->size >= 100)
		chunk = a->size / 6;
	else
		chunk = a->size / 12;
	if (chunk < 1)
		chunk = 1;
	return (chunk);
}
