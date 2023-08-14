# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 16:02:53 by mfornah           #+#    #+#              #
#    Updated: 2023/03/26 14:34:09 by mfornah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC    = gcc

CFLAGS   = -Werror -Wall -Wextra

# INC = ./include/

SRC = ft_isalnum.c ft_isalpha.c ft_isdigit.c \
	ft_isascii.c ft_isprint.c ft_strlen.c\
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
	ft_strchr.c ft_split.c ft_strrchr.c ft_strncmp.c\
	ft_memchr.c ft_memcmp.c ft_atoi.c ft_strnstr.c\
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_itoa.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c\
	ft_strmapi.c ft_striteri.c ft_putendl_fd.c get_next_line.c ft_printf.c\
	ft_checkparam.c ft_hexpointer.c ft_print_pa.c \
	ft_print_putchar.c ft_print_putstr.c ft_print_unsingened.c\
	ft_printf_hexlong.c ft_printf_ptr.c ft_printf_putnbr.c \
	ft_printf.c ft_putnbr_base_uns.c ft_strlen2.c ft_checkbase.c

	
	

 SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c\
			ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstlast_bonus.c \



OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

$(NAME) : $(OBJS) $(OBJS_BONUS)
		@ar rsc $(NAME) $(OBJS) 
RM = @rm -f

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) 

fclean: clean
	$(RM) $(NAME) $(OBJS) $(OBJS_BONUS)

re: fclean all

.PHONY: all re clean fclean 