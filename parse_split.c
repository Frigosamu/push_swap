/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 12:13:47 by mariredo          #+#    #+#             */
/*   Updated: 2026/05/27 16:22:22 by mariredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_split(char **split, t_stack *a)
{
	int		j;
	long	num;

	j = 0;
	while (split[j])
	{
		if (!is_number(split[j]))
		{
			free_split(split);
			ft_free_stack(a);
			ft_error();
		}
		num = ft_atol(split[j]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_split(split);
			ft_free_stack(a);
			ft_error();
		}
		ft_lst_add_back(a, ft_lstnew((int)num));
		j++;
	}
}
