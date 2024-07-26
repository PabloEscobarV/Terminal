/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/26 17:11:31 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"

#define T_ARG(llst)	((t_arg *)((llst)->data))

t_cchar	*cmpstrv(t_cchar *args, t_cchar **strv)
{
	while (*strv && !ft_strlcmp(args, *strv))
		++strv;
	return (*strv);
}

int		checkinitdtd(t_cchar *args, t_splqt *splt)
{
	int		tmp;

	tmp = cmpqts(args, splt->rdr);
	if (tmp)
		return (tmp);
	tmp = cmpqts(args, splt->splts);
	if (tmp)
	{
		printf("%s\t\'%s\'", TOKENERROR, splt->splts[tmp]);
		return (-1);
	}
	return (IOSIZE);
}

int	setinitdt(t_cchar *args, t_splqt *splt, t_llist *llargt, t_argv *argvt)
{
	int	oper;

	oper = cmpqts(args + T_ARG(llargt)->x, splt);
	if (oper < 0)
			return (0);
	switch (oper)
	{
	case (I_APPOFILE):
		argvt->appnd = 1;
		argvt->outfile = T_ARG(llargt)->arg;
		break ;
	case (I_OFILE):
		argvt->outfile = T_ARG(llargt)->arg;
		break ;
	case (I_IFILE):
		argvt->infile = T_ARG(llargt)->arg;
	}
	return (1);
}

int		checksplt(t_cchar *args, t_cchar **escptn, t_cchar **splts)
{
	int	oper;

	if (!(*args))
		return (-1);
	if (cmpstrv(args, escptn))
		return (0);
	oper = cmpqts(args, splts);
	if (oper)
		return (oper + O_HRDOC);
	return (0);
}

int		getsize(t_cchar *args, t_splqt *splt, t_llist *llargt, t_argv *argvt)
{
	int	size;

	size = 0;
	while (llargt)
	{
		++size;
		argvt->oper = checksplt(args + T_ARG(llargt)->size, splt->qts, splt->splts);
		if (argvt->oper)
			break ;
		llargt = llargt->next;
	}
	return (size);
}

int		setargv(t_cchar *args, t_splqt *splt, t_llist **llargt, t_argv *argvt)
{
	int	size;
	t_cchar	**tmp;

	size = getsize(args, splt, llargt, argvt);
	argvt->argv = malloc((size + 1) * sizeof(t_cchar *));
	if (!(argvt->argv))
		return (ft_perror("MALLOC ERROR!!!: in setargv"));
	argvt->argv[size] = NULL;
	tmp = argvt->argv;
	while (size)
	{
		*tmp = T_ARG(llargt)->arg;
		llargt = llargt->next;
		--size;
		++tmp;
	}
	return (llargt);
}



t_argv	*setargvt(t_cchar *args, t_splqt *splt, t_llist **llargt)
{
	t_llist	*tmp;
	t_argv	*argvt;

	argvt = crtargvt();
	if (!argvt)
		return (ft_perror("MALLOC ERROR!!!: crtargvt"));
	if ((*llargt)->previous && !(*llargt)->previous->next)
		if (!setinitdt(args, splt, llargt, argvt))
			return (llistclear(&argvt, freeargvt));
	tmp = setargv(args, splt, llargt, argvt);
	tmp = 
	*llargt = tmp;
	return (argvt);
}

t_llist	*nodeargvt(t_cchar *args, t_splqt *splt)
{

}

t_llist	*netdata(t_cchar *args, t_hash *hst)
{
	t_llist	*llargt;
	t_llist	*llargvt;

	llargt = spliter(args,
		crtsplqtt(ft_split(QTS, SPLTCH), ft_split(SPLTS, SPLTCH)), hst);
	if (!llargt)
		return (ft_perror("ERROR in SPLITTER!!!"));

}


