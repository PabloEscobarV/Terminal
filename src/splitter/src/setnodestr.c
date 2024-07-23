/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnodestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:23:47 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/23 14:26:56 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"

// t_llist	*setnodestr(t_cchar *str, t_crds *crds, t_splqt *splt, t_hash *hst)
// {
// 	t_llist	*node;
// 	char	*tmp;

// 	tmp = strhandler(str, crds, splt->qts, hst);
// 	if (!tmp)
// 		return (NULL);
// 	node = llistnewnode(crtargt(tmp, crds->i, crds->size));
// 	crds->i = crds->size;
// 	return (llistnewnode((void *)tmp));
// }

static int	isqtssv(t_cchar *str, t_cchar ***splt)
{
	t_cchar	*tmp;

	while (**splt)
	{
		tmp = ft_strlcmp(str, (t_cchar *)**splt);
		if (tmp)
			return (tmp - str);
		++(*splt);
	}
	return (0);
}

static int	offsetqt(t_cchar *str, t_crds *crds, t_cchar **qts)
{
	t_cchar	*tmp;

	if (crds->i > 0 && *(str - 1 + crds->i) == ESCCH)
		return (0);
	crds->size = isqtssv(str + crds->i, &qts);
	if (!crds->size)
		return (0);
	crds->i += crds->size;
	crds->size = crds->i;
	while (crds->size < crds->strsize)
	{
		tmp = ft_strlcmp(str + crds->size, *qts);
		if (tmp && *(str - 1 + crds->size) != ESCCH)
			return ((int)(tmp - str) - crds->size);
		++crds->size;
	}
	crds->i = -1;
	return (0);
}

t_llist	*setnodestr(t_cchar *str, t_crds *crds, t_splqt *splt)
{
	int		tmp;
	t_llist	*node;

	tmp = offsetqt(str, crds, splt->qts);
	if (!tmp)
		return (NULL);
	node = llistnewnode(crtargt(ft_strndup(str + crds->i, crds->size - crds->i),
		crds->i, crds->size));
	crds->i = tmp + crds->size;
	return (node);
}