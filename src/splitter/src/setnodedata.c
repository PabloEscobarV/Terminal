/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnodedata.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:15:25 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/01 17:16:10 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitterlcl.h"

static void		skipspaces(t_cchar *str, t_crds* crds, t_splqt *splt, t_crds *res)
{
	res->i = crds->i;
	while (res->i < crds->strsize && str[res->i] == splt->spcs)
		++res->i;
	if (res->i >= crds->strsize)
		return ;
	res->size = crds->size;
	while (--res->size && str[res->size] == splt->spcs);
	++res->size;
	res->strsize = res->size - res->i;
}

static int	checkcrds(t_crds *crds, t_crds *res)
{
	if (res->i >= crds->strsize)
	{
		crds->i = crds->strsize;
		return (1);
	}
	if (res->strsize < 1)
	{
		crds->i = res->i;
		return (1);
	}
	return (0);
}

t_llist	*setnodedata(t_cchar *str, t_crds *crds, t_splqt *splt)
{
	t_cchar	*tmp;
	t_crds	res;
	t_llist	*node;

	tmp = offset(str, crds, splt);
	skipspaces(str, crds, splt, &res);
	if (checkcrds(crds, &res))
		return (NULL);
	crds->i = ft_strlen(tmp) + crds->size;
	if (crds->i >= crds->strsize)
		tmp = NULL;
	node = llistnewnode(crtargt(ft_strndup(str + res.i, res.strsize), tmp));
	return (node);
}
