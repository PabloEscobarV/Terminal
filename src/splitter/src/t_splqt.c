/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_splqt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:02:06 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/26 15:03:31 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"

t_splqt	*crtsplqtt(char *qts, char *rdr, char *spln, char *splts)
{
	t_splqt	*splqt;

	if (!qts || !splts || !spln)
		return (NULL);
	splqt = malloc(sizeof(t_splqt));
	if (!splqt)
		return (NULL);
	splqt->hrdoc = HRDOC;
	splqt->qts = (t_cchar **)ft_split(qts, SPLTCH);
	splqt->rdr = (t_cchar **)ft_split(rdr, SPLTCH);
	splqt->spln = (t_cchar **)ft_split(spln, SPLTCH);
	splqt->splts = (t_cchar **)ft_split(splts, SPLTCH);
	return (splqt);
}

void	*freesplqtt(t_splqt *splqt)
{
	ft_free_d((void **)(splqt->qts));
	ft_free_d((void **)splqt->rdr);
	ft_free_d((void **)splqt->spln);
	ft_free_d((void **)splqt->splts);
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