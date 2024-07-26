/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:20:39 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/26 14:28:18 by Pablo Escob      ###   ########.fr       */
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

t_llist	*spliter(t_cchar *str, t_splqt *splt, t_hash *hst);
///////////////////////////////T_SPLQT///////////////////////////////
t_splqt	*crtsplqtt(char **qts, char **splts, char **spln);
void	*freesplqtt(t_splqt *splqt);
///////////////////////////////TOOLS///////////////////////////////
int		cmpsav(t_cchar *str, t_cchar **qts);
