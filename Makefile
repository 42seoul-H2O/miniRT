# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 21:16:07 by hyunjuki          #+#    #+#              #
#    Updated: 2023/05/08 12:13:12 by hocsong          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIB_PATH = ./lib
LIBFT_PATH = $(LIB_PATH)/libft
MLX_PATH = $(LIB_PATH)/mlx

SRCS_NAME = main.c \
			init.c \
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
			matrix_oper3.c \
			ray.c \
			sphere.c \
			plane.c \
			cylinder.c \
			cylinder2.c \
			camera.c \
			get_diffuse_radiance.c

SRCS_PATH = ./srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

INCS = -I./include -I$(LIBFT_PATH) -I$(MLX_PATH)

all : $(NAME)

$(NAME) : $(OBJS)
	@echo building LIBFT...
	@$(MAKE) -C $(LIBFT_PATH)
	@echo building MiniLibX...
	@$(MAKE) --silent -C $(MLX_PATH)
	@cp $(MLX_PATH)/libmlx.dylib ./libmlx.dylib
	@echo Linking miniRT executable file
	@$(CC) $(CFLAGS) $(OBJS) $(INCS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@echo building obj files : $<
	@$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

clean :
	@echo delete object files
	@rm -f $(OBJS)
	@$(MAKE) --silent -C $(LIBFT_PATH) clean
	@$(MAKE) --silent -C $(MLX_PATH) clean

fclean : clean
	@echo delete executable file
	@rm -f $(NAME)
	@rm -f libmlx.dylib
	@$(MAKE) --silent -C $(LIBFT_PATH) fclean

re :
	@$(MAKE) fclean
	@$(MAKE) all

bonus :
	@echo there is no bonus!

.PHONY : all clean fclean re bonus