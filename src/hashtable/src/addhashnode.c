/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addhashnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:35:44 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/18 20:05:04 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/commondata.h"
#include "../../../libft/libft.h"
#include "../hdrs/hashtable.h"
#include <stdlib.h>

int	addhashnode(t_hashtable *hashtable, const char *key, const char *data)
{
	int	i;
	int	hash;
	int	step;

	if (hashtable->tabsize <= hashtable->nodecount + 1)
		hashtable->resize();
	if (hashtable->nodecount >= hashtable->datacount * C_REHASH)
		hashtable->rehash();
	hash = gethash(hashtable->fhash, key, hashtable->tabsize, HASHSEED);
	step = getstephash(hashtable->fhash, key, hashtable->tabsize, HASHSEED);
	i = 0;
	while (hashtable->table[hash] && hashtable->table[hash]->state)
	{
		if (i < hashtable->tabsize)
		/* code */
	}
	
}