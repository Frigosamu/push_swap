/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:02:44 by mariredo          #+#    #+#             */
/*   Updated: 2026/05/27 16:20:52 by mariredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				idx;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

typedef struct s_stats
{
	int				is_bench;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_stats;

int					is_number(char *s);
long				ft_atol(char *s);
void				parse_args(int argc, char **argv, t_stack *a, int offset);
void				parse_split(char **split, t_stack *a);
void				ft_checkdupli(t_stack *a);
int					ft_is_sorted(t_stack *a);
void				init_stack(t_stack *stack);
void				init_stat(t_stats *stat);
double				ft_compute_disorder(t_stack *stack);
int					get_flag(int argc, char **argv, int *mode, t_stats *stats);

// intermediate functions
int					get_index(t_stack *a, int value);
int					get_max(t_stack *b);
int					get_max_position(t_stack *b);
int					ft_chunk_size(t_stack *a);
void				push_chunks_to_b(t_stack **stack_list, int min, int max,
						t_stats *stat);
void				ft_medium(t_stack *a, t_stack *b, t_stats *stat);
t_stack				**init_stack_list(t_stack *a, t_stack *b);
void				ft_complex_radix(t_stack *a, t_stack *b, t_stats *stat);
void				ft_adaptive(t_stack *a, t_stack *b, t_stats *stat);
void				algorithm_mode(int mode, t_stack *a, t_stack *b,
						t_stats *stat);
void				ft_idx_stack(t_stack *a);

// debug
void				print_stack(t_stack *stack);

// error
void				ft_error(void);

// list controller
t_node				*ft_lstnew(int value);
void				ft_lst_add_back(t_stack *stack, t_node *new);
void				ft_lst_add_front(t_stack *stack, t_node *new);
t_node				*ft_pop(t_stack *stack);
t_node				*ft_pop_bottom(t_stack *stack);

// free
void				ft_free_stack(t_stack *stack);
void				free_split(char **split);

// push swap
void				ft_swap_a(t_stack *stack_a);
void				ft_swap_b(t_stack *stack_b);
void				ft_swap_ab(t_stack *stack_a, t_stack *stack_b);
void				ft_push_a(t_stack *stack_a, t_stack *stack_b);
void				ft_push_b(t_stack *stack_a, t_stack *stack_b);

// rotate
void				ft_rotate_a(t_stack *stack_a);
void				ft_rotate_b(t_stack *stack_b);
void				ft_rotate_ab(t_stack *stack_a, t_stack *stack_b);

// reverse rotate
void				ft_reverse_rotate_a(t_stack *stack_a);
void				ft_reverse_rotate_b(t_stack *stack_b);
void				ft_reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b);

// swap
void				ft_sa(t_stack *a, t_stats *stats);
void				ft_sb(t_stack *b, t_stats *stats);
void				ft_ss(t_stack *a, t_stack *b, t_stats *stats);

// rotate
void				ft_ra(t_stack *a, t_stats *stats);
void				ft_rb(t_stack *b, t_stats *stats);
void				ft_rr(t_stack *a, t_stack *b, t_stats *stats);

// reverse rotate
void				ft_rra(t_stack *a, t_stats *stats);
void				ft_rrb(t_stack *b, t_stats *stats);
void				ft_rrr(t_stack *a, t_stack *b, t_stats *stats);

// push
void				ft_pa(t_stack *a, t_stack *b, t_stats *stats);
void				ft_pb(t_stack *a, t_stack *b, t_stats *stats);

// simple
void				ft_simple(t_stack *a, t_stack *b, t_stats *stat);
t_node				*ft_get_min(t_stack *stack);
int					ft_get_position(t_stack *stack, t_node *target);

#endif
