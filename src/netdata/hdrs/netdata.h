/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:03:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/08/05 18:42:54 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../../libft/libft.h"
#include "../../../hdrs/commondata.h"

t_llist	*netdata(t_cchar *args, t_llist *argtll, t_splqt *splt);
///////////////////////////////////////T_ARGV////////////////////////////////////
t_argv	*crtargvt();
void	freeargvt(void *data);
void	*delargvt(t_argv *argv);
///////////////////////////////////////TOOLS////////////////////////////////////
void	fakefree(void *data);
