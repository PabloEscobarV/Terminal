# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 15:37:37 by blackrider        #+#    #+#              #
#    Updated: 2024/07/01 16:26:54 by blackrider       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = spliter
LIBNAME = libspliter.a

LIBFTDIR = ../../libft
SRCDIR = src
OBJDIR = objs

LIBFT = ft
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGSO = -c -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re, lib

all: $(NAME)

lib: $(LIBNAME)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME) $(LIBNAME)

re: fclean all

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(OBJ) -L$(LIBFTDIR) -l$(LIBFT) -o $@

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	ar -rc $(LIBNAME) $(OBJ) $(LIBFTDIR)/$(OBJDIR)/*.o
	ranlib	$@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGSO) $< -o $@
