# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: appinha <appinha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/08 15:21:34 by apuchill          #+#    #+#              #
#    Updated: 2020/11/07 18:45:01 by appinha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
#CFLAGS		=
RM			= /bin/rm -f

NAME		= minirt

LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_DIR	= libft/
LIB_FLAGS	= -L $(LIBFT_DIR) -lft
MLX_FLAGS	= -lbsd -lmlx -lXext -lX11
INCLUDES	= -I includes -I $(LIBFT_DIR)/includes/

SRC_DIR		= srcs/
SRC_F		= tests.c main.c errors.c mlx_oper.c get_scene.c get_scene_aux.c utils_1.c
SRCS		= $(addprefix $(SRC_DIR), $(SRC_F))

OBJ_DIR		= obj/
OBJS		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))


$(OBJ_DIR)%.o :	$(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
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
			@./minirt "scenes/cylinder.rt"

bonus:		all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus tests rt
