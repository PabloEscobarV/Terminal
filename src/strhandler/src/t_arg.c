/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:02:37 by blackrider        #+#    #+#             */
/*   Updated: 2024/09/29 15:28:31 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"

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

void	freeargtonly(void *data)
{
	free(data);
}

void	setargt(t_arg *argt, char *str, int x, int size)
{
	argt->arg = str;
	argt->x = x;
	argt->size = size;
}
