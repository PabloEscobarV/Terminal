/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:58:57 by polenyc           #+#    #+#             */
/*   Updated: 2024/06/27 15:53:00 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static char	checkqtssplt(t_llist *llst, const char *args, const char **spltqts)
{
	int	x;

	if (!llst->previous)
		return (-1);
	if (!((t_arg *)(llst->data))->x)
		return (0);
	if (!llst->previous->next)
		x = 0;
	else
		x = ((t_arg *)(llst->previous->data))->size + 1;
	while (!ft_strlcmp(args + x, *spltqts))
		++spltqts;
	printf("%s\n", args + ((t_arg *)(llst->data))->size + ((t_arg *)(llst->data))->x);
	if (ft_strlcmp(args + ((t_arg *)(llst->data))->size
		+ ((t_arg *)(llst->data))->x, *spltqts))
		return (1);
	return (-1);
}

t_llist	*ft_spltqts(const char *args, const char **spltqts)
{
	t_llist	*llst;
	t_llist	*tmp;

	llst = ft_splits(args, spltqts);
	if (!llst)
		return (NULL);
	llistiter(llst, printllist);
	tmp = llst;
	while (tmp)
	{
		if (checkqtssplt(tmp, args, spltqts) < 0)
			return (llistclear(&llst, freeargt));
		tmp = tmp->next;
	}
	return (llst);
}

t_llist	*spliter(const char *args, t_splts *splts)
{
	t_llist	*llst;

	llst = ft_spltqts(args, (const char **)(splts->spltqts));
	if (!llst)
		return (NULL);
	return (llst);
}

// int	main()
// {
// 	t_splts	*splts;
// 	t_llist	*llst;

// 	splts = crtspltst();
// 	printmatrix(splts->spltqts);
// 	// printmatrix(splts->splts);
// 	llst = spliter("\"datat double | quotes || $$ << >> < >\" 'data single || quotes'",
// 		splts);
// 	llistiter(llst, printllist);
// 	return (0);
// }

int main()
{
    t_llist *llst;
    char    ***splt;

    splt = crtspltrs("\"0'\0||0$$0|0$0", SPLTCH, 2);
    printmatrix(splt[0]);
	printmatrix(splt[1]);
	llst = ft_splits("|||a||b|c$$v||||", (t_cchar ***)splt);
    llistiter(llst, printllist);
	ft_free_d((void **)splt);
	llistclear(&llst, freeargt);
    return (0);
}