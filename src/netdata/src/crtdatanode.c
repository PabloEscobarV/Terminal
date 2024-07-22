/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crtdatanode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:44:23 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/22 14:17:16 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"

int	cmpstrv(t_cchar *str, t_cchar **sqr)
{
	t_cchar	*tmp;

	while (*sqr)
	{
		tmp = ft_strlcmp(str, (t_cchar *)*sqr);
		if (tmp)
			return (tmp - str);
		++sqr;
	}
	return (0);
}

static int	skipsplt(t_cchar *str, t_crd *crds, t_cchar **splts)
{
	crds->size = cmpstrv(str + crds->i, splts);
	while (crds->size)
	{
		if (crds->i >= crds->strsize)
			return (crds->i);
		crds->i += crds->size;
		crds->size = cmpstrv(str + crds->i, splts);
	}
	return (0);
}



t_llist	*srtdatanode(t_indata *indt, t_cchar ***splts)
{
	
}