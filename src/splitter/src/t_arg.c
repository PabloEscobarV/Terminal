/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:11:24 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/01 17:11:25 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitterlcl.h"

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
