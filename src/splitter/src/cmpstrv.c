/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmpstrv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:24:52 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/30 15:16:32 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"

t_cchar	*cmpstrv(t_cchar *str, t_cchar **splt)
{
	while (*splt && !ft_strlcmp(str, (t_cchar *)*splt))
		++splt;
	return (*splt);
}
