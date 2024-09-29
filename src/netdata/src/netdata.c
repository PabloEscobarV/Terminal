/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/09/29 19:50:01 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../hdrs/netdataservice.h"
#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../strhandler/hdrs/strhandler.h"
#include <stdio.h>
#include <readline/readline.h>

#define T_ARG(llst)	((t_arg *)((llst)->data))

int		getoper(t_cchar *args, t_cchar **escptn, t_cchar **splts)
{
	int	oper;

	if (!(*args))
		return (0);
	args = skipspaces(args);
	if (cmpargsv(args, escptn))
		return (0);
	oper = cmpqts(args, splts);
	if (oper + O_HRDOC < O_SIZE)
		return (oper + O_HRDOC);
	return (0);
}

int	setrdrdt(t_llist **argtll, t_argv *argvt, int oper)
{
	if (!oper)
			return (E_KO);
	switch (oper)
	{
	case (O_APPND):
		argvt->appnd = 1;
		argvt->outfile = ft_strdup(T_ARG(*argtll)->arg);
		break ;
	case (O_OFILE):
		argvt->outfile = ft_strdup(T_ARG(*argtll)->arg);
		break ;
	case (O_IFILE):
		argvt->infile = ft_strdup(T_ARG(*argtll)->arg);
		break ;
	default:
		return (E_KO);
	}
	return (E_OK);
}

t_argv	*setargvt(t_cchar *args, t_splqt *splt, t_llist **argtll)
{
	t_llist	*tmp;
	t_argv	*argvt;

	argvt = crtargvt();
	if (!argvt)
		return (ft_perror("MALLOC ERROR!!!: crtargvt"));
	while (*argtll && !(argvt->oper))
	{
		if (setrdrdt(argtll, argvt,
			getoper(args + T_ARG(*argtll)->x, splt->qts, splt->splts)))
				llistadd_back(&(argvt->argll), llistnewnode(T_ARG(*argtll)->arg));
		argvt->oper = getoper(args + T_ARG(*argtll)->size, splt->qts, splt->splts);
		*argtll = (*argtll)->next;
		if (!setrdrdt(argtll, argvt, argvt->oper))
		{
			argvt->oper = 0;
			*argtll = (*argtll)->next;
		}
	}
	argvt->argv = (t_cchar **)llisttostr(argvt->argll);
	return (argvt);
}

t_llist	*netdata(t_cchar *args, t_llist *argtll, t_splqt *splt)
{
	t_llist	*argvtll;

	if (!argtll)
		return (NULL);
	if (!splt)
		return (ft_perror("ERROR!!! Empty SPLT"));
	argvtll = NULL;
	while (argtll)
		if (!llistadd_back(&argvtll, llistnewnode(setargvt(args, splt, &argtll))))
			return (llistclear(&argvtll, freeargvt));
	return (argvtll);
}

// int	main()
// {
// 	char	*line;
// 	t_llist	*llst;
// 	t_splqt	*splqt;
// 	t_hash	hst;
	
// 	hst.hash = hash;
// 	hst.hashtb = NULL;
// 	splqt = crtsplqtt(QTS, RDR, SPLN, SPLTS);
// 	printmatrix(splqt->spln);
// 	while (1)
// 	{
// 		line = readline("Pablo Escobar:\t");
// 		if (!ft_strcmp(line, "exit"))
// 			break ;
// 		printf("%s\n", line);
// 		llst = spliter(line, splqt, &hst);
// 		llistiter(llst, printllist);
// 		llistclear(&llst, freeargt);
// 	}
// 	freesplqtt(splqt);
// 	return (0);
// }

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

// int	rdrdata(t_cchar *args, t_splqt *splt, t_llist **argtll, t_argv *argvt)
// {
// 	if (!(*argtll))
// 		return (E_OK);
// 	if (!((*argtll)->previous) || !((*argtll)->previous->next))
// 		argvt->oper = getoper(args + T_ARG(*argtll)->x, NULL, splt->splts);
// 	else
// 		argvt->oper = getoper(args + T_ARG((*argtll)->previous)->size,
// 			NULL, splt->splts);
// 	return (setrdrdt(splt, argtll, argvt));
// }

// int		getsize(t_cchar *args, t_splqt *splt, t_llist *argtll, t_argv *argvt)
// {
// 	int	size;

// 	size = 0;
// 	while (argtll)
// 	{
// 		if (!isspltoper(setopercode(args, splt, argtll, argvt)))
// 			break;
// 		printf("|%s|\n", args + T_ARG(argtll)->size);
// 		++size;
// 		argtll = argtll->next;
// 	}
// 	return (size);
// }

// int		setargv(t_cchar *args, t_splqt *splt, t_llist **argtll, t_argv *argvt)
// {
// 	int	size;
// 	t_cchar	**tmp;

// 	size = getsize(args, splt, *argtll, argvt);
// 	if (!size)
// 		return (E_OK);
// 	argvt->argv = malloc((size + 1) * sizeof(t_cchar *));
// 	if (!(argvt->argv))
// 	{
// 		ft_perror("MALLOC ERROR!!!: in setargv");
// 		return (E_KO);
// 	}
// 	argvt->argv[size] = NULL;
// 	tmp = argvt->argv;
// 	while (size)
// 	{
// 		*tmp = T_ARG(*argtll)->arg;
// 		*argtll = (*argtll)->next;
// 		--size;
// 		++tmp;
// 	}
// 	return (E_OK);
// }

// int	setargvtdata(t_cchar *args, t_splqt *splt, t_llist **argtll, t_argv *argvt)
// {
// 	argvt->oper = setopercode(args, splt, *argtll, argvt);
// 	setrdrdt(splt, argtll, argvt);
// 	setargv(args, splt, argtll, argvt);
// 	argvt->oper = setopercode(args, splt, *argtll, argvt);
// 	if (argvt->oper == O_NULL)
// 		return (E_OK);
// 	setrdrdt(splt, argtll, argvt);
// 	argvt->oper = setopercode(args, splt, *argtll, argvt);
// 	if (!argvt->oper || !isspltoper(argvt->oper))
// 		return (E_ERROR);
// }

// int	setargvtdata(t_cchar *args, t_splqt *splt, t_llist **argtll, t_argv *argvt)
// {
// 	while (*argtll && !(argvt->oper))
// 	{
// 		argvt->oper = setopercode(args, splt, argtll, argvt);
// 		if (isspltoper(argvt->oper))
// 			llistadd_back(&(argvt->argll), llistnewnode(T_ARG(*argtll)->arg));
// 		else
// 			setrdrdt(splt, argtll,argvt);
// 		*argtll = (*argtll)->next;
// 	}
// 	argvt->argv = llisttostr(argvt->argll);
// 	return (E_OK);
// }

// int	setopercode(t_cchar *args, t_splqt *splt, t_llist *argtll, t_argv *argvt)
// {
// 	int	opercode;

// 	if (!argtll)
// 		return (O_NULL);
// 	opercode = getoper(args + T_ARG(argtll)->x, splt->qts, splt->splts);
// 	if (opercode)
// 		return (opercode);
// 	return (getoper(args + T_ARG(argtll)->size, splt->qts, splt->splts));
// }

// int		isspltoper(int oper)
// {
// 	if (oper == O_APPND || oper == O_IFILE || oper == O_OFILE)
// 		return (O_NULL);
// 	return (oper);
// }

