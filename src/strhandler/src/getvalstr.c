/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvalstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:15:24 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/22 14:55:56 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../hdrs/strhandlerserv.h"
#include "../../../libft/libft.h"
#include "../../../HashTable/hdrs/hashtable.h"
#include <unistd.h>

char	*getvalstr(t_arg *strt, int oper, t_strtosub *strtosub, t_hashtable *hst)
{
	if (oper < 0)
		return (NULL);
	switch (oper)
	{
	case (I_BRACES):
		return (subbraces(strt, strtosub->subend[I_BRACES], hst));
	case (I_EXTSTS):
		return (subexicd(strt, hst));
	case (I_PID):
		return (ft_itoa(getpid()));		
	}
	return (subvar(strt, hst));
}