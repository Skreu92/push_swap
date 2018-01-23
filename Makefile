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

FLAGS= -Wall -Werror -Wextra

SRC_PS=	p_s/difficult.c\
	p_s/push_swap.c\
	libps/swap_stack.c\
	libps/push_stack.c\
	libps/rotate_stack.c\
	libps/reverse_rotate_stack.c\
	p_s/easy.c\
	p_s/path_a.c\
	p_s/path_b.c\
	p_s/stack_manip.c\
	p_s/check.c\
	p_s/move.c\

SRC_CK = c/checker.c\
	c/read.c\
	libps/swap_stack.c\
	libps/push_stack.c\
	libps/rotate_stack.c\
	libps/reverse_rotate_stack.c\
	p_s/check.c\
	p_s/stack_manip.c\
	p_s/easy.c\

PS = push_swap 
CK = checker
CC = gcc
OBJ_PS = $(SRC_PS:.c=.o)
OBJ_CK = $(SRC_CK:.c=.o)
RM = rm -rf
INC = -I includes/
FT = -L libft/ -lft
CG = \033[92m
CY =  \033[93m
CE = \033[0m

all: $(PS) $(CK)


$(PS): $(OBJ_PS)
	@echo "\033[K$(CY)[PS] :$(CE) $(CG)Creating Library$(CE)\033[1A";
	@make -C libft/ fclean
	@make -C libft/
	@$(CC)  $(FLAGS) $(INC) -o $(PS) $(OBJ_PS) $(FT)
	@echo "\033[K$(CY)[PS] :$(CE) $(CG)Compiled PS$(CE)";

$(CK): $(OBJ_CK)
	@echo "\033[K$(CY)[PS] :$(CE) $(CG)Creating Library$(CE)\033[1A";
	@$(CC)  $(FLAGS) $(INC) -o $(CK) $(OBJ_CK) $(FT)
	@echo "\033[K$(CY)[PS] :$(CE) $(CG)Compiled CK$(CE)";

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[K$(CY)[PS] :$(CE) $(CG)Compiling $<$(CE) \033[1A";

clean:
	@$(RM) $(OBJ_PS)
	@$(RM) $(OBJ_CK)
	@make -C libft/ clean
	@echo "\033[K$(CY)[PS] :$(CE) $(CG)Cleaning Object files $(CE)";

fclean: clean
	@$(RM) $(PS)
	@$(RM) $(CK)
	@make -C libft/ fclean
	@echo "\033[K$(CY)[PS] :$(CE) $(CG)Cleaning PS/CK $(CE)";

re: fclean all

.PHONY : all clean fclean re
