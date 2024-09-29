/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:16:32 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/29 15:55:19 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRHANDLER_H
# define STRHANDLER_H

# include "../../../E_Codes/e_codes.h"
# include "../../../HashTable/hdrs/hashtable.h"

# define ECRANE	'\\'
# define FESC	"=\\"
# define RESC	" \\/\"\'"
# define SUBSTR	"${ $? $$"
# define SUBEND	"}"
# define VARSYM	"_"
# define SIZEPE	2
# define LAMDA	0.01

enum	e_strtochng_i
{
	I_BRACES,
	I_EXTSTS,
	I_PID,
	I_SUBSTRSIZE,
};

enum	e_quet
{
	I_DQTS,
	I_SQTS,
	IQTSSIZE,
};

typedef struct s_argcrd
{
	int		i;
	char	*args;
}				t_argcrd;


typedef struct s_strtosub
{
	char	*qts;
	char	**substr;
	char	**subend;
}				t_strtosub;

typedef struct	s_arg
{
	char	*arg;
	int		x;
	int		size;
}				t_arg;

typedef struct	s_strtoinsrt
{
	char	varch;
	t_cchar	*fesc;
	t_cchar	*resc;
	t_cchar	**substr;
}				t_subesc;

char	*strhandler(char *str, t_strtosub *strtosub, t_hashtable *hst);
////////////////////////////////////T_ESCS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_subesc	*crtescs(char var, t_cchar *fesc, t_cchar *resc, t_cchar **substr);
void		*freeescs(t_subesc *escs);
///////////////////////////////T_ARG///////////////////////////////
void		freeargtonly(void *data);
void		freeargt(void *data);
t_arg		*crtargt(char *str, int x, int size);

#endif