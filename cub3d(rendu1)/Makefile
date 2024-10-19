# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppuivif <ppuivif@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 07:00:41 by tebandam          #+#    #+#              #
#    Updated: 2024/10/17 11:25:33 by ppuivif          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================== NAME ===================#

NAME = cub3D

#================ COMPILATOR ================#

CC = cc

#=================== FLAGS ==================#

CFLAGS = -Wall -Wextra -Werror -I./MLX42/include -g

MLXFLAGS= MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

#============= MANDATORY SOURCES ============#

SRCS =  src/main.c \
		src/parsing_args.c \
		src/check_and_open_file.c \
		src/get_file_content.c \
		src/allocation.c \
		src/initialization_of_values.c\
		src/parsing_map_textures.c \
		src/parsing_map_path_textures.c \
		src/parsing_map_colors.c \
		src/parsing_map.c \
		src/parsing_map_utils_1.c \
		src/parsing_map_utils_2.c \
		src/render_graphics.c \
		src/movement.c \
		src/raycast.c \
		src/ray_hit_detection.c \
		src/texture_displaying.c \
		src/draw_elements.c \
		src/error.c \
		src/free.c \
		src/utils_1.c \
		src/utils_2.c \
		src/utils_3.c \
		src/utils_4.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

#============ TRANSFORM .c TO .o ============#

OBJS=$(SRCS:.c=.o)

#============ Colors ========================#

white='\033[1;37m'
dark_green='\033[0;32m'

#================ UTILS PART ================#

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)
	@echo $(dark_green)"Executable is ready"

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re 