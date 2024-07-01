/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:24:52 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/01 16:07:15 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitterlcl.h"

static int	cmpstrv(t_cchar *str, t_cchar **splt)
{
	t_cchar	*tmp;

	while (*splt)
	{
		tmp = ft_strlcmp(str, (t_cchar *)*splt);
		if (tmp)
			return (tmp - str);
		++splt;
	}
	return (0);
}

static int	skipsplt(t_cchar *str, t_crds *crds, t_splqt *splt)
{
	crds->size = cmpstrv(str + crds->i, splt->splts);
	while (crds->size)
	{
		if (crds->i >= crds->strsize)
			return (crds->i);
		crds->i += crds->size;
		crds->size = cmpstrv(str + crds->i, splt->splts);
	}
	return (0);
}

int	offset(t_cchar *str, t_crds *crds, t_splqt *splt)
{
	int	tmp;

	if (skipsplt(str, crds, splt))
		return (0);
	crds->size = crds->i;
	tmp = 0;
	while (!tmp && ++crds->size < crds->strsize)
	{
		tmp = cmpstrv(str + crds->size, splt->qts);
		if (tmp)
			return (0);
		tmp = cmpstrv(str + crds->size, splt->splts);
	}
	return (tmp);
}
