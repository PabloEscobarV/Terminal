/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvarval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:18:35 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/04 17:22:01 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../../../libft/libft.h"

char	*getvarval(char *args, int size, t_hash *hst)
{
	char	*varval;

	args = ft_strndup(args, size);
	varval = hst->hash(args, hst->hashtb);
	free(args);
	return (varval);
}

char	*getvar(t_arg *strt, int size, t_hash *hst)
{
	char	*varval;
	
	if (!size)
		return (NULL);
	varval = getvarval(strt->arg + strt->x, size, hst);
	if (!varval)
	{
		ft_putstr(MALLOCERROR);
		exit(-1);
	}
	strt->x += size;
	return (varval);
}

int	getoperation(t_arg *strt, char **substr)
{
	int		i;

	if (strt->arg[strt->x] != VARCH)
		return (E_ERR);
	if ((strt->x && ft_strchr(FESC, strt->arg[strt->x - 1]))
		|| ft_strchr(RESC, strt->arg[strt->x + 1]))
		return (E_ERR);
	i = 0;
	while (substr[i] && !ft_strlcmp(strt->arg + strt->x, substr[i]))
		++i;
	if (i < I_SUBSTRSIZE)
		strt->x += ft_strlen(substr[i]);
	else
		++(strt->x);
	return (i);
}
