# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 17:51:31 by Pablo Escob       #+#    #+#              #
#    Updated: 2024/08/04 19:24:53 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = strhandler
LIBNAME = libstrhandler.a
LIBNAMEFULL = libstrhandlerfull.a
TEST = test
TESTFILE = test.c
READLINE = readline

LIBFTDIR = ../../libft
SRCDIR = src
OBJDIR = objs

LIBFT = ft
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGSO = -c -Wall -Wextra
LIBRS = -L$(LIBFTDIR) -l$(LIBFT) -l$(READLINE)

.PHONY: all, clean, fclean, re, lib, libfull, run

all: lib

lib: $(LIBNAME)

libfull: $(LIBNAMEFULL)

run: $(LIBNAME)
	$(CC) $(TESTFILE) -L. -l$(NAME) $(LIBRS) -o $(TEST)
	./$(TEST)

re: fclean lib

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -rf $(NAME) $(LIBNAME) $(LIBNAMEFULL) $(TEST)

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	ar -rc $(LIBNAME) $(OBJ)
	ranlib $@

$(LIBNAMEFULL): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	ar -rc $(LIBNAMEFULL) $(OBJ) $(LIBFTDIR)/$(OBJDIR)/*.o
	ranlib $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGSO) $< -o $@

