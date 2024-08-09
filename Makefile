# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 07:00:41 by tebandam          #+#    #+#              #
#    Updated: 2024/08/09 02:18:01 by tebandam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=================== NAME ===================#

NAME = cub3D

#================ COMPILATOR ================#
CC = clang

#=================== FLAGS ==================#

CFLAGS = -Wall -Wextra -Werror -I. -g

#============= MANDATORY SOURCES ============#

SRCS =	src/main.c \
		src/utils1.c \
		src/initialization.c \
		src/parsing_args.c \
		src/error.c \
		src/check_and_open_file.c \
		src/read_map.c \
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
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(dark_green)"Executable is ready"

clean: 
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re 