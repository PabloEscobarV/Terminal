/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/26 17:47:02 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"

#define T_ARG(llst)	((t_arg *)((llst)->data))

t_cchar	*cmpstrv(t_cchar *args, t_cchar **strv)
{
	if (!strv)
		return (NULL);
	while (*strv && !ft_strlcmp(args, *strv))
		++strv;
	return (*strv);
}

int		checksplt(t_cchar *args, t_cchar **escptn, t_cchar **splts)
{
	int	oper;

	if (!(*args))
		return (0);
	if (cmpstrv(args, escptn))
		return (0);
	oper = cmpqts(args, splts);
	if (oper)
		return (oper + O_HRDOC);
	return (0);
}

int	setrdrdt(t_splqt *splt, t_llist **llargt, t_argv *argvt)
{
	if (!(argvt->oper))
			return (0);
	switch (argvt->oper)
	{
	case (O_APPND):
		argvt->appnd = 1;
		argvt->outfile = T_ARG(*llargt)->arg;
		break ;
	case (O_OFILE):
		argvt->outfile = T_ARG(*llargt)->arg;
		break ;
	case (O_IFILE):
		argvt->infile = T_ARG(*llargt)->arg;
	default:
		return (argvt->oper);
	}
	*llargt = (*llargt)->next;
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

	size = getsize(args, splt, *llargt, argvt);
	argvt->argv = malloc((size + 1) * sizeof(t_cchar *));
	if (!(argvt->argv))
	{
		ft_perror("MALLOC ERROR!!!: in setargv");
		return (1);
	}
	argvt->argv[size] = NULL;
	tmp = argvt->argv;
	while (size)
	{
		*tmp = T_ARG(*llargt)->arg;
		*llargt = (*llargt)->next;
		--size;
		++tmp;
	}
	return (0);
}

int		setendargvt(t_cchar *args, t_splqt *splt, t_llist **llargt, t_argv *argvt)
{
	if (argvt->oper != O_APPND && argvt->oper != O_IFILE
		&& argvt->oper != O_OFILE)
			return (0);
	if (setrdrdt(splt, llargt, argvt))
		return (0);
	argvt->oper = checksplt(args + T_ARG(*llargt)->x, NULL, splt);
	*llargt = (*llargt)->next;
	return (0);
}

int	initdat(t_cchar *args, t_splqt *splt, t_llist **llargt, t_argv *argvt)
{
	if (!(*llargt)->previous || (*llargt)->previous->next)
		return (0);
	argvt->oper = checksplt(args + T_ARG(*llargt)->x, NULL, splt);
	if (!setrdrdt(splt, llargt, argvt))
	{
		printf("%s\t\'%s\'", TOKENERROR, splt->splts[argvt->oper]);
		return (1);
	}
	return (0);
}

t_argv	*setargvt(t_cchar *args, t_splqt *splt, t_llist **llargt)
{
	t_llist	*tmp;
	t_argv	*argvt;

	argvt = crtargvt();
	if (!argvt)
		return (ft_perror("MALLOC ERROR!!!: crtargvt"));
	if (initdat(args, splt, llargt, argvt))
		return (delargvt(argvt));
	if (setargv(args, splt, llargt, argvt))
		return (delargvt(argvt));
	setendargvt(args, splt, llargt, argvt);
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


// int		checkinitdtd(t_cchar *args, t_splqt *splt)
// {
// 	int		tmp;

// 	tmp = cmpqts(args, splt->rdr);
// 	if (tmp)
// 		return (tmp);
// 	tmp = cmpqts(args, splt->splts);
// 	if (tmp)
// 	{
// 		printf("%s\t\'%s\'", TOKENERROR, splt->splts[tmp]);
// 		return (-1);
// 	}
// 	return (IOSIZE);
// }