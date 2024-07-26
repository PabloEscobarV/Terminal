# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 15:37:37 by blackrider        #+#    #+#              #
#    Updated: 2024/07/26 23:48:41 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = spliter
LIBNAME = libsplitter.a
LIBNAMEFULL = libsplitterft.a
TEST = test
TESTFILE = test.c
READLINE = readline

LIBFTDIR = ../../libft
GNLDIR = ../../get_next_line
PRINTFDIR = ../../ft_printf
SRCDIR = src
OBJDIR = objs

LIBFT = ft
GNL = gnlfull
PRINTF = ftprintffull
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC = gcc
CFLAGSO = -c -Wall -Wextra
LIBRS = -L$(LIBFTDIR) -l$(LIBFT) -L$(GNLDIR) -l$(GNL) -L$(PRINTFDIR) -l$(PRINTF) -l$(READLINE)

.PHONY: all, clean, fclean, re, lib, libfull, run

all: lib

lib: $(LIBNAME)

libf: $(LIBNAMEFULL)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(MAKE) -C $(PRINTFDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(MAKE) -C $(PRINTFDIR) fclean
	rm -f $(NAME) $(LIBNAME) $(LIBNAMEFULL) $(TEST)

re: fclean all

run: $(LIBNAME)
	$(CC) $(TESTFILE) -L. -lsplitter $(LIBRS) -o $(TEST)
	./$(TEST)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(GNLDIR) bonus
	$(MAKE) -C $(PRINTFDIR) bonus
	$(CC) $(OBJ) $(LIBRS) -o $@

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(GNLDIR) bonus
	$(MAKE) -C $(PRINTFDIR) bonus
	ar -rc $(LIBNAME) $(OBJ)
	ranlib	$@

$(LIBNAMEFULL): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(GNLDIR) bonus
	$(MAKE) -C $(PRINTFDIR) bonus
	ar -rc $(LIBNAMEFULL) $(OBJ) $(LIBFTDIR)/$(OBJDIR)/*.o
	ranlib	$@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGSO) $< -o $@
