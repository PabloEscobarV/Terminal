/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnodestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:23:47 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/30 17:37:43 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"

static char	offsetqt(t_cchar *str, t_crds *crds, t_cchar **qts)
{
	t_cchar	*tmp;

	tmp = cmpstrv(str + crds->i, qts);
	if (!tmp)
		return (0);
	crds->i += ft_strlen(tmp);
	crds->size = crds->i;
	while (crds->size < crds->strsize)
	{
		if (ft_strlcmp(str + crds->size, tmp))
			return (1);
		++crds->size;
	}
	crds->i = crds->size;
	crds->size = -1;
	return (0);
}

static t_cchar	*spltaftstr(t_cchar *str, t_crds *crds, t_splqt *splt)
{
	t_cchar	*tmp;

	tmp = cmpstrv(str + crds->i, splt->splts);
	while (str[++crds->i] && ((str[crds->i]) == splt->spcs || !tmp))
		tmp = cmpstrv(str + crds->i, splt->splts);
	return (tmp);
}

t_llist	*setnodestr(t_cchar *str, t_crds *crds, t_splqt *splt)
{
	t_llist	*node;

	if (!offsetqt(str, crds, splt->qts))
		return (NULL);
	node = llistnewnode(crtargt(
		ft_strndup(str + crds->i, crds->size - crds->i), spltaftstr(str, crds, splt)));
	crds->i = ft_strlen(((t_arg *)(node->data))->spliter) + crds->size;
	return (node);
}
