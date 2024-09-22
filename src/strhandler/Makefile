# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 17:51:31 by Pablo Escob       #+#    #+#              #
#    Updated: 2024/09/22 19:13:35 by Pablo Escob      ###   ########.fr        #
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

HASHTABLENAME = hashtablefull
HASHTABLEDIR = HashTable
HASHTABLEPATH = ../../$(HASHTABLEDIR)
LIB_HST = -L$(HASHTABLEPATH) -l$(HASHTABLENAME)

CC = gcc
CFLAGSO = -c -Wall -Wextra
LIBRS = -l$(READLINE) -L$(LIBFTDIR) -l$(LIBFT) -L$(HASHTABLEPATH) -l$(HASHTABLENAME)

.PHONY: all, clean, fclean, re, lib, libfull, run

all: lib

lib: $(LIBNAME)

libfull: $(LIBNAMEFULL)

cobj: $(OBJ)

run: $(LIBNAME)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(HASHTABLEPATH) libfull
	$(CC) $(TESTFILE) -L. -l$(NAME) $(LIBRS) -o $(TEST)
	./$(TEST)

re: fclean lib

clean:
	$(MAKE) -C $(HASHTABLEPATH) clean
	$(MAKE) -C $(LIBFTDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(HASHTABLEPATH) fclean
	rm -rf $(NAME) $(LIBNAME) $(LIBNAMEFULL) $(TEST)

$(LIBNAME): $(OBJ)
	ar -rc $(LIBNAME) $(OBJ)
	ranlib $@

$(LIBNAMEFULL): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(HASHTABLEPATH)
	ar -rc $(LIBNAMEFULL) $(OBJ) $(LIBFTDIR)/$(OBJDIR)/*.o $(HASHTABLEPATH)/$(OBJDIR)/*.o
	ranlib $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGSO) $< -o $@

