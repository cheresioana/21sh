# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icheres <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 13:36:23 by icheres           #+#    #+#              #
#    Updated: 2016/04/20 12:07:20 by icheres          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell1

SRC = cd.c\
	  util_str_plus.c\
	  ft_split_whitespaces.c\
	  implemented_functions.c\
	  main.c\
	  path.c\
	  utility_exit.c\
	  utility_implemented_functions.c\
	  utility_output.c\
	  utility_process.c\
	  utility_str.c\
	  utility_list.c\
	  utility_validation.c\
	  ft_split_extended.c\
	  run.c\
	  nlist_create.c\
	  slist_create.c\
	  wrong_fct.c\
	  commands.c\
	  iter_fd.c\
	  pulis.c\
	  processing_command.c\

OBJ = $(SRC:.c=.o)

COMP = gcc 
MOBJ = gcc 
RM = rm -rf



all: $(NAME)
$(NAME):
	@make -C includes/libft/
	gcc -c $(SRC)	
	$(MOBJ) $(OBJ) -L includes/libft -lft -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
