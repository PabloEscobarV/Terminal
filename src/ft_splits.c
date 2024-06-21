/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 21:08:25 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/21 23:03:16 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void	printllist(void *data)
{
	printf("[0]: %d\t[1]: %d\n", ((int *)(data))[0], ((int *)(data))[1]);
}

void	*freet_splt(t_splt *data)
{
	if (!data)
		return (NULL);
	free(data->lens);
	free(data);
	return (NULL);
}

t_splt	*crtt_splt(const char *args, const char **splt)
{
	t_splt	*data;

	data = malloc(sizeof(t_splt));
	if (!data)
		return (NULL);
	data->lens = malloc(sizeof(int) * ft_matsize(splt));
	if (!(data->lens))
		freet_splt(data);
	data->args = args;
	data->splt = splt;
	data->args_s = args;
	data->args_f = args + ft_strlen(args) - 1;
	data->sizesplt = 0;
	while (splt[data->sizesplt])
	{
		data->lens[data->sizesplt] = ft_strlen(splt[data->sizesplt]);
		++data->sizesplt;
	}
	return (data);
}

static int	*crtdata(int a, int b)
{
	int	*tmp;

	tmp = malloc(2 * sizeof(int));
	tmp[0] = a;
	tmp[1] = b;
	return (tmp);
}	

static char		checkbn(t_splt *d, int i, int j)
{
	if (d->args + i == d->args_s)
		return (0);
	if (d->args + i - d->lens[j] >= d->args_s)
		if (!ft_strncmp(d->args + i - d->lens[j], d->splt[j], d->lens[j]))
			return (0);
	if (d->args + d->lens[j] < d->args_f)
		if (ft_strncmp(d->args + i + d->lens[j], d->splt[j], d->lens[j]))
			return (1);
	return (0);
}

static char		checksplt(t_splt *d, int i_args)
{
	int	j;

	j = 0;
	while (d->splt[j])
	{
		if (ft_strncmp(d->args + i_args, d->splt[j], d->lens[j]))
		{
			++j;
			continue ;
		}
		if (checkbn(d, i_args, j))	
			return (d->lens[j]);
		++j;
	}
	return (0);
}

t_llist	*llistadd_back(t_llist **llst, t_llist *newnode)
{
	t_llist	*tmp;

	if (!newnode)
		return (NULL);
	if (!(*llst))
	{
		*llst = newnode;
		return (newnode);
	}
	tmp = *llst;
	if (tmp->previous)
	{
		while (tmp->previous->next)
			tmp = tmp->previous;
		newnode->previous = tmp->previous;
		tmp->previous->next = newnode;
	}
	else
	{
		newnode->previous = tmp;
		tmp->next = newnode;
	}
	tmp->previous = newnode;
	return (newnode);
}

static t_llist	*setcrd(t_splt *d)
{
	int		j;
	int		i;
	t_llist	*llst;
	t_llist	*newnode;

	i = -1;
	llst = NULL;
	while (d->args[++i])
	{
		j = checksplt(d, i);
		if (!j)
			continue ;
		if (!llst)
		{
			llst = llistnewnode(crtdata(0, i - 1));
			newnode = llst;
			continue ;
		}
		newnode = llistadd_back(&llst,
			llistnewnode(crtdata(((int *)(newnode->data))[1] + 2, i - 1)));
	}
	// llistadd_back(&llst,
	// 	llistnewnode(crtdata(((int *)(newnode->data))[1] + 2, i - 1)));
	return (llst);
}

// char	**ft_splits(const char *str, const char **splt)
// {
// 	int		size;
// 	char	**strs;
// 	t_llist	*llst;

// 	llst = setcrd(str, splt);
// 	size = llistsize(llst);
// 	strs = malloc((size + 1) * sizeof(char *));
// 	if (!strs)
// 		return (llistclear(&llst, ft_freenode));
// 	strs[size] = NULL;
// 	llst = llst->previous;
// 	while (size)
// 	{
// 		--size;
// 		strs[size] = ft_strndup((str + ((int *)(llst->d))[0]),
// 			((int *)(llst->d))[1]);
// 		llst = llst->previous;
// 	}
// 	llistclear(&llst, ft_freenode);
// 	return (strs);
// }

void	printmatrix(char **matrix)
{
	while (*matrix)
	{
		printf("|%s|\n", *matrix);
		++matrix;
	}
}


int	main()
{
	char	**splt;
	t_splt	*data;
	t_llist	*llst;

	splt = ft_split("|", '0');
	data = crtt_splt("|a|b|d|", (const char **)splt);
	printf("ARGV:\t%s\n", data->args);
	printmatrix(splt);
	for (int i = 0; i < data->sizesplt; ++i)
		printf("[%d]\t%d\n", i, data->lens[i]);
	llst = setcrd(data);
	llistiter(llst, printllist);
	// char	**res;

	// res = ft_splits("|||avf|||bg|$01234$0000  123   $$", " |$");
	// printmatrix(res);
	return (0);
}

// char	*ft_strstr(const char *str, const char *srch, size_t len)
// {
// 	size_t	i;

// 	if (!(*srch))
// 		return ((char *)str);
// 	while (*str && len > 0)
// 	{
// 		i = 0;
// 		while (srch[i] && *(str + i) == srch[i] && i < len)
// 			++i;
// 		if (!srch[i])
// 			return ((char *)str);
// 		++str;
// 		--len;
// 	}
// 	return (NULL);
// }