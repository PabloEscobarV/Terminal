# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 17:51:31 by Pablo Escob       #+#    #+#              #
#    Updated: 2024/08/04 17:59:36 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = strhandler
LIBNAME = libstrhandler.a
TEST = test
TESTFILE = test.c
READLINE = readline

LIBFTDIR = ../../libft
SRCDIR = src
OBJDIR = obj

LIBFT = ft
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGSO = -c -Wall -Wextra
LIBRS = -L$(LIBFTDIR) -l$(LIBFT) -l$(READLINE)

.PHONY: all, clean, fclean, re, lib, libfull, run

all: lib

lib: $(LIBNAME)

run: $(LIBNAME)
	$(CC) $(TESTFILE) -L. -l$(NAME) $(LIBRS) -o $(TEST)
	./$(TEST)

re: fclean lib

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -rf $(NAME) $(LIBNAME) $(TEST)

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	ar -rc $(LIBNAME) $(OBJ)
	ranlib $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGSO) $< -o $@

