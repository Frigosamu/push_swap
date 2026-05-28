/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efiguere <efiguere@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:25:43 by mariredo          #+#    #+#             */
/*   Updated: 2026/05/28 12:27:27 by efiguere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_flag(int argc, char **argv, int *mode, t_stats *stats)
{
	int	i;

	i = 1;
	*mode = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!ft_strcmp(argv[i], "--simple") && *mode == 0)
			*mode = 1;
		else if (!ft_strcmp(argv[i], "--medium") && *mode == 0)
			*mode = 2;
		else if (!ft_strcmp(argv[i], "--complex") && *mode == 0)
			*mode = 3;
		else if (!ft_strcmp(argv[i], "--adaptive") && *mode == 0)
			*mode = 4;
		else if (!ft_strcmp(argv[i], "--bench") && stats->is_bench == 0)
			stats->is_bench = 1;
		else
			ft_error();
		i++;
	}
	if (*mode == 0)
		*mode = 4;
	return (i);
}

void	ft_adaptive_bench(double disorder)
{
	if (disorder < 20.00)
		ft_printf("[bench] strategy: Adaptive / O(n²)\n");
	else if (disorder >= 20.00 && disorder < 50.00)
		ft_printf("[bench] strategy: Adaptive / O(n√n)\n");
	else if (disorder >= 50.00)
		ft_printf("[bench] strategy: Adaptive / O(nlogn)\n");
}

void	ft_print_benchmark(t_stats *stat, double disorder, int mode)
{
	ft_printf("[bench] disorder: %f%%\n", disorder);
	if (mode == 1)
		ft_printf("[bench] strategy: Simple / O(n²)\n");
	else if (mode == 2)
		ft_printf("[bench] strategy: Medium / O(n√n)\n");
	else if (mode == 3)
		ft_printf("[bench] strategy: Complex / O(nlogn)\n");
	else
		ft_adaptive_bench(disorder);
	ft_printf("[bench] total_ops: %d\n", stat->total);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", stat->sa,
		stat->sb, stat->ss, stat->pa, stat->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		stat->ra, stat->rb, stat->rr, stat->rra, stat->rrb, stat->rrr);
}

void	algorithm_mode(int mode, t_stack *a, t_stack *b, t_stats *stat)
{
	if (mode == 1)
		ft_simple(a, b, stat);
	else if (mode == 2)
		ft_medium(a, b, stat);
	else if (mode == 3)
		ft_complex_radix(a, b, stat);
	else if (mode == 4)
		ft_adaptive(a, b, stat);
}

int	main(int argc, char **argv)
{
	t_stack	a_stack;
	t_stack	b_stack;
	t_stats	stat;
	int		mode;
	double	aux;

	init_stat(&stat);
	init_stack(&a_stack);
	init_stack(&b_stack);
	aux = (double)get_flag(argc, argv, &mode, &stat);
	parse_args(argc, argv, &a_stack, (int)aux);
	ft_checkdupli(&a_stack);
	ft_idx_stack(&a_stack);
	aux = ft_compute_disorder(&a_stack) * 100.0;
	if (ft_is_sorted(&a_stack))
		return (ft_free_stack(&a_stack), ft_free_stack(&b_stack), 0);
	algorithm_mode(mode, &a_stack, &b_stack, &stat);
	if (stat.is_bench)
		ft_print_benchmark(&stat, aux, mode);
	ft_free_stack(&a_stack);
	ft_free_stack(&b_stack);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	t_stack	a_stack;
	t_stack	b_stack;
	t_stats	stats;

	a_stack.top = NULL;
	a_stack.bottom = NULL;
	a_stack.size = 0;
	b_stack.top = NULL;
	b_stack.bottom = NULL;
	b_stack.size = 0;
	ft_bzero(&stats, sizeof(t_stats));
	parse_args(argc, argv, &a_stack);
	ft_checkdupli(&a_stack);
	if (ft_is_sorted(&a_stack))
	{
		ft_printf("Already sorted\n");
		return (0);
	}
	ft_printf("\n(intermediate)CHUNK TEST\n");
	print_stack(&a_stack);
	chunk_to_b(&a_stack, &b_stack, 0, 2);
	move_to_a(&a_stack, &b_stack);
	ft_printf("\nSTACK A AFTER CHUNKS:\n");
	print_stack(&a_stack);
	ft_printf("SORTED = %d\n", ft_is_sorted(&a_stack));
	ft_free_stack(&a_stack);
	ft_free_stack(&b_stack);
	a_stack.top = NULL;
	a_stack.bottom = NULL;
	a_stack.size = 0;
	b_stack.top = NULL;
	b_stack.bottom = NULL;
	b_stack.size = 0;
	parse_args(argc, argv, &a_stack);
	ft_printf("\nsimple test\n");
	print_stack(&a_stack);
	ft_simple(&a_stack, &b_stack, &stats, 0);
	ft_printf("\nSTACK A AFTER SIMPLE SORT:\n");
	print_stack(&a_stack);
	ft_printf("SORTED = %d\n", ft_is_sorted(&a_stack));
	ft_free_stack(&a_stack);
	ft_free_stack(&b_stack);
	return (0);
}
*/
