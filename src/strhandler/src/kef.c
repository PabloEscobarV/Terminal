/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kef.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:24:15 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/04 17:32:15 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"

float		updatekef(float kef, int diff)
{
	kef += (float)(diff) * LAMDA;
	if (kef < 0)
		return (0.2);
	if (kef < 1.0)
		return (1.0 + kef);
	return (kef);
}

