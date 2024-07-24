/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argshndlr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:11:39 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/07/24 17:32:54 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../../../libft/libft.h"

t_cchar	*getdev(t_cchar *args, t_cchar **splt)
{
	while (*splt && !ft_strlcmp(args, *splt))
		++splt;
	return (*splt);
}

t_cchar	*getend(t_cchar *args, t_cchar **splt)
{
	t_cchar	*tmp;

	tmp = args;
	while (*args && !getdev(args, splt))
		++args;
	if ((tmp - args) > 0)
		return (args);
	++args;
	while (*args && !ft_isspace(*args) && !getdev(args, splt))
		++args;
	return (args);
}

t_uchar	skipspc(t_cchar *args, t_cchar *end, t_crds *crd)
{
	t_cchar	*tmp;

	tmp = args;
	while (args < end && ft_isspace(*args))
		++args;
	if (args == end)
		return (0);
	crd->i = args - tmp;
	tmp = end;
	while (ft_isspace(*end))
		--end;
	crd->size = tmp - end;
	return (1);
}

char	*getargs(t_cchar **args, t_cchar *splt)
{
	t_crds	crd;
	t_cchar	*end;
	char	*str;

	end = getend(*args, splt);
	if (!skipspc(args, end, &crd))
		return (NULL);
	str = ft_strndup(*(args + crd.i), crd.size);
	*args = end;
	return (str);
}

char	*argshndlr(t_cchar **args, t_splqt *splt)
{
	while ()
}