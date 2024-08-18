/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashfunction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:50:01 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/18 18:42:51 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/commondata.h"
#include "../../../libft/libft.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MURMURSIZE	32
#define C_1			0xcc9e2d51
#define C_2			0x1b873593
#define R_BYTES		15
#define R_HASHFINAL	16	
#define R_HASH		13
#define M			5
#define N			0xe6546b64
#define CEND_1		0x85ebca6b
#define	CEND_2		0xc2b2ae35

uint32_t	handlelastbts(uint32_t hash, const uint32_t *blocks, int len)
{
	uint32_t	data;

	data = 0;
	switch (len & 3)
	{
		case (3):
			data ^= blocks[2] << MURMURSIZE / 2;
		case (2):
			data ^= blocks[1] << MURMURSIZE / 4;
		case (0):
			data ^= blocks[0];
			data *= C_1;
			data = (data << R_BYTES) | (data >> (MURMURSIZE - R_BYTES));
			data *= C_2;
			hash ^= data;
	}
	return (hash);
}

uint32_t setfinalhash(uint32_t hash, int len)
{
	hash ^= len;
    hash ^= hash >> 16;
    hash *= 0x85ebca6b;
    hash ^= hash >> 13;
    hash *= 0xc2b2ae35;
    hash ^= hash >> 16;
	return (hash);
}

uint32_t	murmur3_32(const char *str, int len, uint32_t hash)
{
	int				i;
	uint32_t		data;
	const uint32_t	*blocks;
	
	blocks = (const uint32_t *)str;
	i = len >> 2;
	while (i)
	{
		--i;
		data = *blocks;
		data *= C_1;
		data = (data << R_BYTES) | (data >> (MURMURSIZE - R_BYTES));
		data *= C_2;
		hash ^= data;
		hash = (hash << R_HASH) | (hash >> (MURMURSIZE - R_HASH));
		hash = hash * M + N;
		++blocks;
	}
	hash = handlelastbts(hash, blocks, len);
	return (setfinalhash(hash, len));
}

int	main()
{
	const char str[] = "Ing. Pavlo Olenych";

	printf("Result of hash function:\t%ld\n", murmur3_32(str, sizeof(str), 0) % 101);
	return (0);
}
