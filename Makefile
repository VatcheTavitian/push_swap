# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 11:15:57 by vtavitia          #+#    #+#              #
#    Updated: 2023/05/22 14:29:11 by vtavitia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LDLIBS = -L./Libft -lft

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
BONUS_SRC = $(filter-out ./main.c, $(wildcard ./bonus/*.c) $(wildcard ./*.c))
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./Libft
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $(NAME)

bonus: $(BONUS_OBJ)
	make -C ./Libft
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $(BONUS_NAME)

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
	make clean -C ./Libft

fclean:clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	make fclean -C ./Libft
	
re: fclean all

.PHONY: all clean fclean bonus re
