# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srequiem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/04 15:52:40 by srequiem          #+#    #+#              #
#    Updated: 2018/05/03 11:57:13 by srequiem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libft.a
SRCS =  ft_putchar.c \
	ft_strdupn.c	\
	ft_power.c		\
	ft_sqrt.c		\
	ft_free2tab.c	\
	ft_sort.c       \
	ft_swap.c       \
	ft_lstmap.c	    \
	ft_lstdel.c		\
	ft_lstiter.c	\
	ft_lstadd.c		\
	ft_lstdelone.c	\
	ft_lstnew.c		\
	ft_len_int.c	\
	ft_itoa.c		\
	ft_strsplit.c	\
	ft_is_space.c	\
	ft_strtrim.c	\
	ft_strjoin.c	\
	ft_strsub.c		\
	ft_strnequ.c	\
	ft_strequ.c		\
	ft_strmapi.c	\
	ft_strmap.c		\
	ft_striteri.c	\
	ft_striter.c	\
	ft_strclr.c		\
	ft_strdel.c		\
	ft_strnew.c		\
	ft_memdel.c		\
	ft_memmove.c	\
	ft_strlcat.c	\
	ft_memchr.c		\
	ft_memcmp.c		\
	ft_memccpy.c	\
	ft_memalloc.c   \
	ft_putstr.c		\
	ft_putendl.c	\
	ft_putendl_fd.c \
	ft_putnbr.c		\
	ft_putchar_fd.c \
	ft_putstr_fd.c  \
	ft_putnbr_fd.c  \
	ft_atoi.c		\
	ft_bzero.c		\
	ft_isalnum.c	\
	ft_isalpha.c	\
	ft_isascii.c	\
	ft_isdigit.c	\
	ft_islower.c	\
	ft_isprint.c	\
	ft_isupper.c	\
	ft_memcpy.c		\
	ft_memset.c		\
	ft_strcat.c		\
	ft_strchr.c		\
	ft_strcmp.c		\
	ft_strcpy.c		\
	ft_strdup.c		\
	ft_strlen.c		\
	ft_strncat.c	\
	ft_strncmp.c	\
	ft_strncpy.c	\
	ft_strnstr.c	\
	ft_strrchr.c	\
	ft_strstr.c		\
	ft_tolower.c	\
	ft_toupper.c	

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	@ar crs libft.a $(OBJS)

$(OBJS):
	$(CC) -c $(CFLAGS) $(SRCS)

obj/%.o: src/%.c
	gcc $(CFLAGS) -c $< -o $@ -I includes

so:
	$(CC) -fPIC $(CFLAGS) $(SRCS) -shared -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
