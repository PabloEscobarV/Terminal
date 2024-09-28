/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:37:09 by blackrider        #+#    #+#             */
/*   Updated: 2024/09/28 21:10:19 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include <stdio.h>

void	fakefree(void *data)
{
	(void *)data;
}

void	printstr(void *data)
{
	char	*str;

	str = (char *)data;
	printf("|%s|\n", str);
}

t_cchar	*skipspaces(t_cchar *args)
{
	while (*args && ft_isspace(*args))
		++args;
	return (args);
}

t_cchar	*cmpargsv(t_cchar *args, t_cchar **strv)
{
	if (!strv)
		return (NULL);
	while (*strv && !ft_strlcmp(args, *strv))
		++strv;
	return (*strv);
}
