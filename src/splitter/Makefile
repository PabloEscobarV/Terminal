# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 15:37:37 by blackrider        #+#    #+#              #
#    Updated: 2024/09/28 22:22:04 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = spliter
LIBNAME = libsplitter.a
TEST = test
TESTFILE = test.c
READLINE = readline

LIBFTDIR = ../../libft
GNLDIR = ../../get_next_line
PRINTFDIR = ../../ft_printf
STRHANDLERDIR = ../strhandler
SRCDIR = src
OBJDIR = objs

LIBFT = ft
GNL = gnlfull
PRINTF = ftprintffull
STRHANDLER = strhandler
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGSO = -c -Wall -Wextra
LIBRS = -l$(READLINE)

.PHONY: all, clean, fclean, re, lib, libfull, run

all: lib

lib: $(LIBNAME)

cobj: $(OBJ)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(PRINTFDIR) clean
	$(MAKE) -C $(STRHANDLERDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(PRINTFDIR) fclean
	$(MAKE) -C $(STRHANDLERDIR) fclean
	rm -f $(LIBNAME) $(TEST)

re: fclean all

run: $(LIBNAME)
	$(CC) $(TESTFILE) -L. -lsplitter $(LIBRS) -o $(TEST)
	./$(TEST)

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(PRINTFDIR) bonus
	$(MAKE) -C $(STRHANDLERDIR)
	ar -x $(LIBFTDIR)/lib$(LIBFT).a
	ar -x $(PRINTFDIR)/lib$(PRINTF).a
	ar -x $(STRHANDLERDIR)/lib$(STRHANDLER).a
	mv *.o $(OBJDIR)
	ar -rc $(LIBNAME) $(OBJDIR)/*.o
	ranlib	$@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) -g $(CFLAGSO) $< -o $@
