/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llisttostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:17:58 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/29 16:35:13 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../hdrs/netdataservice.h"
#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../../hdrs/commondata.h"
#include <stdio.h>

static char	**matcpy(char **dest, char **src)
{
	while (*src)
	{
		*dest = *src;
		++src;
		++dest;
	}
	return (dest);
}

static void	cpylist(char **dest, t_llist *llst)
{
	while (llst)
	{
		*dest = ft_strdup((char *)llst->data);
		llst = llst->next;
		++dest;
	}
}

static int	sincellistsize(t_llist *llst)
{
	int	size;

	size = 0;
	while (llst)
	{
		llst = llst->next;
		++size;
	}
	return (size);
}

char	**llisttostr(t_llist *llst)
{
	int		size;
	char	**apparg;
	char	**str;
	char	**cpystr;

	if (!llst)
		return (NULL);
	apparg = ft_split((t_cchar *)llst->data, SPLTCH);
	size = ft_matsize((t_cchar **)apparg);
	size += sincellistsize(llst->next);
	str = malloc((1 + size) * sizeof(char *));
	if (!str)
		return (NULL);
	cpystr = matcpy(str, apparg);
	free(apparg);
	cpylist(cpystr, llst->next);
	str[size] = NULL;
	return (str);
}