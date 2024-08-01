/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:16:32 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/01 13:04:02 by polenyc          ###   ########.fr       */
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

typedef struct	s_strtoinsrt
{
	t_cchar	varch;
	t_cchar	**
}