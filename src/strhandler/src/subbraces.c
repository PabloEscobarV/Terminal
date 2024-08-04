/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subbraces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:20:24 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/04 17:33:17 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../hdrs/strhandlerserv.h"
#include "../../../libft/libft.h"

char	*subbraces(t_arg *strt, char *end, t_hash *hst)
{
	int		size;
	char	*res;

	size = strt->x;
	if (checkvarfront(strt->arg[strt->x]))
		return (NULL);
	while (strt->arg[size] && !ft_strlcmp(strt->arg + size, end)
		&& !checkvarend(strt->arg[size]))
		++size;
	if (size == strt->x || !ft_strlcmp(strt->arg + size, end))
		return (ft_perror("Command not found"));
	res = getvar(strt, size - strt->x, hst);
	++(strt->x);
	return (res);
}
