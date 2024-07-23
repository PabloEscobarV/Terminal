/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setindata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:20:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/23 10:58:36 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "splitter/hdrs/splitter.h"
#include <stdlib.h>
#include <stdio.h>

#define T_ARG(llst) 	((t_arg *)((llst)->data))
#define T_ARGV(llst)	((t_argv *)((llst)->data))

static int	defoprtn(t_cchar *str, t_cchar **splts, int size)
{
	int	i;

	i = 0;
	while (splts[i])
	{
		if (!ft_strncmp(str, splts[i], size))
			return (i);
		++i;
	}
	return (-1);
}

static t_uchar	setargv(t_argv *argvt, t_llist *data)
{
	switch(argvt->oper)
	{
		case (OR):
			// argvt->infile = ft_strdup(T_ARG(data)->arg);
			break;
		case (END):
			// argvt->outfile = ft_strdup(T_ARG(data)->arg);
			break;
		case (APPND):
			argvt->outfile = ft_strdup(T_ARG(data)->arg);
			break;
		case (HRDOC):
			break ;
		case (PIPE):
			break ;
		case (INRDR):
			argvt->outfile = ft_strdup(T_ARG(data)->arg);
			break ;
		case (OUTRDR):
			argvt->outfile = ft_strdup(T_ARG(data)->arg);
			break ;
		default:
			argvt->argv = (t_cchar **)ft_split(T_ARG(data)->arg, SPLTSP);
	}
	return (0);
}

static t_uchar	setstr(t_argv *argvt, t_llist *data)
{
	if (argvt->oper != DBQUETE && argvt->oper != SGQUOTE)
		return (1);
	argvt->str = ft_strdup(T_ARG(data)->arg);
	if (!argvt->str)
		return (MEMERROR);
	return (0);
}

static int	setx(t_llist *data)
{
	if (!data->previous || !data->previous->next)
		return (0);
	return (T_ARG(data->previous)->size);
}

static int	setsize(t_llist *data)
{
	if (!data->previous || !data->previous->next)
		return (T_ARG(data)->x);
	return (T_ARG(data)->x - T_ARG(data->previous)->size);
}

t_uchar	nodeoprtn(t_cchar *args, t_splqt *splqt, t_argv *argvt, t_llist *data)
{
	int	x;
	int	size;

	x = setx(data);
	size = setsize(data);
	if (!size)
		return (1);
	argvt->oper = defoprtn(args + x, splqt->splts, size);
	if (argvt->oper >= 0)
		return (setargv(argvt, data));
	argvt->oper = defoprtn(args + x, splqt->qts, size) + 10;
	return (setstr(argvt, data));
}

t_llist	*setargvtnode(t_cchar *args, t_cchar **envp, t_splqt *splqt, t_llist **data)
{
	t_argv	*argvt;

	argvt = crtargvt(NULL, NULL, (t_cchar **)envp);
	while (*data && cmpstrv(args + T_ARG(*data)->size, splqt->splts))
	{		
		if (nodeoprtn(args, splqt, argvt, *data))
			return (NULL);
		*data = (*data)->next;
	}
	argvt->path = getapppath((char **)envp, argvt->argv[0]);
	argvt->envp = envp;
	return (llistnewnode(argvt));
}

t_llist	*getargvllst(t_cchar *args, t_cchar **envp, t_splqt *splqt)
{
	t_llist	*argvllst;
	t_llist	*tmp;
	t_llist	*llst;

	llst = spliter(args, splqt);
	if (!llst)
		return (NULL);
	llistiter(llst, printllist);
	argvllst = NULL;
	tmp = llst;
	while (tmp)
		if (llistadd_back(&argvllst, setargvtnode(args, envp, splqt, &tmp))
			&& tmp);
			{
				llistclear(&llst, freeargt);
				return (llistclear(&argvllst, freeargvt));
			}
	return (argvllst);
}

static void	printargvt(void *data)
{
	t_argv *argvt;

	argvt = (t_argv *)data;
	printf("operation:\t%d\nPATH:\t%s\nSTR:\t%s\nINFILE:\t%s\nOUTFILE:\t%s\n",
		argvt->oper, argvt->path, argvt->str, argvt->infile, argvt->outfile);
	printmatrix((t_cchar **)argvt->argv);
	ft_putchar('\n');
}

int main(int argc, char **argv, char **envp)
{
	char	str[] =  "< file.txt grep 135 | wc -l > file1.txt";
	t_llist *llst;
	t_llist	*argvllst;
    t_splqt	*splqt;

	splqt = crtsplqtt((t_cchar **)ft_split("\"0'", SPLTCH),
		(t_cchar **)ft_split(SPLTS, SPLTCH), ' ');
    printmatrix(splqt->qts);
	printmatrix(splqt->splts);
	llst = spliter(str, splqt);
	llistiter(llst, printllist);
	argvllst = getargvllst(str, (t_cchar **)envp, splqt);
	llistiter(argvllst, printargvt);
	// for (int i = 0; i < size; ++i)
	// 	printf("%d\t", i);
	// for (int i = 0; i < size; ++i)
	// 	printf("%c\t", str[i]);
	// printf("\n%s\n", str);
	freesplqtt(splqt);
	llistclear(&llst, freeargt);
	llistclear(&argvllst, freeargvt);
    return (0);
}