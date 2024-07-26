/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servicespltr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:54:36 by polenyc           #+#    #+#             */
/*   Updated: 2024/07/26 23:45:28 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "splitter.h"
#define ERRQTS  "ERROR!!! Only one "

///////////////////////////////ARGSHANDLER///////////////////////////////
char	*argshndlr(t_cchar **args, t_splqt *splt);
///////////////////////////////STRHENDLER///////////////////////////////
char    *strhandler(t_cchar **args, t_crds *crd, t_cchar **qts, t_hash *hst);
char	*dqtshandler(t_cchar **args, t_crds *crd, t_cchar *end, t_hash *hst);
char	*sqtshadler(t_cchar **args, t_crds *crd, t_cchar *end);
///////////////////////////////SETNODE///////////////////////////////
// t_llist	*setnodestr(t_cchar *str, t_crds *crds, t_splqt *splt);
t_llist	*setnodestr(t_cchar *str, t_crds *crd, t_splqt *splt, t_hash *hst);
t_llist	*setnodedata(t_cchar *args, t_crds *crds, t_splqt *splt);
// t_llist	*setnodedata(t_cchar *args, t_crds *crd, t_cchar **splt);
///////////////////////////////OFFSET///////////////////////////////
int	    offset(t_cchar *str, t_crds *crds, t_splqt *splt);
///////////////////////////////T_ARG///////////////////////////////
void	freeargt(void *data);
t_arg	*crtargt(char *str, int x, int size);
///////////////////////////////T_CRDS///////////////////////////////
t_crds	*crdcrdst(int i, int size, int strsize);
void	*freecrds(t_crds *crds);
///////////////////////////////TOOLS///////////////////////////////
void	printmatrix(t_cchar **matrix);
void	printllist(void *data);
int		*crtintdt(int x);
void	*putsprintf(char *msg, int *ern);