# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 17:21:43 by aben-ham          #+#    #+#              #
#    Updated: 2022/02/03 20:58:31 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -I ./includes
DEPFLAGS = -MMD -MF
FRAMEWORK = -framework opengl -framework Appkit

FILES = \
	main.c

NAME = fractol
MLX_LIB_NAME = libmlx.a

MLX_DIR = ./minilibx_opengl

OBJ_DIR = OUT/
OBJ_FILES = $(OBJ_DIR)$(FILES:.c=.o)
DEPS_FILES = $(OBJ_FILES:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ_FILES) $(MLX_LIB_NAME)
	gcc $(MLX_LIB_NAME) $(FRAMEWORK) $(OBJ_FILES) -o $(NAME)

$(OBJ_FILES) : $(OBJ_DIR)%.o:%.c
	mkdir -p $(dir $@)
	gcc  $(CFLAGS) -c $(@:OUT/%.o=%.c) $(DEPFLAGS) $(@:.o=.d) -o $@

$(MLX_LIB_NAME) :
	make -C $(MLX_DIR)
	mv $(MLX_DIR)/$(MLX_LIB_NAME) .

-include $(DEPS_FILES)

########################

clean :
	make -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(MLX_LIB_NAME)

re : fclean all
