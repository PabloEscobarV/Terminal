/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 15:57:46 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/30 15:59:16 by Pablo Escob      ###   ########.fr       */
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

void	setargt(t_arg *argt, char *str, int x, int size)
{
	argt->arg = str;
	argt->x = x;
	argt->size = size;
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