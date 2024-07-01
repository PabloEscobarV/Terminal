/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setnodestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:16:17 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/01 17:16:23 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitterlcl.h"

static t_cchar	*offsetqt(t_cchar *str, t_crds *crds, t_cchar **qts)
{
	t_cchar	*tmp;

	tmp = cmpstrv(str + crds->i, qts);
	if (!tmp)
		return (NULL);
	crds->i += ft_strlen(tmp);
	crds->size = crds->i;
	while (crds->size < crds->strsize)
	{
		if (ft_strlcmp(str + crds->size, tmp))
			return (tmp);
		++crds->size;
	}
	crds->i = crds->size;
	crds->size = -1;
	return (NULL);
}

t_llist	*setnodestr(t_cchar *str, t_crds *crds, t_splqt *splt)
{
	t_cchar	*tmp;
	t_llist	*node;

	tmp = offsetqt(str, crds, splt->qts);
	if (!tmp)
		return (NULL);
	node = llistnewnode(crtargt(
		ft_strndup(str + crds->i, crds->size - crds->i), tmp));
	crds->i = ft_strlen(tmp) + crds->size;
	return (node);
}
