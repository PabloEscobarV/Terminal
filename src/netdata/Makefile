# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 18:22:27 by Pablo Escob       #+#    #+#              #
#    Updated: 2024/08/18 21:15:29 by Pablo Escob      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = netdata
FULLLIB = full
LIBNAME = lib$(NAME).a
LIBNAMEFULL = lib$(NAME)$(FULLLIB).a
TEST = test
TESTFILE = test.c
READLINE = readline

LIBFTDIR = ../../libft
GNLDIR = ../../get_next_line
PRINTFDIR = ../../ft_printf
STRHANDLERDIR = ../strhandler
SPLITERDIR = ../splitter
SRCDIR = src
OBJDIR = objs

LIBFT = ft
GNL = gnlfull
PRINTF = ftprintffull
STRHANDLER = strhandler
SPLITER = splitter

LIBLIBFT = -L$(LIBFTDIR) -l$(LIBFT)
LIBGNL = -L$(GNLDIR) -l$(GNL)
LIBPRINTF = -L$(PRINTFDIR) -l$(PRINTF)
LIBSTRHNDLR = -L$(STRHANDLERDIR) -l$(STRHANDLER)
LIBSPLITER = -L$(SPLITERDIR) -l$(SPLITER)
LIBRLINE = -l$(READLINE)

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJLIBFT = $(LIBFTDIR)/$(OBJDIR)/*.o
OBJSTRHNLR = $(STRHANDLERDIR)/$(OBJDIR)/*.o
OBJSPLITER = $(SPLITERDIR)/$(OBJDIR)/*.o

CC = gcc
CFLAGSO = -c -Wall -Wextra

LIBRS = $(LIBLIBFT) $(LIBGNL) $(LIBPRINTF) $(LIBRLINE)

.PHONY: all, clean, fclean, re, lib, libfull, run

all: lib

lib: $(LIBNAME)

libf: $(LIBNAMEFULL)

cobj: $(OBJ)

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(MAKE) -C $(PRINTFDIR) clean
	$(MAKE) -C $(STRHANDLERDIR) clean
	$(MAKE) -C $(SPLITERDIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(MAKE) -C $(PRINTFDIR) fclean
	$(MAKE) -C $(STRHANDLERDIR) fclean
	$(MAKE) -C $(SPLITERDIR) fclean
	rm -f $(NAME) $(LIBNAME) $(LIBNAMEFULL) $(TEST)

re: fclean all

run: $(LIBNAMEFULL)
	$(CC) $(TESTFILE) -L. -l$(NAME)full $(LIBRS) -o $(TEST)
	./$(TEST)

$(LIBNAME): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(GNLDIR) bonus
	$(MAKE) -C $(PRINTFDIR) bonus
	$(MAKE) -C $(STRHANDLERDIR) cobj
	$(MAKE) -C $(SPLITERDIR) cobj
	ar -rc $(LIBNAME) $(OBJ)
	ranlib	$@

$(LIBNAMEFULL): $(OBJ)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(GNLDIR) bonus
	$(MAKE) -C $(PRINTFDIR) bonus
	$(MAKE) -C $(STRHANDLERDIR) cobj
	$(MAKE) -C $(SPLITERDIR) cobj
	ar -rc $(LIBNAMEFULL) $(OBJ) $(OBJLIBFT) $(OBJSPLITER) $(OBJSTRHNLR)
	ranlib	$@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGSO) $< -o $@