/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhndlrsqt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:16:06 by polenyc           #+#    #+#             */
/*   Updated: 2024/09/29 15:30:42 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"
#include "../../../libft/libft.h"
#include "../../../hdrs/commondata.h"

char	*sqtshadler(t_cchar **args, t_crds *crd, t_cchar *end)
{
	int		size;
	char	*res;
	char	*tmp;

	res = (char *)*args;
	while (*res && !(ft_strlcmp(res, end) && *(res - 1) != BKSLASH))
		++res;
	if (!(*res))
		return (pmsgsetern("ERROR!!! Is not end single quote", &(crd->size)));
	size = res - *args;
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return (pmsgsetern("ALLOC ERROR!!! in sqtshandler", &(crd->size)));	
	tmp = res;
	while (res - tmp < size)
	{
		*res = **args;
		++res;
		++(*args);
	}
	*res = '\0';
	++(*args);
	return (tmp);
}
