/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_splqt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:02:06 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/29 15:29:38 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"

t_splqt	*crtsplqtt(t_cchar **qts, t_cchar **splts, t_cchar spcs)
{
	t_splqt	*splqt;

	splqt = malloc(sizeof(t_splqt));
	if (!splqt)
		return (NULL);
	splqt->qts = qts;
	splqt->splts = splts;
	splqt->spcs = spcs;
	return (splqt);
}

void	*freesplqtt(t_splqt *splqt)
{
	ft_free_d((void **)(splqt->qts));
	ft_free_d((void **)splqt->splts);
	free(splqt);
	splqt = NULL;
	return (splqt);
}
