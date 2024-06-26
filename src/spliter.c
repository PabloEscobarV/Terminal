/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:58:57 by polenyc           #+#    #+#             */
/*   Updated: 2024/06/26 14:38:14 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>

static char	checkqtssplt(t_llist *llst, char *args, char **spltqts)
{
	while (*spltqts)
	{
		if (llst->previous && llst->previous->next)
			if (!ft_strlcmp(args + ((t_arg *)(llst->previous->data))->x, spltqts))
				return (0);
		if (ft_strlcmp(args + ((t_arg *)(llst->data))->size, spltqts))
			return (1);
		return (0);
		++spltqts;
	}

}

t_llist	*spltqts(t_llist **llst, const char *args, char **spltqts)
{
	t_llist	*tmp;

	*llst = ft_splits(args, spltqts);
	if (!llst)
		return (NULL);
	tmp = *llst;
	while (tmp)
	{
		if (checkqtssplt(tmp, ))
		tmp = tmp->next;
	}
	
}

t_llist	*spliter(const char *args, t_splts *splts)
{

}