# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 16:17:18 by jgeslin           #+#    #+#              #
#    Updated: 2015/12/21 16:19:48 by abary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

LIB = alum1.a

INC_DIR = includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

SOURCES = ft_putnbr.c\
		  ft_putchar.c\
		  ft_putstr.c\
		  ft_atoi.c\
		  ft_strcpy.c\
		  ft_strdup.c\
		  ft_strlen.c\
		  ft_putstr_fd.c\
		  ft_read_match.c\
		  ft_list_match.c\
		  ft_print_matches.c\
		  ft_game_matches.c\
		  ft_strcmp.c\
		  ft_tolower.c\
		  ft_strlower.c\
		  ft_strjoin.c\
		  ft_resolve_matches.c\
		  ft_isdigit.c\
		  ft_display.c

SRC = $(addprefix sources/,$(SOURCES))

OBJ = $(SRC:.c=.o)

all : $(NAME) $(LIB)

$(NAME) : $(LIB)
	@$(CC) -o $(NAME) main.c $(LIB) $(CFLAGS)
	@echo "MiniOns Arrived!"
	@echo "A New Challenger!"

$(LIB) : $(OBJ)
	@ar -r $(LIB) $(OBJ)
	@ranlib $(LIB)
	@echo "Cpt. Alum1 Lib. Arrived."

clean :
	@rm -rf $(OBJ)
	@echo "MiniOns Died!"

fclean : clean
	@rm -rf $(NAME) $(LIB)
	@echo "All's Destroyed! R.I.P :'("

re : fclean all
	@echo "And The Rain Against! ^^"

.PHONY: all clean fclean re
