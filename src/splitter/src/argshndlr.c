/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argshndlr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:11:39 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/07/26 22:48:44 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"
#include "../../../libft/libft.h"
#include <stdio.h>

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
	if ((args - tmp) > 0)
		return (args);
	while (ft_isspace(*(++args)));
	while (*args && !ft_isspace(*args) && !getdev(args, splt))
		++args;
	return (args);
}

t_cchar	*skipsplts(t_cchar *args, t_cchar **splt)
{
	int	tmp;

	while (*args)
	{
		tmp = cmpstrv(args, splt);
		if (!tmp)
			return (args);
		args += tmp;
	}
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
	while (ft_isspace(*(--end)));
	crd->size = (int)(end - tmp) + 1 - crd->i;
	return (1);
}

char	*argshndlr(t_cchar **args, t_splqt *splt)
{
	t_crds	crd;
	char	*str;
	t_cchar	*end;

	if (cmpstrv(*args, splt->qts))
		return (NULL);
	end = getend(*args, splt->splts);
	*args = skipsplts(*args, splt->splts);
	if (!skipspc(*args, end, &crd))
	{
		*args = end;
		return (NULL);
	}
	str = ft_strndup((*args + crd.i), crd.size);
	*args = end;
	return (str);
}

// void	printmatrix(t_cchar **matrix)
// {
// 	while (*matrix)
// 	{
// 		printf("%s\n", *matrix);
// 		++matrix;
// 	}
// }

// int	main()
// {
// 	int		size;
// 	t_cchar	*args;
// 	t_cchar	*args_s;
// 	t_cchar	**splt;
// 	char	*str;

// 	args = ft_strdup("< file.txt echo >> file.txt ");
// 	args_s = args;
// 	splt = (t_cchar **)ft_split("<< >> || $$ < > $ | \" \'", ' ');
// 	printmatrix(splt);
// 	size = ft_strlen(args);
// 	while (args - args_s < size)
// 	{
// 		str = argshndlr(&args, splt);
// 		printf("|%s|\t|%s|\n", str, args);
// 		args = skipsplts(args, splt);
// 	}
// 	free(str);
// 	ft_free_d((void **)splt);
// 	return (0);
// }

// t_llist	*nodeargs(t_cchar *args, t_crds *crd, t_cchar **splt)
// {
// 	char	*str;
// 	t_cchar	*tmp;

// 	tmp = args;

// }

// char	*getargs(t_cchar **args, t_cchar *splt)
// {

// }