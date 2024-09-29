/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdataservice.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:15:26 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/29 15:01:44 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../hdrs/netdata.h"

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

char	**llisttostr(t_llist *llst);
///////////////////////////////////////TOOLS////////////////////////////////////
void	printstr(void *data);
t_cchar	*skipspaces(t_cchar *args);
t_cchar	*cmpargsv(t_cchar *args, t_cchar **strv);
