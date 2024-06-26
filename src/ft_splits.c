/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:41:10 by polenyc           #+#    #+#             */
/*   Updated: 2024/06/25 13:57:46 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static int		issplt(const char *str, const char **splt)
{
	const char	*tmp;

	while (*splt)
	{
		tmp = ft_strlcmp(str, (const char *)*splt);
		if (tmp)
			return (tmp - str);
		++splt;
	}
	return (0);
}

static int		ft_offset(const char *str, const char **splt, int strsize)
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

static t_llist	*setnodedata(const char **splt, const char *str, int size, int *i)
{
	int		offset;
	t_llist	*node;

	*i += ft_offset(str + *i, splt, size);
 	offset = ft_offset(str + *i, splt, size);
	node = llistnewnode(crtargt(NULL, *i, 0));
	while (!offset && ++(*i) < size)
		offset = ft_offset(str + *i, splt, size);
	((t_arg *)(node->data))->size = *i - ((t_arg *)(node->data))->x;
	*i += offset;
	return (node);
}

static t_llist	*setllstdata(const char *str, const char **splt)
{
	int		i;
	int		strsize;
	t_llist	*llst;

	strsize = ft_strlen(str);
	llst = NULL;
	i = 0;
	while (i < strsize)
		llistadd_back(&llst, setnodedata(splt, str, strsize, &i));
	return (llst);
}

t_llist	*ft_splits(const char *str, const char **splt)
{
	t_llist	*llst;
	t_llist	*ll;

	if (!str || !splt)
		return (NULL);
	llst = setllstdata(str, splt);
	if (!llst)
		return (NULL);
	ll = llst;
	while (ll)
	{
		((t_arg *)(ll->data))->arg = ft_strndup(str + ((t_arg *)(ll->data))->x,
			((t_arg *)(ll->data))->size);
		ll = ll->next;
	}
	return (llst);
}

// char	**ft_splits(const char *str, const char **splt)
// {
// 	int		size;
// 	char	**strs;
// 	t_llist	*llst;

// 	if (!str || !splt)
// 		return (NULL);
// 	llst = setllstdata(str, splt);
// 	size = llistsize(llst);
// 	strs = malloc((size + 1) * sizeof(char *));
// 	if (!strs)
// 		return (llistclear(&llst, ft_freenode));
// 	strs[size] = NULL;
// 	if (llst->previous)
// 		llst = llst->previous;
// 	while (size && llst)
// 	{
// 		--size;
// 		strs[size] = ft_strndup(str + ((int *)(llst->data))[0],
// 			((int *)(llst->data))[1]);
// 		llst = llst->previous;
// 	}
// 	llistclear(&llst, ft_freenode);
// 	return (strs);
// }

// char	**llist_splits(t_llist **llst, const char *str, const char **splt)
// {
// 	int		size;
// 	char	**strs;
// 	t_llist	*ll;

// 	if (!str || !splt)
// 		return (NULL);
// 	*llst = setllstdata(str, splt);
// 	ll = *llst;
// 	size = llistsize(*llst);
// 	strs = malloc((size + 1) * sizeof(char *));
// 	if (!strs)
// 		return (llistclear(llst, ft_freenode));
// 	strs[size] = NULL;
// 	if ((*llst)->previous)
// 		*llst = (*llst)->previous;
// 	while (size && llst)
// 	{
// 		--size;
// 		strs[size] = ft_strndup(str + ((int *)((*llst)->data))[0],
// 			((int *)((*llst)->data))[1]);
// 		*llst = (*llst)->previous;
// 	}
// 	*llst = ll;
// 	return (strs);
// }