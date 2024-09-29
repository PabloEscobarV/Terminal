/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:03:51 by polenyc           #+#    #+#             */
/*   Updated: 2024/09/29 15:30:25 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"
#include "../../../hdrs/commondata.h"

int	*crtintdt(int x)
{
	int	*res;

	res = malloc(sizeof(int));
	if (!res)
		return (ft_perror(MALLOCERROR));
	*res = x;
	return (res);
}

int	cmpsav(t_cchar *str, t_cchar **qts)
{
	while (*qts && !ft_strlcmp(str, *qts))
		++qts;
	return (ft_strlen(*qts));
}

int	cmpqts(t_cchar *str, t_cchar **qts)
{
	int	i;

	i = 0;
	while (*qts && !ft_strlcmp(str, *qts))
	{
		++qts;
		++i;
	}
	return (i);
}

// void	fakefree(void *data)
// {

// }

int	cmpstrv(t_cchar *str, t_cchar **splt)
{
	t_cchar	*tmp;

	while (*splt)
	{
		tmp = ft_strlcmp(str, (t_cchar *)*splt);
		if (tmp)
			return (tmp - str);
		++splt;
	}
	return (0);
}

void	*errorf()
{

}