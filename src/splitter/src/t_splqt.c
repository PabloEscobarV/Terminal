/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_splqt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 19:02:06 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/25 13:31:08 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/servicespltr.h"
#include "../hdrs/splitter.h"

t_cchar	**crtsplqt(t_cchar **qts, t_cchar **splts)
{
	t_cchar	**tmp;
	t_cchar	**splqt;

	splqt = malloc((ft_matsize(qts) + ft_matsize(splts) + 1)
		* sizeof(t_cchar *));
	if (!splqt)
		return (NULL);
	tmp = splqt;
	while (*splts)
	{
		*tmp = *splts;
		++splts;
		++tmp;
	}
	while (*qts)
	{
		*tmp = *qts;
		++qts;
	}
	*tmp = NULL;
	return (splqt);
}

t_splqt	*crtsplqtt(t_cchar **qts, t_cchar **splts)
{
	t_splqt	*splqt;

	if (!qts || !splts)
		return (NULL);
	splqt = malloc(sizeof(t_splqt));
	if (!splqt)
		return (NULL);
	splqt->spltqt = crtsplqt(qts, splts);
	if (!splqt->spltqt)
		return (ft_free(splqt));
	splqt->qts = qts;
	splqt->splts = splts;
	
	return (splqt);
}

void	*freesplqtt(t_splqt *splqt)
{
	ft_free_d((void **)(splqt->qts));
	ft_free_d((void **)splqt->splts);
	free(splqt->spltqt);
	free(splqt);
	return (NULL);
}
