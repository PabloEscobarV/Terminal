/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crtspltst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:26:02 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/02 14:55:14 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../src/splitter/hdrs/splitter.h"
#include <stdlib.h>

void        *freespltrst(t_spltrs *spltrs)
{
	ft_free_d(spltrs->iordr);
	ft_free_d(spltrs->splt);
	freesplqtt(spltrs->splqt);
	free(spltrs);
	spltrs = NULL;
	return (spltrs);
}

t_spltrs	*crtspltst(t_cchar *qts, t_cchar *iordr, t_cchar *splt, t_cchar space)
{
    char		*tmp;
    t_spltrs	*spltrs;

    spltrs = malloc(sizeof(t_spltrs));
    if (!spltrs)
        return (NULL);
	tmp = ft_strjoin(iordr, splt);
    spltrs->splqt = crtsplqtt(ft_split(qts, SPLTCH), ft_split(tmp, SPLTCH),
        space);
	free(tmp);
    spltrs->iordr = ft_split(iordr, SPLTCH);
    spltrs->splt = ft_split(splt, SPLTCH);
	if (!spltrs->splqt || !spltrs->iordr || spltrs->splt)
        return (freespltrst(spltrs));
	return (spltrs);
}
