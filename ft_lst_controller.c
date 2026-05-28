/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:21:18 by efiguere          #+#    #+#             */
/*   Updated: 2026/05/27 16:03:52 by mariredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->idx = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_lst_add_back(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return ;
	if (stack->size == 0)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		new->prev = stack->bottom;
		new->next = NULL;
		stack->bottom->next = new;
		stack->bottom = new;
	}
	stack->size++;
}

void	ft_lst_add_front(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return ;
	if (stack->size == 0)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->top->prev = new;
		new->next = stack->top;
		new->prev = NULL;
		stack->top = new;
	}
	stack->size++;
}

t_node	*ft_pop(t_stack *stack)
{
	t_node	*aux_node;

	if (!stack || stack->size == 0)
		return (NULL);
	aux_node = stack->top;
	if (stack->size >= 2)
	{
		stack->top = aux_node->next;
		stack->top->prev = NULL;
	}
	else
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	aux_node->next = NULL;
	stack->size--;
	return (aux_node);
}

t_node	*ft_pop_bottom(t_stack *stack)
{
	t_node	*aux_node;

	if (!stack || stack->size == 0)
		return (NULL);
	aux_node = stack->bottom;
	if (stack->size >= 2)
	{
		stack->bottom = aux_node->prev;
		stack->bottom->next = NULL;
	}
	else
	{
		stack->bottom = NULL;
		stack->top = NULL;
	}
	aux_node->prev = NULL;
	stack->size--;
	return (aux_node);
}
