/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/22 14:34:48 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"

#define T_ARGV(llist) ((t_argv *)((llist)->data))

int	skipsplt(t_cchar *str, t_crd *crd, t_cchar **splts)
{
	crd->size = cmpstrv(str + crd->i, splts);
	while (crd->size)
	{
		if (crd->i >= crd->strsize)
			return (crd->i);
		crd->i += crd->size;
		crd->size = cmpstrv(str + crd->i, splts);
	}
	return (0);
}

t_llist	*crtnodeargvt(t_indata *indt, t_crd *crd, t_sqr *sqr)
{
	t_argv	*argvt;
	t_llist	*node;

	argvt = crtargvt(NULL);
	node = llistnewnode(argvt);
	crd->size = cmpstrv(indt->args + crd->i, sqr->splts);
	while (crd->i < crd->strsize && !crd->size)
	{
		
		crd->size = cmpstrv(indt->args + crd->i, sqr->splts);
	}
	return (node);
}

t_llist	*crtllistargvt(t_cchar *args, t_sqr *sqr)
{

}

t_llist	*netdata(t_cchar *args, t_sqr *sqr)
{
	if (!args || !sqr)
		return (NULL);
	return ();
}

