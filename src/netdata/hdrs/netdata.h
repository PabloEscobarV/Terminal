/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:03:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/09/29 16:06:00 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETDATA_H
# define NETDATA_H

#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"

typedef struct	s_argv
{
	char	oper;
	char	appnd;
	t_cchar	*path;
	t_llist	*argll;
	char	*infile;
	char	*outfile;
	t_cchar	**argv;
	t_cchar	**envp;
}				t_argv;

t_llist	*netdata(t_cchar *args, t_llist *argtll, t_splqt *splt);
///////////////////////////////////////T_ARGV////////////////////////////////////
t_argv	*crtargvt();
void	freeargvt(void *data);
void	*delargvt(t_argv *argv);
///////////////////////////////////////TOOLS////////////////////////////////////
void	fakefree(void *data);

#endif