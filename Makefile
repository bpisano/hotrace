# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/22 16:39:00 by bpisano      #+#   ##    ##    #+#        #
#    Updated: 2018/02/22 16:41:54 by bpisano     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = hotrace

SRC = ./sources/hotrace.c				\

OBJECTS = $(SRC:.c=.o)

LIB = libft.a

HEADS = -I ./includes					\
		-I ./libft						\

FLAGS = -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
END = \033[0m

all: $(NAME)

$(LIB):
	@(make -C libft)

$(NAME): $(LIB) $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS) libft/$(LIB)
	@echo "$(BLUE)$(NAME)\033[500D\033[42C$(GREEN)[DONE]$(END)"

%.o : %.c
	@echo "Compiling $(notdir $@)\033[500D\033[42C$(RED)[KO]$(END)"
	@gcc $(FLAGS) $(HEADS) -o $@ -c $?
	@echo "\033[1A\033[500D\033[42C$(GREEN)[DONE]$(END)"

clean:
	@rm -f $(OBJECTS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
	@make fclean -C libft

re: fclean all
