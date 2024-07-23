/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhanler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:40:24 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/23 14:52:03 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	fakefree(void *data)
{

}

char    *strhandler(t_cchar *args, t_crds *crd, t_cchar **qts, t_hash *hst)
{
	char	*tmp;
	int		size;
	int		iqt;

	args += crd->i;
	iqt = cmpqts(args, qts);
	if (iqt >= IQTSSIZE)
		return (NULL);
	qts += iqt;
	size = ft_strlen(qts);
	args += size; 
	crd->i += size;
	if (iqt == I_DQTS)
		return (dqtshandler(args, crd, qts, hst));
	return (sqtshadler(args, crd, qts));
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
// 	t_crds		crd;
// 	t_cchar		**qts = (t_cchar **)ft_split("\" \'", ' ');
// 	char		*res;

// 	hst.hash = hash;
// 	hst.hashtb = NULL;
// 	crd.i = 0;
// 	args = ft_strdup("\"$\n data from str. $ \\$var $var1 \\\"$vvar into $ \\$ $var\\\" into file: $var ; echo data \\\"DATA\\\" $var after var\" >> file.txt);");
// 	printmatrix(qts);
// 	res = strhandler(args, &crd, qts, &hst);
// 	if (!res)
// 		printf("ERROR!!!\n");
// 	else
// 	{
// 		printf("|%s|\n", res);
// 		printf("finded size:\t%d\n", ft_strlen(res));
// 		printf("size for input string:\t%d\tcrd->i:\t%d\t|%s|\n", ft_strlen(args), crd.i, args + crd.i);
// 	}
// 	// printf("real size:\t%d\n", ft_strlen(res));
// 	free(res);
// 	free((void *)args);
// 	ft_free_d(qts);
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

// \"$\n data from str. $ \\$var $var1 \\\"$vvar into $ \\$ $var\\\" into file: $var ; echo data \\\"DATA\\\" $var after var >> file.txt\"