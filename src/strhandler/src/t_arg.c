/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:02:37 by blackrider        #+#    #+#             */
/*   Updated: 2024/08/02 15:28:20 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/commondata.h"

t_arg	*crtargt(char *str, int x, int size)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	arg->x = x;
	arg->size = size;
	arg->arg = str;
	return (arg);
}

void	freeargt(void *data)
{
	free(((t_arg *)data)->arg);
	free(data);
}
