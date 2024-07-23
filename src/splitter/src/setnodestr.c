/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnodestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:23:47 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/23 19:56:02 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include <stdio.h>

static int	qtlen(t_cchar *str, t_cchar **qts)
{
	while (*qts && !ft_strlcmp(str, *qts))
		++qts;
	return (ft_strlen(*qts));
}

t_llist	*setnodestr(t_cchar *args, t_crds *crd, t_splqt *splt, t_hash *hst)
{
	t_llist	*node;
	char	*str;
	t_cchar	*tmp;

	if (crd->i >= crd->strsize)
		return (NULL);
	tmp = args + crd->i;
	str = strhandler(&tmp, splt->qts, hst);
	if (!str)
		return (NULL);
	crd->size = (int)(tmp - args);
	node = llistnewnode(crtargt(str, crd->i + qtlen(args + crd->i, splt->qts),
		crd->size));
	crd->i = crd->size;
	return (node);

}

// static int	isqtssv(t_cchar *str, t_cchar ***splt)
// {
// 	t_cchar	*tmp;

// 	while (**splt)
// 	{
// 		tmp = ft_strlcmp(str, (t_cchar *)**splt);
// 		if (tmp)
// 			return (tmp - str);
// 		++(*splt);
// 	}
// 	return (0);
// }

// static int	offsetqt(t_cchar *str, t_crds *crds, t_cchar **qts)
// {
// 	t_cchar	*tmp;

// 	if (crds->i > 0 && *(str - 1 + crds->i) == ESCCH)
// 		return (0);
// 	crds->size = isqtssv(str + crds->i, &qts);
// 	if (!crds->size)
// 		return (0);
// 	crds->i += crds->size;
// 	crds->size = crds->i;
// 	while (crds->size < crds->strsize)
// 	{
// 		tmp = ft_strlcmp(str + crds->size, *qts);
// 		if (tmp && *(str - 1 + crds->size) != ESCCH)
// 			return ((int)(tmp - str) - crds->size);
// 		++crds->size;
// 	}
// 	crds->i = -1;
// 	return (0);
// }

// t_llist	*setnodestr(t_cchar *str, t_crds *crds, t_splqt *splt)
// {
// 	int		tmp;
// 	t_llist	*node;

// 	tmp = offsetqt(str, crds, splt->qts);
// 	if (!tmp)
// 		return (NULL);
// 	node = llistnewnode(crtargt(ft_strndup(str + crds->i, crds->size - crds->i),
// 		crds->i, crds->size));
// 	crds->i = tmp + crds->size;
// 	return (node);
// }