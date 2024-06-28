/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_crds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:14:27 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/28 17:24:19 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"

t_crds	*crdcrdst(int i, int size, int strsize)
{
	t_crds	*crds;

	crds = malloc(sizeof(t_crds));
	if (!crds)
		return (NULL);
	crds->i = i;
	crds->size = size;
	crds->strsize = strsize;
}

void	freecrds(t_crds *crds)
{
	free(crds);
	crds = NULL;
	return (crds);
}
