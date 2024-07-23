/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhnddrdqt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:12:57 by polenyc           #+#    #+#             */
/*   Updated: 2024/07/23 15:36:49 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../../../libft/libft.h"

#define T_INT(llist) (*((int *)((llist)->data)))

static int	*crtintdt(int x)
{
	int	*res;

	res = malloc(sizeof(int));
	if (!res)
		return (ft_perror(MALLOCERROR));
	*res = x;
	return (res);
}

static t_uchar	checkvarch(t_cchar *str, t_cchar var)
{
	if (*str != var)
		return (0);
	if (*(str - 1) == ESCCH)
		return (0);
	if (*(str + 1) == SPCCH || *(str + 1) == ESCCH)
		return (0);
	if (!ft_isprint(*(str + 1)))
		return (0);
	return (1);
}

static t_llist	*strsizeexc(t_cchar *args, t_cchar *end, t_hash *hst)
{
	t_cchar	*tmp;
	t_llist	*llst;

	llst = llistnewnode((void *)crtintdt(0));
	tmp = args;
	while (*args && !(ft_strlcmp(args, end) && *(args - 1) != ESCCH))
	{
		if (checkvarch(args, VARCH))
		{
			T_INT(llst) += ft_strlen((char *)(llistadd_back(&llst,
				llistnewnode((void *)hst->hash(args, hst->hashtb))))->data);
			while (*args && *args != SPCCH && !ft_strlcmp(args, end))
				++args;
			continue ;
		}
		if (*args != ESCCH)
			++T_INT(llst);
		++args;
	}
	if (!(*args))
		llistclear(&llst, free);
	llistinsert(llst, llistnewnode((void *)crtintdt(args - tmp)));
	return (llst);
}

static t_cchar	*setresstr(char *res, t_cchar *args, t_cchar *end, t_llist *llst)
{
	int		i;

	i = 0;
    while (args < end)
    {
		if (llst && checkvarch(args, VARCH))
		{
			i = ft_strcpy(res + i, (t_cchar *)llst->data) - res; 
			while (*args && *args != SPCCH && args < end)
				++args;
			llst = llst->next;
			continue ;
		}
		if (*args != ESCCH)
		{
			res[i] = *args;
			++i;
		}
		++args;
    }
	res[i] = '\0';
}

char	*dqtshandler(t_cchar **args, t_cchar *end, t_hash *hst)
{
	char		*res;
	t_llist		*llst;

	llst = strsizeexc(*args, end, hst);
	if (!llst)
		return (ft_perror("ERROR in string handler"));
	res = malloc((T_INT(llst) + 1) * sizeof(char));
	if (!res)
		return (ft_perror(MALLOCERROR));
	*args = setresstr(res, *args, *args + T_INT(llst->next), llst->next->next);
	llistclear(&llst, free);
	return (res);
}
