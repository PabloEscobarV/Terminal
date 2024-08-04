/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:36:48 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/04 19:34:26 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../hdrs/strhandlerserv.h"
#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"
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

static int	setdata(t_arg *argt, t_arg *strt, t_strtosub *strtosub, t_hash *hst)
{
	char	*tmp;

	while (strt->arg[strt->x])
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
		if (tmp)
		{
			cpydata(argt, tmp);
			free(tmp);
		}
		else
			writedata(argt, strt);
	}
	return (E_OK);
}

char	*strhandler(char *str, t_strtosub *strtosub, t_hash *hst)
{
	static float	kef = 1.0;
	t_arg			argt;
	t_arg			strt;

	if (!str || !hst || !(*str))
		return (ft_perror("ERROR!!! EMPTY ARGUMENT!!!"));
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
