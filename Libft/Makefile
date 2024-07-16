# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 13:02:21 by barjimen          #+#    #+#              #
#    Updated: 2024/07/16 23:16:54 by barjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILE_C =	ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_strlen.c			\
			ft_memset.c			\
			ft_bzero.c			\
			ft_memcpy.c			\
			ft_strlcpy.c		\
			ft_strlcat.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strncmp.c		\
			ft_atoi.c			\
			ft_memmove.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_calloc.c			\
			ft_strnstr.c		\
			ft_strdup.c			\
			ft_substr.c			\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putnbr_fd.c		\
			ft_putendl_fd.c		\
			ft_strjoin.c		\
			ft_striteri.c		\
			ft_strmapi.c		\
			ft_itoa.c			\
			ft_strtrim.c		\
			ft_split.c			\
			get_next_line.c		\
			ft_printf.c			\
			ft_point.c			\
			ft_low_x_or_up_x.c	\
			ft_hexa_p.c			\
			ft_hexa.c			
			
			

FILE_C_BONUS =	ft_lstnew_bonus.c		\
				ft_lstadd_front_bonus.c	\
				ft_lstsize_bonus.c		\
				ft_lstlast_bonus.c		\
				ft_lstadd_back_bonus.c	\
				ft_lstdelone_bonus.c	\
				ft_lstclear_bonus.c		\
				ft_lstiter_bonus.c		\
				ft_lstmap_bonus.c		\


FILE_O = ${FILE_C:.c=.o}
FILE_O_BONUS = ${FILE_C_BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${FILE_O}
	ar -rcs ${NAME} ${FILE_O}

all: $(NAME)

clean: 
	rm -f $(FILE_O) $(FILE_O_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(FILE_O_BONUS)
	ar -rcs ${NAME} ${FILE_O} ${FILE_O_BONUS}
	@#make "FILE_C = $(FILE_C_BONUS)"

.Phony: all clean fclean re
