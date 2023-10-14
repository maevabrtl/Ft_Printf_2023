# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Maya <Maya@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 13:26:09 by mabertha          #+#    #+#              #
#    Updated: 2023/10/09 21:06:43 by Maya             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_itoabase.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
ft_tolower.c ft_toupper.c ft_utoabase.c ft_strndup.c ft_lstadd_back.c \
ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstfree.c ft_lstiter.c \
ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS = $(SRCS:.c=.o)
INC = libft.h

#*****************************************************************************#
#                                   Rules                                     #
#*****************************************************************************#

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

#*****************************************************************************#
#                                Compilation                                  #
#*****************************************************************************#

%.o: %.c
	$(CC) $(CC_FLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(INC)
	ar rcs $(NAME) $(OBJS)
