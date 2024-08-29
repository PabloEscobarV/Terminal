/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdataservice.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:15:26 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/29 20:17:32 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../hdrs/netdata.h"

char	**llisttostr(t_llist *llst);
///////////////////////////////////////TOOLS////////////////////////////////////
void	printstr(void *data);
t_cchar	*skipspaces(t_cchar *args);
t_cchar	*cmpargsv(t_cchar *args, t_cchar **strv);
