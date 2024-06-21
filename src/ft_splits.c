/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:08:25 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/21 17:44:31 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	*crtdata(int a, int b)
{
	int	*tmp;

	tmp = malloc(2 * sizeof(int));
	tmp[0] = a;
	tmp[1] = b;
	return (tmp);
}

char	*ft_strndup(const char *src, int n)
{
	char	*tmp;

	tmp = malloc(++n * sizeof(char));
	if (!tmp)
		return (NULL);
	if (ft_strncpy(tmp, src, n))
	{
		free(tmp);
		ft_putstr("ERROR!!!:\tft_strndup\n");
		return (NULL);
	}
	return (tmp);
}

static t_llist	*setcrd(const char *str, const char *splt)
{
	int		j;
	int		i;
	t_llist	*llst;
	t_llist	*newnode;

	i = 0;
	llst = NULL;
	while (str[i])
	{
		j = i;
		if (ft_strchr(splt, str[i]))
			while (str[++i] && str[i] == str[j]);
		if (!str[i])
			return (llst);
		newnode = llistnewnode(crtdata(i, 0));
		while (str[++i] && !ft_strchr(splt, str[i]));
		((int *)(newnode->data))[1] = i - ((int *)(newnode->data))[0];
		llistadd_back(&llst, newnode);
	}
	return (llst);
}

char	**ft_splits(const char *str, const char *splt)
{
	int		size;
	char	**strs;
	t_llist	*llst;

	llst = setcrd(str, splt);
	size = llistsize(llst);
	strs = malloc((size + 1) * sizeof(char *));
	if (!strs)
		return (llistclear(&llst, ft_freenode));
	strs[size] = NULL;
	llst = llst->previous;
	while (size)
	{
		--size;
		strs[size] = ft_strndup((str + ((int *)(llst->data))[0]),
			((int *)(llst->data))[1]);
		llst = llst->previous;
	}
	llistclear(&llst, ft_freenode);
	return (strs);
}

void	printmatrix(char **matrix)
{
	while (*matrix)
	{
		printf("%s\n", *matrix);
		++matrix;
	}
}

int	main()
{
	char	**res;

	res = ft_splits("|||avf|||bg|$01234$0000  123   $$", " |$");
	printmatrix(res);
	return (0);
}