/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:16:32 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/07/30 15:58:55 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define REPLSCH	'$'
#define	BRACES	"{}"
#define PID		"$$"

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

typedef struct	s_strhdlr
{
	t_cchar	esc;
	t_cchar	acivatech;
}				t_strhndlr;