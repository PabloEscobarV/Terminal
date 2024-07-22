/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpstrv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:10:34 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/22 14:30:21 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"

char	isqtssv(t_cchar *str, t_cchar *qts)
{
	t_cchar	*tmp;

	while (*qts && *str != *qts)
		++qts;
	return (*qts);
}

int	cmpstrv(t_cchar *str, t_cchar **sqr)
{
	t_cchar	*tmp;

	while (*sqr)
	{
		tmp = ft_strlcmp(str, (t_cchar *)*sqr);
		if (tmp)
			return (tmp - str);
		++sqr;
	}
	return (0);
}
