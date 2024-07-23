/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:03:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/23 10:41:09 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../../libft/libft.h"

#define ESCCH		'\\'
#define VARCH		'$'
#define SPCCH		' '
#define MALLOCERROR	"ALLOC ERROR!!!"
#define QTS			"\"\'"
#define IORDR		">0<0>>"

typedef unsigned char	t_uchar;
typedef const char		t_cchar;
typedef t_cchar *(* f_hash)(t_cchar *key, char **hashtb);

typedef struct	s_indata
{
	t_cchar	*args;
	char	**hashtb;
}				t_indata;

typedef struct	s_hash
{
	f_hash	hash;
	char	**hashtb;
}				t_hash;

typedef struct	s_crd
{
	int	i;
	int	size;
	int	strsize;
}				t_crd;

typedef struct	s_sqr
{
	t_cchar	*qts;
	t_cchar	**rdr;
	t_cchar	**splts;
	t_cchar	***qrs;
}				t_sqr;

typedef struct	s_argv
{
	char	oper;
	char	appnd;
	t_cchar	*path;
	t_llist	*str;
	char	*infile;
	char	*outfile;
	t_cchar	**argv;
	t_cchar	**envp;
}				t_argv;

enum
{
	I_DQTS,
	I_SQTS,
	IDSSIZE,
};

enum
{
	I_OFILE,
	I_IFILE,
	I_APPOFILE,
	IOSIZE,
};

/////////////////////////////////////////RDRHANDLER/////////////////////////////////
char	*rdrhandler(t_cchar *args, t_crd *crd, t_cchar **rdr, t_argv *argvt);
/////////////////////////////////////////STRHANDLER/////////////////////////////////
char    *strhandler(t_cchar *args, t_crd *crd, t_cchar **qts, t_hash *hst);
/////////////////////////////////////////STRHANDLER/////////////////////////////////
t_cchar *hashf(t_cchar *key, char **hashtb);
/////////////////////////////////////////T_ARGV/////////////////////////////////
t_argv	*crtargvt(t_cchar **envp);
void	freeargvt(t_argv *argv);
void	*delargvt(t_argv *argv);
/////////////////////////////////////////T_SQR/////////////////////////////////
t_sqr	*crtsqrt(t_cchar **qts, t_cchar **splts, t_cchar **rdr);
void	*delsqrt(t_sqr *sqr);
void	freesqrt(t_sqr *sqr);
/////////////////////////////////////////CHECK SPLQTRDR/////////////////////////////////
int		isqtssv(t_cchar *str, t_cchar **qts);
int		cmpstrv(t_cchar *str, t_cchar **sqr);
/////////////////////////////////////////TOOLS/////////////////////////////////
void	fakefree(void *data);