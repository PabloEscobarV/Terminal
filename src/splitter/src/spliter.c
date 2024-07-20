/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:10:06 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/20 18:42:49 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../../../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>

t_llist	*spliter(t_cchar *str, t_splqt *splt)
{
	t_crds	crds;
	t_llist	*llst;

	if (!str || !splt)
		return (NULL);
	crds.i = 0;
	crds.size = 0;
	crds.strsize = ft_strlen(str);
	llst = NULL;
	while (crds.size < crds.strsize)
	{
		if (llistadd_back(&llst, setnodestr(str, &crds, splt)))
			continue ;
		llistadd_back(&llst, setnodedata(str, &crds, splt));
	}
	if (crds.i < 0)
		return (llistclear(&llst, freeargt));
	return (llst);
}

// int	main()
// {
// 	char	*line;
// 	t_llist	*llst;
// 	t_splqt	*splqt;
	
// 	splqt = crtsplqtt((t_cchar **)ft_split("\"0'", SPLTCH),
// 		(t_cchar **)ft_split("||0$$0<<0|0$0<0>", SPLTCH), ' ');
// 	while (1)
// 	{
// 		line = readline("Pablo Escobar:\t");
// 		if (!ft_strcmp(line, "exit"))
// 			break ;
// 		printf("%s\n", line);
// 		llst = spliter(line, splqt);
// 		llistiter(llst, printllist);
// 		llistclear(&llst, freeargt);
// 	}
// 	freesplqtt(splqt);
// 	return (0);
// }

// int main()
// {
// 	char	str[] =  "|  greap -A20   |  cd .. ||";
// 	t_llist *llst;
//     t_splqt	*splqt;

// 	splqt = crtsplqtt((t_cchar **)ft_split("\"0'", SPLTCH),
// 		(t_cchar **)ft_split("||0$$0>>0<<0|0$0", SPLTCH), ' ');
//     printmatrix(splqt->qts);
// 	printmatrix(splqt->splts);
// 	llst = spliter(str, splqt);
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("%d\t", i);
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("%c\t", str[i]);
// 	// printf("\n%s\n", str);
// 	llistiter(llst, printllist);
// 	freesplqtt(splqt);
// 	llistclear(&llst, freeargt);
//     return (0);
// }

// " objdump -M intel -D ./test | grep -A2 main.: || echo \"data1 | data2 || datat3 $$ data4 $ data5 |\" >> file.txt $ cd .. $$ ls -a "

// static t_cchar	*cmpstrv(t_cchar *str, t_cchar **splt)
// {
// 	t_cchar	*tmp;

// 	while (*splt && !tmp)
// 	{
// 		tmp = ft_strlcmp(str, (t_cchar *)*splt);
// 		++splt;
// 	}
// 	return (tmp);
// }

// static t_cchar	*skipsplt(t_cchar *str, t_cchar *end, t_cchar **splt)
// {
// 	t_cchar	*tmp;

// 	tmp = cmpstrv(str, splt);
// 	while (tmp && tmp < end)
// 	{
// 		str = tmp;
// 		tmp = cmpstrv(str, splt);
// 	}
// 	return (str);
// }

// static t_cchar	offset(t_cchar **str, t_cchar *end, t_splqt *splt)
// {
// 	t_cchar	*scrd;
// 	t_cchar	*tmp;

// 	*str = skipsplt(*str, end, splt->splts);
// 	tmp = cmpstrv(*str + 1, splt);
// 	while (!tmp && tmp < end)
// 	{
// 		scrd = tmp;
// 		tmp = cmpstrv(tmp, splt);
// 	}
// 	return (scrd);
// }

// static t_llist	*setnodedata(t_cchar **str, t_cchar *end, t_splqt *splt)
// {
// 	t_cchar	*scrd;

// 	scrd = offset(str, end, splt);
// }