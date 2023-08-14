# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 09:35:58 by mfornah           #+#    #+#              #
#    Updated: 2023/04/08 11:58:35 by mfornah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## EXECUTABLE ##
NAME = pipex

## COMPILATION ##
CC = gcc
CFLAGS = -Wall -Werror  -Wextra -g3 -fsanitize=address

## INCLUDE ##
LIBS_PATH = ./libft/libft.a

#Chedk Leak memory
#LEAK = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s

## VARIABLES ##
AR = @ar rcs
RM = @rm -f
MAKE_NOPRINT = $(MAKE) --no-print-directory -C
#LINK = -L $(LIBS_PATH)


## SOURCE FILE ##
SRC = find_path.c  pipex.c utils.c child.c main.c
OBJS = ${SRC:.c=.o}


## COLORS ##
END		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m


## RULES ##
all: libft $(NAME)

libft:
	@echo "$(NAME): $(BLUE)Generating... Just a minute$(RESET)"
	@make -sC ./libft/srcs
	@echo "$(NAME): $(GREEN)Done!$(RESET)"

%.o :%.c 
	@echo "${BLUE} ◎ $(YELLOW)Compiling   ${RED}→   $(WHITE)$< $(END)"	
	@$(CC) $(CFLAGS) -c -o $@ $< 
	
$(NAME) : libft $(OBJS)
	@make -sC ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a
	clear
	@echo "$(GREEN)You Created $(NAME)$(END)"


## CLEANNING ##
clean:
	@$(RM) $(OBJS)
	@cd ./libft && make clean 
	@echo "$(GREEN)$(NAME): $(RED)→ $(BLUE) Cleaning... $(END)"
	@echo "$(GREEN)$(NAME): $(RED)→ $(YELLOW) the files(*.o) were deleted $(END)"

## REMOVING .O FILES AND .A FILES ##
fclean: clean
	$(RM) $(NAME) $(OBJS) $(libft)
	@make fclean -sC ./libft
	@echo "$(GREEN)$(NAME): $(RED) → $(BLUE)was deleted$(END)"
	
norm:
	-@norminette  $(SRCS_PATH)
	-@norminette  $(LIBS_PATH)

	

## REMOVING AND RUNNING ##
re: fclean all

.PHONY: all re clean fclean  norm



