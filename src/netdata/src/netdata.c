/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/26 22:33:09 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"
#include <stdio.h>
#include <readline/readline.h>

#define T_ARG(llst)	((t_arg *)((llst)->data))

t_cchar	*cmpargsv(t_cchar *args, t_cchar **strv)
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
	if (cmpargsv(args, escptn))
		return (0);
	oper = cmpqts(args, splts);
	if (oper + O_HRDOC < O_SIZE)
		return (oper + O_HRDOC);
	return (0);
}

int	setrdrdt(t_splqt *splt, t_llist **argtll, t_argv *argvt)
{
	if (!(argvt->oper))
			return (0);
	switch (argvt->oper)
	{
	case (O_APPND):
		argvt->appnd = 1;
		argvt->outfile = T_ARG(*argtll)->arg;
		break ;
	case (O_OFILE):
		argvt->outfile = T_ARG(*argtll)->arg;
		break ;
	case (O_IFILE):
		argvt->infile = T_ARG(*argtll)->arg;
		break ;
	default:
		return (argvt->oper);
	}
	*argtll = (*argtll)->next;
	return (0);
}

int		getsize(t_cchar *args, t_splqt *splt, t_llist *argtll, t_argv *argvt)
{
	int	size;

	size = 0;
	while (argtll)
	{
		++size;
		argvt->oper = checksplt(args + T_ARG(argtll)->size, splt->qts, splt->splts);
		if (argvt->oper)
			break ;
		argtll = argtll->next;
	}
	return (size);
}

int	initdat(t_cchar *args, t_splqt *splt, t_llist **argtll, t_argv *argvt)
{
	if ((*argtll)->previous && (*argtll)->previous->next)
		return (0);
	argvt->oper = checksplt(args + T_ARG(*argtll)->x, NULL, splt->splts);
	if (setrdrdt(splt, argtll, argvt))
	{
		printf("%s\t\'%s\'", TOKENERROR, splt->splts[argvt->oper]);
		return (1);
	}
	return (0);
}

int		setargv(t_cchar *args, t_splqt *splt, t_llist **argtll, t_argv *argvt)
{
	int	size;
	t_cchar	**tmp;

	size = getsize(args, splt, *argtll, argvt);
	if (!size)
		return (0);
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
		*tmp = T_ARG(*argtll)->arg;
		*argtll = (*argtll)->next;
		--size;
		++tmp;
	}
	return (0);
}

int		setendargvt(t_cchar *args, t_splqt *splt, t_llist **argtll, t_argv *argvt)
{
	if (!(*argtll))
		return (0);
	if (argvt->oper != O_APPND && argvt->oper != O_IFILE
		&& argvt->oper != O_OFILE)
			return (0);
	if (setrdrdt(splt, argtll, argvt))
		return (1);
	// argvt->oper = checksplt(args + T_ARG(*argtll)->x, NULL, splt->splts);
	// *argtll = (*argtll)->next;
	return (0);
}

t_argv	*setargvt(t_cchar *args, t_splqt *splt, t_llist **argtll)
{
	t_llist	*tmp;
	t_argv	*argvt;

	argvt = crtargvt();
	if (!argvt)
		return (ft_perror("MALLOC ERROR!!!: crtargvt"));
	if (initdat(args, splt, argtll, argvt))
		return (delargvt(argvt));
	if (setargv(args, splt, argtll, argvt))
		return (delargvt(argvt));
	if (setendargvt(args, splt, argtll, argvt))
		return (delargvt(argvt));
	return (argvt);
}

t_llist	*nodeargvt(t_cchar *args, t_splqt *splt, t_llist *argtll)
{
	t_llist	*llst;

	if (!argtll)
		return (ft_perror("ERROR!!! Empty argt dlist"));
	if (!splt)
		return (ft_perror("ERROR!!! Empty SPLT"));
	llst = NULL;
	while (argtll)
		if (!llistadd_back(&llst, llistnewnode(setargvt(args, splt, &argtll))))
			break ;
	return (llst);
}

t_llist	*netdata(t_cchar *args, t_hash *hst)
{
	t_splqt	*splt;
	t_llist	*argtll;
	t_llist	*argvtll;

	splt = crtsplqtt(QTS, RDR, SPLN, SPLTS);
	argtll = spliter(args, splt, hst);
	if (!argtll)
		return (ft_perror("ERROR!!! Error in splitter"));
	argvtll = nodeargvt(args, splt, argtll);
	llistclear(&argtll, free);
	freesplqtt(splt);
	return (argvtll);
}

void	printargvtllist(void *data)
{
	t_argv	*argvt;

	argvt = (t_argv *)data;
	printf("Operation code:\t%d;\tAPP status:\t%d;\n", argvt->oper, argvt->appnd);
	printf("Input file:\t%s\nOutput file:\t%s\n", argvt->infile, argvt->outfile);
	printmatrix(argvt->argv);
}

void	*hash(t_cchar *key, char **hashtb)
{
	return ((void *)ft_strdup("ABC"));
}

int	main()
{
	char	*line;
	t_llist	*llst;
	t_splqt	*splqt;
	t_hash	hst;
	
	hst.hash = hash;
	hst.hashtb = NULL;
	while (1)
	{
		line = readline("Pablo Escobar:\t");
		if (!ft_strcmp(line, "exit"))
			break ;
		printf("%s\n", line);
		llst = netdata(line, &hst);
		llistiter(llst, printargvtllist);
	}
	freesplqtt(splqt);
	return (0);
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