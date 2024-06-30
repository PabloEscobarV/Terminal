/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:10:06 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/30 16:36:39 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../../../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static void		skipspaces(t_cchar *str, t_crds* crds, t_splqt *splt)
{
	while (str[crds->i] && str[crds->i] == splt->spcs)
		++crds->i;
	if (crds->i >= crds->strsize)
		return ;
	while (--crds->size && str[crds->size] == splt->spcs);
	++crds->size;
	crds->strsize = crds->size - crds->i;
}

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
	skipspaces(str, &crds, splt);
	while (crds.i < crds.strsize)
	{
		if (llistadd_back(&llst, setnodestr(str, &crds, splt)))
			continue ;
		llistadd_back(&llst, setnodedata(str, &crds, splt));
	}
	if (crds.size < 0)
		return (llistclear(&llst, freeargt));
	return (llst);
}

int main()
{
	char	str[] = " | | | | |||$$$     objdump -M intel -D ./test | grep -A20 main.: || wc -l $$ ls -a || cd .. | echo \" data1 || data2 | data3 $$ data4 $ data5 | \" >> file.txt   | | | | | | | | | | |";
	t_llist *llst;
    t_splqt	*splqt;

	splqt = crtsplqtt((t_cchar **)ft_split("\"0'", SPLTCH),
		(t_cchar **)ft_split("||0$$0>>0<<0|0$0", SPLTCH), ' ');
    printmatrix(splqt->qts);
	printmatrix(splqt->splts);
	llst = spliter(str, splqt);
	// for (int i = 0; i < size; ++i)
	// 	printf("%d\t", i);
	// for (int i = 0; i < size; ++i)
	// 	printf("%c\t", str[i]);
	// printf("\n%s\n", str);
	llistiter(llst, printllist);
	freesplqtt(splqt);
	llistclear(&llst, freeargt);
    return (0);
}

// "|||$$$     objdump -M intel -D ./test | grep -A20 main.: || wc -l $$ ls -a || cd .. | echo \" data1 || data2 | data3 $$ data4 $ data5 | \" >> file.txt   ||";
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