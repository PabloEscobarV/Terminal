/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crthashatable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:26:02 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/18 18:34:48 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/commondata.h"
#include "../../../libft/libft.h"
#include "../hdrs/hashtable.h"
#include <stdlib.h>

t_hashnode	*crthashtable(int size)
{
	t_hashnode	*hashtable;

	hashtable = malloc(size * sizeof(t_hashnode));
	if (!hashtable)
	{
		ft_perror(MALLOCERROR);
		exit(-1);
	}
	return (hashtable);
}