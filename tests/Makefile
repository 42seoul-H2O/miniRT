# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 21:16:07 by hyunjuki          #+#    #+#              #
#    Updated: 2023/04/23 11:23:04 by hocsong          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = test_executable

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIB_PATH = ../lib
LIBFT_PATH = $(LIB_PATH)/libft
MLX_PATH = $(LIB_PATH)/mlx

SRCS_NAME = init.c \
			ft_atof.c \
			key_hook.c \
			color.c \
			parser_main.c \
			parser_ambient.c \
			parser_camera.c \
			parser_cylinder.c \
			parser_light.c \
			parser_plane.c \
			parser_sphere.c \
			render.c \
			vector_oper1.c \
			vector_oper2.c \
			shapelst_oper1.c \
			matrix_oper1.c \
			matrix_oper2.c \
			ray.c \
			sphere.c \
			camera.c

SRCS_PATH = ../srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

TEST_SRCS = test_matrix.c \
			puterr_and_exit.c

INCS = -I../include -I$(LIBFT_PATH) -I$(MLX_PATH)

all : $(NAME)

$(NAME) :
	@echo building LIBFT...
	@$(MAKE) -C $(LIBFT_PATH)
	@echo building MiniLibX...
	@$(MAKE) --silent -C $(MLX_PATH)
	@cp $(MLX_PATH)/libmlx.dylib ./libmlx.dylib
	@echo Compiling $(NAME)
	@$(CC) $(CFLAGS) $(INCS) $(SRCS) $(TEST_SRCS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	@$(MAKE) --silent -C $(LIBFT_PATH) clean
	@$(MAKE) --silent -C $(MLX_PATH) clean

fclean : clean
	@echo delete executable file
	@rm -f $(NAME)
	@rm -f libmlx.dylib
	@rm -rf test_executable.dSYM
	@$(MAKE) --silent -C $(LIBFT_PATH) fclean

re :
	@$(MAKE) fclean
	@$(MAKE) all

bonus :
	@echo there is no bonus!

.PHONY : all clean fclean re bonus