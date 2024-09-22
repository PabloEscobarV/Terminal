/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:42:36 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/22 14:58:41 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/netdata.h"
#include "../splitter/hdrs/splitter.h"
#include "../strhandler/hdrs/strhandler.h"
#include "../../../HashTable/hdrs/hashtable.h"
#include <stdio.h>
#include <readline/readline.h>

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
	int				hstsize = 64;
	t_strtosub		tmpt;
	char			*str;
	char			*line;
	t_hashtable		*hst;
	t_llist			*ndata;
	t_llist			*spliterll;
	t_splqt			*splqt;
	

	hst = crthashtable(hstsize);
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
		str = strhandler(line, &tmpt, hst);
		spliterll = spliter(str, splqt);
		ndata = netdata(str, spliterll, splqt);
		llistiter(ndata, printargvtllist);		
		llistclear(&ndata, freeargvt);
		llistclear(&spliterll, freeargt);
		free(line);
		free(str);
	}
	freesplqtt(splqt);
	free(line);
	ft_free_d((void **)tmpt.subend);
	ft_free_d((void **)tmpt.substr);
	free(tmpt.qts);
	freehashtablet(hst);
	return (0);
}