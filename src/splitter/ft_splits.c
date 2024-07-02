/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:41:10 by polenyc           #+#    #+#             */
/*   Updated: 2024/07/02 14:42:34 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/splitter.h"
#include "../../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static char	***crtspltrs(t_cchar *splts, char delimer, int size)
{
	int		tmp;
	int		i;
	char	***spltrs;

	spltrs = malloc((size + 1) * sizeof(char **));
	if (!spltrs)
		return (NULL);
	spltrs[size] = NULL;
	i = 0;
	tmp = 0;
	while (i < size)
	{
		spltrs[i] = ft_split(splts + tmp, delimer);
		tmp = ft_strlen(splts) + 1;
		++i;
	}
	return (spltrs);
}

static int		issplt(t_cchar *str, t_cchar **splt)
{
	t_cchar	*tmp;

	while (*splt)
	{
		tmp = ft_strlcmp(str, (t_cchar *)*splt);
		if (tmp)
			return (tmp - str);
		++splt;
	}
	return (0);
}

static int		ft_offset(t_cchar *str, t_cchar **splt, int strsize)
{
    int tmp;
    int i;

    i = issplt(str, splt);
    if (!i)
        return (0);
    while (i < strsize)
    {
        tmp = issplt(str + i, splt);
        if (!tmp)
            return (i);
        i += tmp;
    }
    return (strsize);
}

static t_llist	*setdata(t_cchar *str, int *si, t_cchar **splt)
{
	int		offset;
	t_llist	*node;

	si[1] += ft_offset(str + si[1], splt, si[0]);
 	offset = ft_offset(str + si[1], splt, si[0]);
	node = llistnewnode(crtargt(NULL, si[1], 0));
	while (!offset && ++(si[1]) < si[0])
		offset = ft_offset(str + si[1], splt, si[0]);
	((t_arg *)(node->data))->size = si[1] - ((t_arg *)(node->data))->x;
	((t_arg *)(node->data))->arg = ft_strndup(str + si[1], ((t_arg *)(node->data))->size);
	si[1] += offset;
	return (node);
}

static t_llist	*setllstdata(t_cchar *str, t_cchar **splt)
{
	int		si[2];
	t_llist	*llst;

	si[0] = ft_strlen(str);
	llst = NULL;
	si[1] = 0;
	while (si[1] < si[0])
		llistadd_back(&llst, setdata(str, si, splt));
	return (llst);
}

t_llist	*ft_splits(t_cchar *str, t_cchar **splt)
{
	t_llist	*llst;

	if (!str || !splt)
		return (NULL);
	llst = setllstdata(str, splt);
	if (!llst)
		return (NULL);
	return (llst);
}

int main()
{
	char	str[] =  "a|b";
	t_llist *llst;
    t_splqt	*splqt;

	splqt = crtsplqtt((t_cchar **)ft_split("\"0'", SPLTCH),
		(t_cchar **)ft_split("||0$$0>>0<<0|0$0<0>", SPLTCH), ' ');
    printmatrix(splqt->qts);
	printmatrix(splqt->splts);
	llst = ft_splits(str, splqt->splts);
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