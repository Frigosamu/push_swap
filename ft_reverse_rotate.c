/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:57:20 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/18 12:02:30 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a(t_stack *stack_a)
{
	t_node	*aux_node;

	if (!stack_a || stack_a->size == 0)
		return ;
	aux_node = ft_pop_bottom(stack_a);
	ft_lst_add_front(stack_a, aux_node);
}

void	ft_reverse_rotate_b(t_stack *stack_b)
{
	t_node	*aux_node;

	if (!stack_b || stack_b->size == 0)
		return ;
	aux_node = ft_pop_bottom(stack_b);
	ft_lst_add_front(stack_b, aux_node);
}

void	ft_reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	ft_reverse_rotate_a(stack_a);
	ft_reverse_rotate_b(stack_b);
}
