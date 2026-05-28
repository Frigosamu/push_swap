# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariredo <mariredo@student.42.malaga.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/14 19:20:45 by mariredo          #+#    #+#              #
#    Updated: 2026/05/27 12:18:39 by mariredo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

SRC =	is_number.c			\
		ft_atol.c			\
		ft_checkdupli.c		\
		ft_error.c			\
		ft_free.c			\
		init_utils.c		\
		ft_is_sorted.c		\
		ft_index.c			\
		ft_lst_controller.c	\
		ft_push_swap.c		\
		ft_reverse_rotate.c	\
		ft_rotate.c			\
		ft_rules_push.c		\
		ft_rules_reverse.c	\
		ft_rules_rotate.c	\
		ft_rules_swap.c		\
		ft_simple.c			\
		ft_medium.c			\
		ft_complex.c		\
		ft_adaptive.c		\
		parse_args.c		\
		parse_split.c		\
		ft_chunk_size.c		\
		main.c

CHECKER_SRC =	checker.c

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

all: libft $(NAME)

bonus: libft $(CHECK)

libft:
	@make -C libft

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L./libft -lft -o $(NAME)

$(CHECK): $(CHECKER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) -L./libft -lft -o $(CHECK)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(CHECKER_OBJ)
	@make clean -C libft

fclean: clean
	$(RM) $(NAME) $(CHECK)
	@make fclean -C libft

re: fclean all

.PHONY: all bonus clean fclean re libft