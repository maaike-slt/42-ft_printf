# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msloot <msloot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 17:15:16 by msloot            #+#    #+#              #
#    Updated: 2023/11/18 17:58:16 by msloot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
CC = 	cc
AR =	ar rcs
RM = 	rm -rf

CFLAGS =	-Wall -Werror -Wextra
CFLAGS +=	-g3
# CFLAGS +=	-fsanitize=address
# CFLAGS +=	-Wsuggest-attribute=const

# **************************************************************************** #
#	LIB		#

LIBPATH =	./libft/
LIBNAME =	$(LIBPATH)libft.a
LIBINC =	-I$(LIBPATH)

# **************************************************************************** #
#	SOURCE		#

SRC_PATH =	./src/
OBJ_PATH =	./obj/
INC =		./inc/

SRC_NAME = \
			ft_printf.c \

SRC =		$(addprefix $(SRC_PATH), $(SRC_NAME))
# SRC =		$(wildcard $(SRC_PATH)*.c) $(wildcard $(SRC_PATH)**/*.c)
#SRC_NAME =	$(subst $(SRC_PATH), , $(SRC))

OBJ_NAME =	$(SRC_NAME:.c=.o)
OBJ =		$(addprefix $(OBJ_PATH), $(OBJ_NAME))

# *************************************************************************** #
#	RULES		#

all:		$(NAME)
	@printf "\n$(B)$(MAG)$(NAME) compiled$(D)\n"

$(NAME):	$(OBJ) $(LIBNAME)
	@cp $(LIBNAME) $(NAME)
	$(AR) $(NAME) $(OBJ)

test:		all
	$(CC) $(CFLAGS) -I$(INC) main.c $(NAME) && echo && ./a.out

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC) $(LIBINC) -c $< -o $@

$(LIBNAME):
	@printf "$(D)$(B)$(BLU)\n$(NAME) objects compiled\n\n$(D)"
	@$(MAKE) -C $(LIBPATH)

clean:
	@$(RM) $(OBJ_PATH)
	@$(MAKE) clean -C $(LIBPATH)

fclean:		clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBPATH)

re:			fclean all

.PHONY: all clean fclean re test

# **************************************************************************** #
