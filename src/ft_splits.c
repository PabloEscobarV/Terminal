/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:41:10 by polenyc           #+#    #+#             */
/*   Updated: 2024/06/28 14:44:54 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	isqts(t_cchar *str, t_cchar **splt)
{
	t_cchar	*tmp;

	while (*splt)
	{
		tmp = ft_strlcmp(str, (t_cchar *)*splt);
		if (tmp)
			return (tmp - str);
		++(splt);
	}
	return (0);
}

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

static int	issplt(t_cchar *str, t_cchar **splt)
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

static int	ft_offsetqt(t_cchar *str, t_cchar **qts, int *crd, int strsize)
{
	t_cchar	*tmp;

	crd[1] = isqtssv(str + crd[0], &qts);
	if (!crd[1])
		return (0);
	crd[1] += crd[0];
	crd[0] = crd[1];
	tmp = ft_strlcmp(str + crd[1], (t_cchar *)*qts);
	while (!tmp && (++crd[1] < strsize))
		tmp = ft_strlcmp(str + crd[1], (t_cchar *)*qts);
	if (crd[1] >= strsize)
		return (-1);
	str += crd[1];
	crd[1] -= crd[0];
	return ((int)(tmp - str));
}

static int	skipsplts(t_cchar *str, t_cchar **splt, int *crd, int strsize)
{
	int	tmp;

    tmp = issplt(str + crd[0], splt);
	crd[1] = tmp + crd[0];
	while (tmp)
	{
		if (crd[1] >= strsize)
		{
			crd[0] = crd[1];
			return (tmp);
		}
		tmp = issplt(str + crd[1], splt);
		crd[1] += tmp;
	}
	crd[0] = crd[1];
	return (0);
}
static int	ft_offset(t_cchar *str, t_splqt *splt, int *crd, int strsize)
{
    int tmp;

	tmp = skipsplts(str, splt->splts, crd, strsize);
	if (tmp)
		return (tmp);
    while (!tmp && crd[1] < strsize)
	{
		tmp = isqts(str + crd[1], splt->qts);
		if (tmp)
		{
			tmp = 0;
			break ;
		}
		++crd[1];
        tmp = issplt(str + crd[1], splt->splts);
	}
	crd[1] -= crd[0];
	return (tmp);
}

static t_llist	*setnodedata(t_cchar *str, int *si, t_splqt *splt)
{
	int		tmp;
	int		crd[2];
	t_llist	*node;

	crd[0] = si[1];
	tmp = ft_offsetqt(str, splt->qts, crd, si[0]);
	if (!tmp)
		tmp = ft_offset(str, splt, crd, si[0]);
	si[1] = tmp + crd[0] + crd[1];
	if (crd[0] >= si[0])
		return (NULL);
	if (!crd[1])
		return (NULL);
	node = llistnewnode(crtargt(NULL, crd[0], crd[1]));
	((t_arg *)(node->data))->arg = ft_strndup(str + crd[0], crd[1]);
	return (node);
}

static t_llist	*setllstdata(t_cchar *str, t_splqt *splt)
{
	int			si[2];
	t_llist		*llst;

	si[0] = ft_strlen(str);
	llst = NULL;
	si[1] = 0;
	while ((si[1] < si[0]))
		llistadd_back(&llst, setnodedata(str, si, splt));
	return (llst);
}

t_llist	*ft_splits(t_cchar *str, t_splqt *splt)
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
    t_llist *llst;
    t_splqt	*splqt;

	splqt = crtsplqtt((t_cchar **)ft_split("\"0'", SPLTCH),
		(t_cchar **)ft_split("||0$$0>>0|0$", SPLTCH));
    // printmatrix(splqt->qts);
	// printmatrix(splqt->splts);
	llst = ft_splits("|$||$$|$grep -A2 | echo \"data || data | datta >> data\" >> file1.txt||$$||$", splqt);
    llistiter(llst, printllist);
	freesplqtt(splqt);
	llistclear(&llst, freeargt);
    return (0);
}

// static char	***crtspltrs(t_cchar *splts, char delimer, int size)
// {
// 	int		tmp;
// 	int		i;
// 	char	***spltrs;

// 	spltrs = malloc((size + 1) * sizeof(char **));
// 	if (!spltrs)
// 		return (NULL);
// 	spltrs[size] = NULL;
// 	i = 0;
// 	tmp = 0;
// 	while (i < size)
// 	{
// 		spltrs[i] = ft_split(splts + tmp, delimer);
// 		tmp = ft_strlen(splts) + 1;
// 		++i;
// 	}
// 	return (spltrs);
// }


// static int		issplt(t_cchar *str, t_cchar **splt)
// {
// 	t_cchar	*tmp;

// 	while (*splt)
// 	{
// 		tmp = ft_strlcmp(str, (t_cchar *)*splt);
// 		if (tmp)
// 			return (tmp - str);
// 		++splt;
// 	}
// 	return (0);
// }

// static int		ft_offset(t_cchar *str, t_cchar **splt, int strsize)
// {
//     int tmp;
//     int i;

//     i = issplt(str, splt);
//     if (!i)
//         return (0);
//     while (i < strsize)
//     {
//         tmp = issplt(str + i, splt);
//         if (!tmp)
//             return (i);
//         i += tmp;
//     }
//     return (strsize);
// }

// static t_llist	*setnodedata(t_cchar **splt, t_cchar *str, int *si)
// {
// 	int		offset;
// 	t_llist	*node;

// 	si[1] += ft_offset(str + si[1], splt, si[0]);
//  	offset = ft_offset(str + si[1], splt, si[0]);
// 	node = llistnewnode(crtargt(NULL, si[1], 0));
// 	while (!offset && ++(si[1]) < si[0])
// 		offset = ft_offset(str + si[1], splt, si[0]);
// 	((t_arg *)(node->data))->size = si[1] - ((t_arg *)(node->data))->x;
// 	si[1] += offset;
// 	return (node);
// }

// static t_llist	*setllstdata(t_cchar *str, t_cchar **splt)
// {
// 	int		si[2];
// 	t_llist	*llst;

// 	si[0] = ft_strlen(str);
// 	llst = NULL;
// 	si[1] = 0;
// 	while (si[1] < si[0])
// 		llistadd_back(&llst, setnodedata(str, si, splt));
// 	return (llst);
// }

// t_llist	*ft_splits(t_cchar *str, t_cchar **splt)
// {
// 	t_llist	*llst;

// 	if (!str || !splt)
// 		return (NULL);
// 	llst = setllstdata(str, splt);
// 	if (!llst)
// 		return (NULL);
// 	return (llst);
// }