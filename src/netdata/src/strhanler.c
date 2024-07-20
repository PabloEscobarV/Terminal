/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhanler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:40:24 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/20 22:54:49 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"

void	fakefree(void *data)
{

}

int	*crtintdt(int x)
{
	int	*res;

	res = malloc(sizeof(int));
	if (!res)
		return (ft_perror(MALLOCERROR));
	*res = x;
	return (res);
}

t_llist	*strsizeexc(t_indata *indt, t_cchar *str, t_cchar end, f_hash hashf)
{
	int		size;
	t_llist	*llst;
	t_llist	*tmp;

	size = 0;
	llst = NULL;
	while (*str && !(*str == end && *(str - 1) != ESCCH))
	{
		if (*str == VARCH  && *(str - 1) != ESCCH)
		{
			tmp = newnode(hashf(str, indt->hashtb));
			llistadd_back(&llst, tmp);
			size += ft_strlen((t_cchar *)(tmp->data));
		}
		if (*str != ESCCH)
			++size;
		++str;
	}
	llistadd_back(&llst, newnode(crtintdt(size)));
	return (llst);
}

int	setresstr(char	*res, t_cchar *args, t_cchar end, t_llist *llst)
{
	int		i;
	char	*tmp;

	tmp = args;
	i = 0;
    while (*args && !(*args) == end && *args != ESCCH)
    {
		if (*args == VARCH)
		{
			i += (int)(ft_strcpy(res + i, (t_cchar *)llst->data) - res + i);
			continue ;
		}
		if (*args != ESCCH)
			res[i] = *args;
		++args;
		++i;
    }
	return ((int)(args - tmp));
}

char    *strhandler(t_indata *indt, t_crd *crd, t_cchar end, f_hash hashf)
{
	char    *res;
	t_llist	*llst;

	llst = strsizeexc(indt, indt->args + crd->i, end, hashf);
	res = malloc((int *)llst->data);
	if (!res)
		return (ft_perror(MALLOCERROR));
	crd->i += setresstr(res, indt->args + crd->i, end, llst);
	free(llst->previous->data);
	llistclear(&llst, fakefree);
}
