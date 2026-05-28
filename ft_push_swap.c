/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:13:18 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/27 16:22:45 by mariredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack *stack_a)
{
	int	aux_value;
	int	aux_idx;

	if (!stack_a || stack_a->size < 2)
		return ;
	aux_value = stack_a->top->value;
	stack_a->top->value = stack_a->top->next->value;
	stack_a->top->next->value = aux_value;
	aux_idx = stack_a->top->idx;
	stack_a->top->idx = stack_a->top->next->idx;
	stack_a->top->next->idx = aux_idx;
}

void	ft_swap_b(t_stack *stack_b)
{
	int	aux_value;
	int	aux_idx;

	if (!stack_b || stack_b->size < 2)
		return ;
	aux_value = stack_b->top->value;
	stack_b->top->value = stack_b->top->next->value;
	stack_b->top->next->value = aux_value;
	aux_idx = stack_b->top->idx;
	stack_b->top->idx = stack_b->top->next->idx;
	stack_b->top->next->idx = aux_idx;
}

void	ft_swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
}

void	ft_push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*aux_node;

	if (!stack_b || stack_b->size == 0)
		return ;
	aux_node = ft_pop(stack_b);
	ft_lst_add_front(stack_a, aux_node);
}

void	ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*aux_node;

	if (!stack_a || stack_a->size == 0)
		return ;
	aux_node = ft_pop(stack_a);
	ft_lst_add_front(stack_b, aux_node);
}
