# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 18:40:31 by aelkhali          #+#    #+#              #
#    Updated: 2022/12/08 22:38:56 by aelkhali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Game Name
NAME = so_long

# Colors :
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED= \033[0;31m
BLUE = \033[0;34m
STOP = \033[0m

# Commands And Flags : 
CC = cc 
FLAGS =	-Wall -Wextra -Werror 
MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

# loading source files : 
LIBFT = ./libft/ft_putstr.c ./libft/ft_split.c ./libft/ft_strchr.c ./libft/ft_strjoin.c \
	./libft/ft_strcmp.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c ./libft/ft_substr.c ./libft/get_next_line.c
SRCS = $(LIBFT) main.c map_checker.c map_reader.c map_checker_utils.c map_checker_utils2.c leaks_hundler.c \
	flood_fills.c

all : $(NAME)
	@echo "You Can Start Playing $(GREEN)*** So long ***"

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $(MLX) $(SRCS) -o $(NAME)
	@echo "$(BLUE)Compiling the source files... $(STOP)"

clean :
	@$(RM) $(OBJS)
	@echo "$(YELLOW)Cleaning the Object files... $(STOP)"
	
fclean : clean
	@$(RM) $(NAME)
	@echo "$(RED)Deleting The Game ... $(STOP)"

re : fclean all