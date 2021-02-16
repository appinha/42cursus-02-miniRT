# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/08 15:21:34 by apuchill          #+#    #+#              #
#    Updated: 2021/02/16 13:51:39 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT

DIR_SRCS	= srcs
DIR_OBJS	= objs
SUBDIRS		= main errors scene vectors bitmap

SRCS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_DIR	= libft/
LIB_FLAGS	= -L $(LIBFT_DIR) -lft
MLX_FLAGS	= -lbsd -lmlx -lXext -lX11
INCLUDES	= -I includes -I $(LIBFT_DIR)/includes/

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			= /bin/rm -f
NORM		= ~/.norminette/norminette.rb

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
			@make -C $(LIBFT_DIR)

$(NAME):	$(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIB_FLAGS)

all:		$(NAME)

clean:
			@make clean -C $(LIBFT_DIR)
			@$(RM) $(OBJS)

fclean:		clean
			@make fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)

re:			fclean all

tests:
			@$(RM) $(OBJS) $(NAME)

rt:			tests all
			./minirt "scenes/base_file.rt"

norm:
			@$(NORM) */*.h */*/*.h */*/*.c */*/*/*.c

norm2:
			@$(NORM) */minirt.h */errors.h */scene.h */vectors.h */bitmap.h && echo ""
			@$(NORM) srcs/main/*.c && echo ""
			@$(NORM) srcs/errors/*.c && echo ""
			@$(NORM) srcs/scene/*.c && echo ""
			@$(NORM) srcs/vectors/*.c && echo ""
			@$(NORM) srcs/bitmap/*.c

.PHONY:		all clean fclean re tests rt
