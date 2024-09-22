# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 07:00:41 by tebandam          #+#    #+#              #
#    Updated: 2024/09/22 13:56:30 by tebandam         ###   ########.fr        #
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
		src/utils1.c \
		src/parsing_args.c \
		src/error.c \
		src/check_and_open_file.c \
		src/get_map.c \
		src/load_images_and_textures.c \
		src/parsing_elements_map.c \
		src/parsing_colors_maps.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		src/ft_split.c \
		src/free.c \
		src/utils2.c \
		src/parsing_map.c \
		src/parsing_map_utils.c \
		src/test.c \
		src/allocation.c \
		src/initialization_of_values.c\
		src/movement.c \

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