# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 20:15:20 by apuchill          #+#    #+#              #
#    Updated: 2020/10/31 12:45:40 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f

NAME	= libft.a

INCLUDE	= includes

SRC_DIR	= srcs/
SRC_F	= ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_isspace.c ft_isblank.c ft_isxdigit.c ft_iscntrl.c ft_isgraph.c \
			ft_ispunct.c ft_islower.c ft_isupper.c ft_tolower.c ft_toupper.c \
			ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strdup.c ft_strndup.c ft_calloc.c \
			ft_strlen.c ft_strchr.c ft_strrchr.c \
			ft_strstr.c ft_strnstr.c ft_strcpy.c ft_strncpy.c ft_strlcpy.c \
			ft_strcmp.c ft_strncmp.c ft_strcat.c ft_strncat.c ft_strlcat.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
			ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_swap.c ft_atoi.c ft_itoa.c ft_sqrt.c ft_pow.c \
			ft_lstsize.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c \
			ft_lstnew.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
			ft_printf.c ft_printf_flags.c ft_printf_cs_pct.c ft_printf_utils.c \
			ft_printf_piduxo.c ft_printf_fg.c ft_printf_e.c ft_ftoa_rnd.c \
			get_next_line.c
SRCS		= $(addprefix $(SRC_DIR), $(SRC_F))

OBJ_DIR		= obj/
OBJS		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))


${OBJ_DIR}%.o :	${SRC_DIR}%.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
			@ranlib $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
