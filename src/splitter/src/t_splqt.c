/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_splqt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:02:06 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/25 14:25:26 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"

t_splqt	*crtsplqtt(t_cchar **qts, t_cchar **splts, t_cchar **spln)
{
	t_splqt	*splqt;

	if (!qts || !splts || !spln)
		return (NULL);
	splqt = malloc(sizeof(t_splqt));
	if (!splqt)
		return (NULL);
	splqt->qts = qts;
	splqt->splts = splts;
	splqt->spln = spln;
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