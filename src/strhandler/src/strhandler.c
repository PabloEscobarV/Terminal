/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:36:48 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/29 16:03:53 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../hdrs/strhandlerserv.h"
#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"
#include "../../../HashTable/hdrs/hashtable.h"
#include "../../../hdrs/commondata.h"
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>

#define T_ARG(argtll)	((t_arg *)((argtll)->data))

static int	cpyqts(t_arg *argt, t_arg *strt, char end)
{
	while (strt->x < strt->size)
	{
		if (argt->x >= argt->size)
			setnewparam(argt);
		argt->arg[argt->x] = strt->arg[strt->x];
		++argt->x;
		++strt->x;
		if (strt->arg[strt->x] == end && strt->arg[strt->x - 1] != BKSLASH)
		{
			if (argt->x >= argt->size)
				setnewparam(argt);
			argt->arg[argt->x] = strt->arg[strt->x];
			++argt->x;
			++strt->x;
			return (E_OK);
		}
	}
	ft_perror(QTSERRMSG);
	return (E_ERR);
}

static void	writedata(t_arg *argt, t_arg *strt)
{
	if (strt->arg[strt->x] == BKSLASH && strt->arg[strt->x + 1]
		&& ft_strchr(ESCSMBS, strt->arg[strt->x + 1]))
		++strt->x;
	argt->arg[argt->x] = strt->arg[strt->x];
	++strt->x;
	++argt->x;
}

static void	cpydata(t_arg *argt, char *tmp)
{
	while (*tmp)
	{
		if (argt->x >= argt->size)
			setnewparam(argt);
		argt->arg[argt->x] = *tmp;
		++tmp;
		++argt->x;
	}
}

static int	setdata(t_arg *argt, t_arg *strt, t_strtosub *strtosub, t_hashtable *hst)
{
	char	*tmp;

	while (strt->x < strt->size)
	{
		if (argt->x >= argt->size)
			setnewparam(argt);
		if (strt->arg[strt->x] == strtosub->qts[I_SQTS])
		{
			if (cpyqts(argt, strt, strtosub->qts[I_SQTS]))
				return (E_ERR);
			continue ;
		}
		tmp = getvalstr(strt, getoperation(strt, strtosub->substr),
				strtosub, hst);
		if (strt->size < 0)
			return (E_ERR);
		if (tmp)
		{
			cpydata(argt, tmp);
			free(tmp);
			continue ;
		}
		writedata(argt, strt);
	}
	return (E_OK);
}

char	*strhandler(char *str, t_strtosub *strtosub, t_hashtable *hst)
{
	static float	kef = 1.0;
	t_arg			argt;
	t_arg			strt;

	if (!str || !hst || !(*str))
		return (ft_perror("ERROR!!! EMPTY ARGUMENT!!!"));
	str = handlvariable(str, hst);
	if (!str || !(*str))
		return (NULL);
	setargt(&strt, str, 0, ft_strlen(str));
	setargt(&argt, NULL, 0, strt.size * kef);
	argt.arg = malloc((argt.size + 1) * sizeof(char));
	argt.arg[argt.size] = '\0';
	if (setdata(&argt, &strt, strtosub, hst))
		return (ft_free(argt.arg));
	argt.arg[argt.x] = '\0';
	kef = updatekef(kef, argt.x - strt.size * kef);
	return (argt.arg);
}

// void	*hash(t_cchar *key, char **hashtb)
// {
// 	return ((void *)ft_strdup("ABC"));
// }

// int	main()
// {
// 	char	*argt;
// 	char	*line;
// 	char	**substr;
// 	char	**subend;
// 	t_hash	hst;
// 	t_strtosub	tmpt;
// 	hst.hash = hash;
// 	hst.hashtb = NULL;
// 	tmpt.qts = ft_strdup("\"\'");
// 	tmpt.substr = ft_split(SUBSTR, SPLTCH);
// 	tmpt.subend = ft_split(SUBEND, SPLTCH);
// 	while (1)
// 	{
// 		line = readline("Pablo Escobar:\t");
// 		if (!ft_strcmp(line, "exit"))
// 			break ;
// 		printf("%s\n", line);
// 		argt = strhandler(line, &tmpt, &hst);
// 		printf("|%s|\n", argt);
// 		free(argt);
// 		free(line);
// 	}
// 	free(line);
// 	ft_free_d((void **)tmpt.subend);
// 	ft_free_d((void **)tmpt.substr);
// 	free(tmpt.qts);
// 	return (0);
// }