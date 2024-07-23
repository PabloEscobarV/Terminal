/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:20:39 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/23 16:39:32 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../../libft/libft.h"

#define SPLTCH		'0'
#define ESCCH		'\\'
#define VARCH		'$'
#define SPCCH		' '
#define MALLOCERROR	"ALLOC ERROR!!!"
#define QTS			"\"\'"
#define IORDR		">0<0>>"

enum
{
	I_DQTS,
	I_SQTS,
	IQTSSIZE,
};

enum
{
	I_OFILE,
	I_IFILE,
	I_APPOFILE,
	IOSIZE,
};

typedef unsigned char	t_uchar;
typedef const char		t_cchar;
typedef t_cchar *(* f_hash)(t_cchar *key, char **hashtb);

typedef struct	s_hash
{
	f_hash	hash;
	char	**hashtb;
}				t_hash;

typedef struct	s_arg
{
	char	*arg;
	int		x;
	int		size;
}				t_arg;

typedef struct	s_splts
{
	char	spcs;
	t_cchar	**qts;
	t_cchar	**splts;
}				t_splqt;

typedef struct	s_sqr
{
	t_cchar	**qts;
	t_cchar	**rdr;
	t_cchar	**splts;
	t_cchar	***qrs;
}				t_sqr;

typedef struct	s_crds
{
	int	i;
	int	size;
	int	strsize;
}				t_crds;

t_llist	*spliter(t_cchar *str, t_splqt *splt, t_hash *hst);
///////////////////////////////STRHENDLER///////////////////////////////
char    *strhandler(t_cchar **args, t_cchar **qts, t_hash *hst);
char	*dqtshandler(t_cchar **args, t_cchar *end, t_hash *hst);
char	*sqtshadler(t_cchar **args, t_cchar *end);
///////////////////////////////SETNODE///////////////////////////////
// t_llist	*setnodestr(t_cchar *str, t_crds *crds, t_splqt *splt);
// t_llist	*setnodestr(t_cchar *str, t_splqt *splt, t_hash *hst);
// t_llist	*setnodedata(t_cchar *str, t_crds *crds, t_splqt *splt);
///////////////////////////////OFFSET///////////////////////////////
int	    offset(t_cchar *str, t_crds *crds, t_splqt *splt);
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
int		cmpstrv(t_cchar *str, t_cchar **splt);
