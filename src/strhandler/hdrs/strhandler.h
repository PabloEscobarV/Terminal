/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:16:32 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/30 16:00:35 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../../hdrs/commondata.h"

#define ECRANE	'\\'
#define	FESC	"=\\"
#define RESC	" \\/\"\'"
#define SUBSTR	"${ $? $$"
#define SUBEND	"}"
#define VARSYM	"_"
#define SIZEPE	2
#define LAMDA	0.01

enum	e_strtochng_i
{
	I_BRACES,
	I_EXTSTS,
	I_PID,
	I_SUBSTRSIZE,
};

// enum	e_qts
// {
// 	I_SQTS,
// 	I_DQTS,
// };

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

typedef struct	s_strtoinsrt
{
	char	varch;
	t_cchar	*fesc;
	t_cchar	*resc;
	t_cchar	**substr;
}				t_subesc;

char	*strhandler(char *str, t_strtosub *strtosub, t_hash *hst);
////////////////////////////////////T_ESCS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_subesc	*crtescs(char var, t_cchar *fesc, t_cchar *resc, t_cchar **substr);
void		*freeescs(t_subesc *escs);
