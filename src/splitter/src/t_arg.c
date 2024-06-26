/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:02:37 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/01 16:00:26 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitterlcl.h"

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
