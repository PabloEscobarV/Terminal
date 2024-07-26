/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_splqt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:02:06 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/26 14:28:38 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"

t_splqt	*crtsplqtt(char **qts, char **splts, char **spln)
{
	t_splqt	*splqt;

	if (!qts || !splts || !spln)
		return (NULL);
	splqt = malloc(sizeof(t_splqt));
	if (!splqt)
		return (NULL);
	splqt->qts = (t_cchar **)qts;
	splqt->splts = (t_cchar **)splts;
	splqt->spln = (t_cchar **)spln;
	return (splqt);
}

void	*freesplqtt(t_splqt *splqt)
{
	ft_free_d((void **)(splqt->qts));
	ft_free_d((void **)splqt->splts);
	ft_free_d((void **)splqt->spln);
	free(splqt);
	return (NULL);
}

// t_cchar	**crtspln(t_cchar **qts, t_cchar **splts)
// {
// 	t_cchar	**tmp;
// 	t_cchar	**splqt;

// 	splqt = malloc((ft_matsize(qts) + ft_matsize(splts) + 1)
// 		* sizeof(t_cchar *));
// 	if (!splqt)
// 		return (NULL);
// 	tmp = splqt;
// 	while (*splts)
// 	{
// 		*tmp = *splts;
// 		++splts;
// 		++tmp;
// 	}
// 	while (*qts)
// 	{
// 		*tmp = *qts;
// 		++qts;
// 	}
// 	*tmp = NULL;
// 	return (splqt);
// }