/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sqr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:21:57 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/20 15:25:25 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"
#include <stdlib.h>

t_sqr	*crtsqrt(t_cchar **qts, t_cchar **splts, t_cchar **rdr)
{
	t_sqr	*sqr;

	sqr = malloc(sizeof(t_sqr));
	if (!sqr)
		return (NULL);
	sqr->qts = qts;
	sqr->rdr = rdr;
	sqr->splts = splts;
	return (sqr);
}

void	*delsqrt(t_sqr *sqr)
{
	ft_free_d(sqr->qts);
	ft_free_d(sqr->rdr);
	ft_free_d(sqr->splts);
	free(sqr);
	return (NULL);
}

void	freesqrt(t_sqr *sqr)
{
	ft_free_d(sqr->qts);
	ft_free_d(sqr->rdr);
	ft_free_d(sqr->splts);
	free(sqr);
}