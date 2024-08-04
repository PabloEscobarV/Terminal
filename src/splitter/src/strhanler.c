/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhanler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:40:24 by blackrider        #+#    #+#             */
/*   Updated: 2024/08/04 19:17:17 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"
#include "../../../ft_printf/headers/ft_printf_bonus.h"
#include "../../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

char    *strcpytoll(t_cchar **args, t_crds *crd, t_cchar **qts)
{
	int	iqt;

	iqt = cmpqts(*args, qts);
	if (iqt >= IQTSSIZE)
		return (NULL);
	qts += iqt;
	*args += ft_strlen(*qts);
	if (!(**args))
		return (putsprintf(ft_sprintf("%s%s\n", ERRQTS, *qts), &(crd->size)));
	return (sqtshadler(args, crd, *qts));
}

// t_cchar	*hash(t_cchar *key, char **hashtb)
// {
// 	return (ft_strdup("ABC"));
// }

// void	printmatrix(t_cchar **argv)
// {
// 	while (*argv)
// 	{
// 		printf("%s\n", *argv);
// 		++argv;
// 	}
// }

// int	main()
// {
// 	t_hash		hst;
// 	t_cchar		*args;
// 	t_cchar		*str;
// 	t_cchar		**qts = (t_cchar **)ft_split("\" \'", ' ');
// 	char		*res;

// 	hst.hash = hash;
// 	hst.hashtb = NULL;
// 	args = ft_strdup("\"|\\\"$var\\\"|\" >> file.txt");
// 	str = args;
// 	printmatrix(qts);
// 	res = strhandler(&args, qts, &hst);
// 	if (!res)
// 		printf("ERROR!!!\n");
// 	else
// 	{
// 		printf("|%s|\n", res);
// 		printf("finded size:\t%d\n", ft_strlen(res));
// 		printf("size for input string:\t%d\tEND:\t|%s|\n", ft_strlen(str), args);
// 	}
// 	// printf("real size:\t%d\n", ft_strlen(res));
// 	free(res);
// 	free((void *)str);
// 	ft_free_d((void **)qts);
// 	return (0);
// }
// echo \"data \\\"DATA\\\" $var after var\" >> file.txt
// data from str. $ \\$var $var1 \\\"$vvar into $ \\$ $var\\\" into file: $var 

// char    *strhandler(t_indata *indt, t_crds *crd, t_cchar iqt, f_hash hashf)
// {
// 	char    	*res;
// 	t_llist		*llst;

// 	if (!(*(indt->args + crd->i)) || !(*(indt->args + crd->i + 1)))
// 		return (ft_strdup(indt->args + crd->i));
// 	llst = strsizeexc(indt->args + crd->i, indt->hashtb, iqt, hashf);
// 	res = malloc((*((int *)llst->data) + 1) * sizeof(char));
// 	if (!res)
// 		return (ft_perror(MALLOCERROR));
// 	crd->i += setresstr(res, indt->args + crd->i, iqt, llst->next);
// 	// free(llst->data);
// 	llistclear(&llst, free);
// 	return (res);
// }

// "$\n data from str. $ \\$var $var1 \\\"$vvar into $ \\$ $var\\\" into file: $var ; echo data \\\"DATA\\\" $var after var >> file.txt\"