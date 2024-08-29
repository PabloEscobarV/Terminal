/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primenum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:43:04 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/29 20:43:08 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../ft_pow/hdrs/ft_pow.h"
#include <stdlib.h>
#include <stdio.h>

t_ulong	getnearestprime(t_ulong max)
{
	t_uchar	*sqrprimes;

	sqrprimes = ft_getmarkprimes((t_ulong)ft_sqrt(max) + 1);
	
}