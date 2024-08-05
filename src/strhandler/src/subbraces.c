/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subbraces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:20:24 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/05 17:44:55 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../hdrs/strhandlerserv.h"
#include "../../../libft/libft.h"

char	*subbraces(t_arg *strt, char *end, t_hash *hst)
{
	int		i;
	char	*res;

	i = strt->x;
	if (checkvarfront(strt->arg[strt->x]))
		return (NULL);
	while (strt->arg[i] && !ft_strlcmp(strt->arg + i, end)
		&& !checkvarend(strt->arg[i]))
		++i;
	if (!strt->arg[i] || i == strt->x || !ft_strlcmp(strt->arg + i, end))
	{
		strt->size = -1;
		return (ft_perror("Command not found"));
	}
	res = getvar(strt, i - strt->x, hst);
	++(strt->x);
	return (res);
}
