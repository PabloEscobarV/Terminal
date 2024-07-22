/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/22 17:59:37 by Pablo Escob      ###   ########.fr       */
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

t_argv	*crtnodeargvt(t_cchar *args, t_crd *crd, t_sqr *sqr, t_hash *hst)
{
	char	*str;
	t_argv	*argvt;

	argvt = crtargvt(NULL);
	crd->size = cmpstrv(args + crd->i, sqr->splts);
	while (crd->i < crd->strsize && !crd->size)
	{
		str = strhandler(args, crd, sqr->qts, hst);
		if (str)
			llistadd_back(&argvt->str, llistnewnode(str));
		if (crd->size < 0)
			return (delargvt(argvt));

		crd->size = cmpstrv(args + crd->i, sqr->splts);
	}
	return (argvt);
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

