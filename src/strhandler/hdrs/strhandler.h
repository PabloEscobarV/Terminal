/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:16:32 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/01 14:37:16 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define	PREEXCPT	"="
#define SUFEXCPT	"\\/ "
#define STRTOCNHG	"{} $ ?"

enum	e_strtochng_i
{
	I_BRACES,
	I_PID,
	I_EXTSTS,
};

enum	e_braces
{
	I_LBRACES,
	I_RBRACES,
};

enum	e_errorstrhndlr
{
	E_MEMERR = -2,
	E_ERR,
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