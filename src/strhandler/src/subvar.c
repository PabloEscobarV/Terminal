/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subvar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:19:35 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/04 17:33:26 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../hdrs/strhandlerserv.h"
#include "../../../libft/libft.h"

char	*subvar(t_arg *strt, t_hash *hst)
{
	int	size;

	if (checkvarfront(strt->arg[strt->x]))
		return (NULL);
	size = strt->x;
	while (strt->arg[size] && !checkvarend(strt->arg[size]))
		++size;
	size -= strt->x;
	if (!size)
		return (NULL);
	return (getvar(strt, size, hst));
}
