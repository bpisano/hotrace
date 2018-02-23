# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/22 16:39:00 by bpisano      #+#   ##    ##    #+#        #
#    Updated: 2018/02/23 13:15:46 by bpisano     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = hotrace

SRC = ./sources/hotrace.c				\
	  ./sources/word_manager.c			\
	  ./sources/search_manager.c		\
	  ./sources/lib1.c					\
	  ./sources/lib2.c					\
	  ./sources/lib3.c					\
	  ./sources/get_next_line.c			\

OBJECTS = $(SRC:.c=.o)

HEADS = -I ./includes					\

FLAGS = -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
END = \033[0m

all: $(NAME)

$(NAME): $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS)
	@echo "$(BLUE)$(NAME)\033[500D\033[42C$(GREEN)[DONE]$(END)"

%.o : %.c
	@echo "Compiling $(notdir $@)\033[500D\033[42C$(RED)[KO]$(END)"
	@gcc $(FLAGS) $(HEADS) -o $@ -c $?
	@echo "\033[1A\033[500D\033[42C$(GREEN)[DONE]$(END)"

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
