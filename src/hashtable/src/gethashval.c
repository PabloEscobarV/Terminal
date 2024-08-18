/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gethashval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:42:43 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/18 20:05:04 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/commondata.h"
#include "../hdrs/hashtable.h"
#include "../../../libft/libft.h"
#include <stdint.h>
#include <stdlib.h>

int	gethash(f_hash fhash, const char *str, int tabsize, uint32_t seed)
{
	if (!str || !(*str))
		return (E_KO);
	return (fhash(str, ft_strlen(str), seed) % tabsize);
}

int	getstephash(f_hash fhash, const char *str, int tabsize, uint32_t seed)
{
	if (!str || !(*str))
		return (E_KO);
	return (fhash(str, ft_strlen(str), seed) % (tabsize - 1));
}
