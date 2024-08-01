/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:16:32 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/01 20:13:09 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../../hdrs/commondata.h"

#define	FESC	"=\\"
#define RESC	" \\/\"\'"
#define SUBSTR	"{?$"
#define SUBEND	"}"
#define VARSYM	"_"

enum	e_strtochng_i
{
	I_BRACES,
	I_EXTSTS,
	I_PID,
	I_SUBSTRSIZE,
};

typedef struct	s_strtoinsrt
{
	char	varch;
	t_cchar	*fesc;
	t_cchar	*resc;
	t_cchar	**substr;
}				t_subesc;

////////////////////////////////////T_ESCS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_subesc	*crtescs(char var, t_cchar *fesc, t_cchar *resc, t_cchar **substr);
void		*freeescs(t_subesc *escs);