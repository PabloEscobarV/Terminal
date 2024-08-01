/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crtescstrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:24:04 by polenyc           #+#    #+#             */
/*   Updated: 2024/08/01 14:37:38 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../hdrs/commondata.h"
#include "../../../libft/libft.h"
#include "../hdrs/strhandler.h"
#include <stdlib.h>

void	*freeescs(t_subesc *escs)
{
	free(escs->fesc);
	free(escs->resc);
	ft_free_d(escs->substr);
	free(escs);
	return (NULL);
}

t_subesc	*crtescs(char var, t_cchar *fesc, t_cchar *resc, t_cchar **substr)
{
    t_subesc  *escs;

    escs = malloc(sizeof(t_subesc));
    if (!escs)
    {
        ft_putstr(MALLOCERROR);
        exit(-1);
    }
    escs->varch = var;
    escs->fesc = ft_strdup(fesc);
    escs->resc = ft_strdup(resc);
    escs->substr = ft_split(substr, SPLTCH);
    if (!escs->fesc || !escs->resc || !escs->substr)
        return (freeescs(escs));
    return (escs);
}
