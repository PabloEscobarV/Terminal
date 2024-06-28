/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:10:06 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/28 19:53:19 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	isqtssv(t_cchar *str, t_cchar ***splt)
{
	t_cchar	*tmp;

	while (**splt)
	{
		tmp = ft_strlcmp(str, (t_cchar *)**splt);
		if (tmp)
			return (tmp - str);
		++(*splt);
	}
	return (0);
}

static int	offsetqt(t_cchar *str, t_crds *crds, t_cchar **qts)
{
	t_cchar	*tmp;

	crds->size = isqtssv(str + crds->i, &qts);
	if (!crds->size)
		return (0);
	crds->i += crds->size;
	crds->size = crds->i;
	while (crds->size < crds->strsize)
	{
		tmp = ft_strlcmp(str + crds->size, *qts);
		if (tmp)
			return ((int)(tmp - str) - crds->size);
		++crds->size;
	}
	return (-1);
}

static int	cmpstrv(t_cchar *str, t_cchar **splt)
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

static int	skipsplt(t_cchar *str, t_crds *crds, t_splqt *splt)
{
	crds->size = cmpstrv(str + crds->i, splt->splts);
	while (crds->size)
	{
		if (crds->i >= crds->strsize)
			return (crds->i);
		crds->i += crds->size;
		crds->size = cmpstrv(str + crds->i, splt->splts);
	}
	return (0);
}

static int	offset(t_cchar *str, t_crds *crds, t_splqt *splt)
{
	int	tmp;

	if (skipsplt(str, crds, splt))
		return (0);
	crds->size = crds->i;
	tmp = 0;
	while (!tmp && ++crds->size < crds->strsize)
	{
		tmp = cmpstrv(str + crds->size, splt->qts);
		if (tmp)
			return (0);
		tmp = cmpstrv(str + crds->size, splt->splts);
	}
	return (tmp);
}

static t_llist	*setnodedata(t_cchar *str, t_crds *crds, t_splqt *splt)
{
	int		tmp;
	t_llist	*node;

	tmp = offsetqt(str, crds, splt->qts);
	if (tmp < 0)
		return (NULL);
	if (!tmp)
		tmp = offset(str, crds, splt);
	if (crds->i >= crds->strsize)
		return (NULL);
	node = llistnewnode(crtargt(ft_strndup(str + crds->i, crds->size - crds->i),
		crds->i, crds->size));
	crds->i = tmp + crds->size;
	return (node);
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
	while (crds.size < crds.strsize)
		llistadd_back(&llst, setnodedata(str, &crds, splt));
	return (llst);
}

int main()
{
	char	str[] = "echo \"data\" >> file.txt $$ echo \"data | data || datat $$ data $ datat\" >> file2.txt";
	int		size;
    t_llist *llst;
    t_splqt	*splqt;

	splqt = crtsplqtt((t_cchar **)ft_split("\"0'", SPLTCH),
		(t_cchar **)ft_split(" || 0 $$ 0 >> 0 << 0 | 0 $ 0|0$", SPLTCH));
    printmatrix(splqt->qts);
	printmatrix(splqt->splts);
	llst = spliter(str, splqt);
    size = ft_strlen(str);
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