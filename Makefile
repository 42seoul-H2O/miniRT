# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 21:16:07 by hyunjuki          #+#    #+#              #
#    Updated: 2023/04/01 12:42:20 by hyunjuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIB_PATH = ./lib
LIBFT_PATH = $(LIB_PATH)/libft
MLX_PATH = $(LIB_PATH)/mlx

SRCS_NAME = main.c 
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
	@echo Linking miniRT executable file
	@$(CC) $(CFLAGS) $(OBJS) $(INCS) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@echo building obj files : $<
	@$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

clean :
	@echo delete object files
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean

fclean : clean
	@echo delete executable file
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re :
	@$(MAKE) fclean
	@$(MAKE) all

bonus :
	@echo there is no bonus!

.PHONY : all clean fclean re bonus