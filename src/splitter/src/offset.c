/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:24:52 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/26 21:53:32 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"

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
