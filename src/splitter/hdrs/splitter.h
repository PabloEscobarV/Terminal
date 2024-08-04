/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:20:39 by blackrider        #+#    #+#             */
/*   Updated: 2024/08/04 19:06:11 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../../libft/libft.h"
#include "../../../hdrs/commondata.h"

typedef struct	s_crds
{
	int	i;
	int	size;
	int	strsize;
}				t_crds;

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
