/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitterlcl.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:57:17 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/01 16:07:09 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "structs.h"
#include "../../../libft/libft.h"

#define SPLTCH			'0'

///////////////////////////////SETNODE///////////////////////////////
t_llist	*setnodestr(t_cchar *str, t_crds *crds, t_splqt *splt);
t_llist	*setnodedata(t_cchar *str, t_crds *crds, t_splqt *splt);
///////////////////////////////OFFSET///////////////////////////////
int	offset(t_cchar *str, t_crds *crds, t_splqt *splt);
///////////////////////////////T_ARG///////////////////////////////
void	freeargt(void *data);
t_arg	*crtargt(char *str, int x, int size);
///////////////////////////////T_SPLQT///////////////////////////////
t_splqt	*crtsplqtt(t_cchar **qts, t_cchar **splts, t_cchar spcs);
void	*freesplqtt(t_splqt *splqt);
///////////////////////////////T_CRDS///////////////////////////////
t_crds	*crdcrdst(int i, int size, int strsize);
void	*freecrds(t_crds *crds);
///////////////////////////////TOOLS///////////////////////////////
void	printmatrix(t_cchar **matrix);
void	printllist(void *data);
