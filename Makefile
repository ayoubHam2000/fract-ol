# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 17:21:43 by aben-ham          #+#    #+#              #
#    Updated: 2022/02/08 15:38:29 by aben-ham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-Wall -Wextra -Werror
CFLAGS = -g  -I ./includes
DEPFLAGS = -MMD -MF
FRAMEWORK = -framework opengl -framework Appkit

FILES = \
	scripts/complex/complex.c \
	scripts/complex/ncomplex.c \
	scripts/events/on_mouse_down.c \
	scripts/events/on_mouse_move.c \
	scripts/events/on_mouse_up.c \
	scripts/events/on_key_up.c \
	scripts/fract/mandelbrot_set.c \
	scripts/fract/julia_set.c \
	scripts/graph/graph.c \
	scripts/graph/init_mlx.c \
	scripts/graph/graph_loop.c \
	scripts/utils/set_rgb.c \
	scripts/utils/get_color.c \
	main.c

NAME = fractol
MLX_LIB_NAME = libmlx.a

MLX_DIR = ./minilibx_opengl

OBJ_DIR = OUT/
OBJ_FILES = $(addprefix $(OBJ_DIR), $(FILES:%.c=%.o))
DEPS_FILES = $(OBJ_FILES:%.o=%.d)

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
