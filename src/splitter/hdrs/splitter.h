/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:20:39 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/25 12:55:20 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../../libft/libft.h"

#define SPLTCH		'0'
#define SLASH		'/'
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
	char	spcs;
	t_cchar	**qts;
	t_cchar	**splts;
	t_cchar	**rdr;
}				t_splqt;

typedef struct	s_crds
{
	int	i;
	int	size;
	int	strsize;
}				t_crds;

t_llist	*spliter(t_cchar *str, t_splqt *splt, t_hash *hst);

