# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 17:51:31 by Pablo Escob       #+#    #+#              #
#    Updated: 2024/09/28 22:07:20 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = strhandler
LIBNAME = libstrhandler.a
TEST = test
TESTFILE = test.c
READLINE = readline

LIBFTDIR = libft
SRCDIR = src
OBJDIR = objs

LIBFT = ft
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

HASHTABLENAME = hashtable
HASHTABLEDIR = HashTable
HASHTABLEPATH = ../../$(HASHTABLEDIR)
LIBFTPATH = ../../$(LIBFTDIR)
LIB_HST = -L$(HASHTABLEPATH) -l$(HASHTABLENAME)

CC = gcc
CFLAGSO = -c -Wall -Wextra
LIBRS = -l$(READLINE)

.PHONY: all, clean, fclean, re, lib, libfull, run

all: lib

lib: $(LIBNAME)

libfull: $(LIBNAMEFULL)

cobj: $(OBJ)

run: $(LIBNAME)
	$(CC) $(TESTFILE) -L. -l$(NAME) $(LIBRS) -o $(TEST)
	./$(TEST)

re: fclean lib

clean:
	$(MAKE) -C $(HASHTABLEPATH) clean
	$(MAKE) -C $(LIBFTPATH) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTPATH) fclean
	$(MAKE) -C $(HASHTABLEPATH) fclean
	rm -rf $(NAME) $(LIBNAME) $(TEST)

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(LIBFTPATH)
	$(MAKE) -C $(HASHTABLEPATH)
	ar -x $(HASHTABLEPATH)/lib$(HASHTABLENAME).a
	ar -x $(LIBFTPATH)/lib$(LIBFT).a
	mv *.o $(OBJDIR)
	ar -rc $(LIBNAME) $(OBJDIR)/*.o
	ranlib $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGSO) $< -o $@

