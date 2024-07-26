/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commondata.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:00:59 by polenyc           #+#    #+#             */
/*   Updated: 2024/07/26 15:05:13 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../libft/libft.h"

#define SPLTCH		' '
#define SLASH		'/'
#define ESCCH		'\\'
#define VARCH		'$'
#define SPCCH		' '
#define MALLOCERROR	"ALLOC ERROR!!!"
#define HRDOC		"<<"
#define QTS			"\" \'"
#define SPLN		"|| $$ | $"
#define RDR			">> < >"
#define SPLTS		"<< >> || $$ < > | $ \" \'"

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
	IQTSSIZE,
};

enum
{
	I_OFILE,
	I_IFILE,
	I_APPOFILE,
	IOSIZE,
};
