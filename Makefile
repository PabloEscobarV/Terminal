# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 17:51:20 by blackrider        #+#    #+#              #
#    Updated: 2024/07/18 11:04:20 by blackrider       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FTPRINTFDIR = ft_printf/
GNLDIR = get_next_line/
LIBFTDIR = libft/
SPLITER = src/splitter

.PHONY: all, cean, fclean

all:
	$(MAKE) -C $(FTPRINTFDIR) bonus
	$(MAKE) -C $(GNLDIR) bonus
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(SPLITER)

clean:
	$(MAKE) -C $(FTPRINTFDIR) clean
	$(MAKE) -C $(GNLDIR) clean
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(SPLITER) clean

fclean:
	$(MAKE) -C $(FTPRINTFDIR) fclean
	$(MAKE) -C $(GNLDIR) fclean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(SPLITER) fclean
