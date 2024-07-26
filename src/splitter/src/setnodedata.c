/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnodedata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:27:33 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/26 23:14:21 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"

static t_cchar	*setend(t_cchar *args, t_crds *crd)
{
	t_cchar	*tmp;

	tmp = args + crd->i;
	if (crd->i)
		return (tmp);
	while (*tmp && ft_isspace(*tmp))
		++tmp;
	crd->i = tmp - args;
	return (tmp);
}

t_llist	*setnodedata(t_cchar *args, t_crds *crd, t_splqt *splt)
{
	char	*str;
	t_cchar	*end;
	t_llist	*node;

	if (crd->i >= crd->strsize)
		return (NULL);
	end = setend(args, crd);
	str = argshndlr(&end, splt);
	crd->size = end - args;
	if (!str)
	{
		crd->i = crd->size;
		return (NULL);
	}
	node = llistnewnode(crtargt(str, crd->i, crd->size));
	crd->i = crd->size;
	return (node);
}

// static void		skipspaces(t_cchar *str, t_crds* crds, t_splqt *splt, t_crds *res)
// {
// 	res->i = crds->i;
// 	while (str[res->i] && str[res->i] == splt->spcs)
// 		++res->i;
// 	if (!str[res->i])
// 		return ;
// 	res->size = crds->size;
// 	while (str[--res->size] == splt->spcs);
// 	++res->size;
// 	res->strsize = res->size - res->i;
// }

// static int	checkcrds(t_crds *crds, t_crds *rescrd)
// {
// 	if (rescrd->i >= crds->strsize)
// 	{
// 		crds->i = crds->strsize;
// 		return (1);
// 	}
// 	if (rescrd->strsize < 1)
// 	{
// 		crds->i = rescrd->i;
// 		return (1);
// 	}
// 	return (0);
// }

// t_llist	*setnodedata(t_cchar *str, t_crds *crds, t_splqt *splt)
// {
// 	int		tmp;
// 	t_crds	rescrd;
// 	t_llist	*node;

// 	if (crds->i < 0)
// 		return (NULL);
// 	tmp = offset(str, crds, splt);
// 	skipspaces(str, crds, splt, &rescrd);
// 	if (checkcrds(crds, &rescrd))
// 		return (NULL);
// 	node = llistnewnode(crtargt(ft_strndup(str + rescrd.i, rescrd.strsize),
// 		crds->i, crds->size));
// 	crds->i = tmp + crds->size;
// 	return (node);
// }
