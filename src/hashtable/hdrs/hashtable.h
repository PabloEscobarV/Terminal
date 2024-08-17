/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:45:05 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/17 19:10:03 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

typedef uint32_t (*t_fhash)(const char*, size_t, uint32_t);

typedef struct  s_hash
{
    t_fhash murmur3;

}