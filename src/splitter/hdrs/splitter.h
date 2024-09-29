/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:20:39 by blackrider        #+#    #+#             */
/*   Updated: 2024/09/29 16:05:30 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITTER_H
# define SPLITTER_H

# include "../../../libft/libft.h"
# include "../../strhandler/hdrs/strhandler.h"

typedef struct	s_crds
{
	int	i;
	int	size;
	int	strsize;
}				t_crds;

typedef struct	s_splts
{
	t_cchar	*hrdoc;
	t_cchar	**qts;
	t_cchar	**spln;
	t_cchar	**rdr;
	t_cchar	**splts;
}				t_splqt;

t_llist	*spliter(t_cchar *str, t_splqt *splt);
///////////////////////////////T_SPLQT///////////////////////////////
t_splqt	*crtsplqtt(char *qts, char *rdr, char *spln, char *splts);
void	*freesplqtt(t_splqt *splqt);
///////////////////////////////T_ARG///////////////////////////////
void	freeargt(void *data);;
///////////////////////////////TOOLS///////////////////////////////
int		cmpsav(t_cchar *str, t_cchar **qts);
int		cmpqts(t_cchar *str, t_cchar **qts);
int		cmpstrv(t_cchar *str, t_cchar **splt);
void	printmatrix(t_cchar **matrix);
void	printllist(void *data);
void    *pmsgsetern(char *msg, int *ern);

#endif