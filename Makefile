# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Etienne <etranchi@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/03 22:48:24 by Etienne           #+#    #+#              #
#    Updated: 2017/10/03 22:48:28 by Etienne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Werror -Wextra -O0 -g -fsanitize=address

SRC=libps/swap_stack.c\
	libps/push_stack.c\
	libps/rotate_stack.c\
	libps/reverse_rotate_stack.c\
	p_s/push_swap.c\
	p_s/difficult.c\
	p_s/easy.c\
	p_s/path_a.c\
	p_s/path_b.c\
	p_s/stack_manip.c\
	p_s/check.c\
	p_s/move.c\

NAME = push_swap 
CC = gcc
OBJ = $(SRC:.c=.o)
RM = rm -rf
INC = -I includes/
FT = -L libft/ -lft
CG = \033[92m
CY =  \033[93m
CE = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[K$(CY)[PS] :$(CE) $(CG)Creating Library$(CE)\033[1A";
	@make -C libft/ fclean
	@make -C libft/
	@$(CC)  $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(FT)
	@echo "\033[K$(CY)[PS] :$(CE) $(CG)Compiled PS$(CE)";

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[K$(CY)[PS] :$(CE) $(CG)Compiling $<$(CE) \033[1A";

clean:
	@$(RM) $(OBJ)
	@echo "\033[K$(CY)[PS] :$(CE) $(CG)Cleaning Object files $(CE)";

fclean: clean
	@$(RM) $(NAME)
	@make -C libft/ fclean
	@echo "\033[K$(CY)[PS] :$(CE) $(CG)Cleaning PS $(CE)";

re: fclean all

.PHONY : all clean fclean re
