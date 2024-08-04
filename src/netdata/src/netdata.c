/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/08/04 20:03:00 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../strhandler/hdrs/strhandler.h"
#include <stdio.h>
#include <readline/readline.h>

#define T_ARG(llst)	((t_arg *)((llst)->data))

void	printstr(void *data)
{
	char	*str;

	str = (char *)data;
	printf("|%s|\n", str);
}

static t_cchar	*skipspaces(t_cchar *args)
{
	while (*args && ft_isspace(*args))
		++args;
	return (args);
}

t_cchar	*cmpargsv(t_cchar *args, t_cchar **strv)
{
	if (!strv)
		return (NULL);
	while (*strv && !ft_strlcmp(args, *strv))
		++strv;
	return (*strv);
}

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
		argvt->outfile = T_ARG(*argtll)->arg;
		break ;
	case (O_OFILE):
		argvt->outfile = T_ARG(*argtll)->arg;
		break ;
	case (O_IFILE):
		argvt->infile = T_ARG(*argtll)->arg;
		break ;
	default:
		return (E_KO);
	}
	return (E_OK);
}

char	**llisttostr(t_llist *llst)
{
	int		size;
	char	**tmp;
	char	**str;

	size = llistsize(llst);
	if (!size)
		return (NULL);
	str = malloc((1 + size) * sizeof(char *));
	if (!str)
		return (NULL);
	str[size] = NULL;
	tmp = str;
	while (llst)
	{
		*tmp = (char *)llst->data;
		llst = llst->next;
		++tmp;
	}
	return (str);
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

t_llist	*nodeargvt(t_cchar *args, t_splqt *splt, t_llist *argtll)
{
	t_llist	*llst;

	llst = NULL;
	while (argtll)
		if (!llistadd_back(&llst, llistnewnode(setargvt(args, splt, &argtll))))
			return (llistclear(&llst, freeargvt));
	return (llst);
}

t_llist	*netdata(t_cchar *args)
{
	t_splqt	*splt;
	t_llist	*argtll;
	t_llist	*argvtll;

	splt = crtsplqtt(QTS, RDR, SPLN, SPLTS);
	argtll = spliter(args, splt);
	if (!argtll)
		return (ft_perror("ERROR!!! Error in splitter"));
	if (!splt)
		return (ft_perror("ERROR!!! Empty SPLT"));
	argvtll = nodeargvt(args, splt, argtll);
	llistclear(&argtll, free);
	freesplqtt(splt);
	return (argvtll);
}

void	printargvtllist(void *data)
{
	t_argv	*argvt;

	argvt = (t_argv *)data;
	printf("Operation code:\t%d;\tAPP status:\t%d;\n", (int)(argvt->oper), (int)(argvt->appnd));
	printf("Input file:\t%s\nOutput file:\t%s\n", argvt->infile, argvt->outfile);
	printmatrix(argvt->argv);
}

void	*hash(t_cchar *key, char **hashtb)
{
	return ((void *)ft_strdup("ABC"));
}

int	main()
{
	char	*str;
	char	*line;
	t_llist	*llst;
	t_splqt	*splqt;
	t_strtosub	tmpt;
	t_hash	hst;
	
	hst.hash = hash;
	hst.hashtb = NULL;
	tmpt.qts = ft_strdup("\"\'");
	tmpt.substr = ft_split(SUBSTR, SPLTCH);
	tmpt.subend = ft_split(SUBEND, SPLTCH);
	splqt = crtsplqtt(QTS, RDR, SPLN, SPLTS);
	while (1)
	{
		line = readline("Pablo Escobar:\t");
		if (!ft_strcmp(line, "exit"))
			break ;
		printf("%s\n", line);
		str = strhandler(line, &tmpt, &hst);
		llst = netdata(str);
		llistiter(llst, printargvtllist);		
		llistclear(&llst, freeargvt);
		free(line);
		free(str);
	}
		free(line);
	ft_free_d((void **)tmpt.subend);
	ft_free_d((void **)tmpt.substr);
	free(tmpt.qts);
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

