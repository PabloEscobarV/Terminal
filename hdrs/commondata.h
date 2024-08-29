/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commondata.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:00:59 by polenyc           #+#    #+#             */
/*   Updated: 2024/08/28 12:32:35 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../libft/libft.h"

#define SPLTCH		' '
#define SLASH		'/'
#define BKSLASH		'\\'
#define VARCH		'$'
#define SPCCH		' '
#define PROCID		"$$"
#define ESCSMBS		"\\$\"\'"
#define MALLOCERROR	"MEMMORY ALLOCATE ERROR!!!"
#define TOKENERROR	"syntax error near unexpected token"
#define HRDOC		"<<"
#define QTS			"\" \'"
#define SPLN		"|| $$ | $"
#define RDR			">> > <"
#define SPLTS		"<< >> || < > | \" \'"

enum	e_errorcodes
{
	E_ERR = -1,
	E_OK,
	E_KO,
	E_ERROR,
};

enum	e_quet
{
	I_DQTS,
	I_SQTS,
	IQTSSIZE,
};

enum	e_rdr
{
	I_APPOFILE,
	I_OFILE,
	I_IFILE,
	IOSIZE,
};

enum	e_operations
{
	O_NULL,
	O_HRDOC,
	O_APPND,
	O_OR,
	O_IFILE,
	O_OFILE,
	O_PIPE,
	O_DQTS,
	O_SQTS,
	O_SIZE,
};

typedef unsigned char	t_uchar;
typedef const char		t_cchar;
typedef void *(* f_hash)(t_cchar *key, char **hashtb);

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
	t_cchar	*hrdoc;
	t_cchar	**qts;
	t_cchar	**spln;
	t_cchar	**rdr;
	t_cchar	**splts;
}				t_splqt;

typedef struct	s_argv
{
	char	oper;
	char	appnd;
	t_cchar	*path;
	t_llist	*argll;
	char	*infile;
	char	*outfile;
	t_cchar	**argv;
	t_cchar	**envp;
}				t_argv;

