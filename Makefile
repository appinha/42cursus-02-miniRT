# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: appinha <appinha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/08 15:21:34 by apuchill          #+#    #+#              #
#    Updated: 2021/02/03 08:37:01 by appinha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minirt

DIR_SRCS	= srcs
DIR_OBJS	= objs
DIRS		= main errors scene tests
SRCS_DIRS	= $(foreach dir, $(DIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(DIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS		= $(foreach dir, $(SRCS_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_DIR	= libft/
LIB_FLAGS	= -L $(LIBFT_DIR) -lft
MLX_FLAGS	= -lbsd -lmlx -lXext -lX11
INCLUDES	= -I includes -I $(LIBFT_DIR)/includes/

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
#CFLAGS		=
RM			= /bin/rm -f
NORM		= ~/.norminette/norminette.rb


$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIB_FLAGS)

$(LIBFT):
			@make -C $(LIBFT_DIR)

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
			./minirt "scenes/cylinder.rt"

norm:
			@$(NORM)

norm2:
			@$(NORM) */minirt.h */errors.h */scene.h && echo ""
			@$(NORM) srcs/main/*.c && echo ""
			@$(NORM) srcs/errors/*.c && echo ""
			@$(NORM) srcs/scene/*.c

bonus:		all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus tests rt
