/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:02:37 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/30 14:54:01 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"

t_arg	*crtargt(char *str, t_cchar *spliter)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	arg->arg = str;
	arg->spliter = spliter;
	return (arg);
}

void	freeargt(void *data)
{
	free(((t_arg *)data)->arg);
	free(data);
}
