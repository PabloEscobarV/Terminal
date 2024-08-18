/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:45:05 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/18 19:23:41 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <stdlib.h>

#define HASHSEED	0
#define C_REHASH	2

typedef struct s_hashnode t_hashnode;

typedef	uint32_t	(* f_hash)(const char *key, int tabsize, int seed);
typedef int			(* f_addnode)(t_hashnode *, int);
typedef int			(* f_findnode)(t_hashnode *, int);
typedef int			(* f_removenode)(t_hashnode *, int);
typedef	int			(* f_resizehashtab)();
typedef	int			(* f_rehash)();

struct s_hashnode
{
    char    *key;
    char    *data;
    char    state;
};

typedef struct	s_hashtable
{
	int				tabsize;
	int				nodecount;
	int				datacount;
	t_hashnode		**table;
	f_hash			fhash;
	f_addnode		add;
	f_findnode		find;
	f_removenode	remove;
	f_resizehashtab	resize;
	f_rehash		rehash;
}				t_hashtable;

int			gethash(f_hash fhash, const char *str, int tabsize, uint32_t seed);
int			getstephash(f_hash fhash, const char *str, int tabsize, uint32_t seed);
uint32_t	murmur3_32(const char* str, int len, uint32_t hash);
/////////////////////////////////CRT HASHTABLE\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_hashnode	*crthashtable(int size);