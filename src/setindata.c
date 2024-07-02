/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setindata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:20:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/02 15:37:52 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../hdrs/pipex.h>
#include "splitter/hdrs/splitter.h"
#include <stdlib.h>
#include <stdio.h>

#define m_arg(llst) ((t_arg *)((llst)->data))

static t_argv	*setargvt(t_cchar *args, t_llist **data, t_spltrs *spltrs)
{
	t_argv	*argvt;

	m_arg(*data)->arg;
	while (*data && !ft_strlcmp(((t_arg *)((*data)->data))->arg, spltrs->splt))
	{

		*data = (*data)->next;
	}
}

static t_argv	*setargvtnode(t_cchar *args, t_llist *data)
{
	t_argv	*argvt;

	argvt = crtargvt(NULL, NULL, NULL);
	if (!argvt)
		return (NULL);
	while (data)
	{

		
	}
}

t_argv	*getargv(t_cchar *args, t_cchar **envp, t_spltrs *spltrs)
{
	t_llist	*llst;

	llst = spliter(args, spltrs->splqt);
	if (!llst)
		return (NULL);
	
}