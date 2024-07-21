/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhanler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:40:24 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/21 15:52:02 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

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

int		setsize(t_indata *indt, t_llist **llst, t_cchar end, f_hash hashf)
{
	int		size;
	t_cchar	*tmp;

	size = 0;
	if (*(indt->args) == VARCH  && *(indt->args - 1) != ESCCH)
	{
		tmp = hashf(indt->args, indt->hashtb);
		llistadd_back(llst, llistnewnode((void *)tmp));
		while (*(indt->args) && *(indt->args) != SPCCH)
			++indt->args;
		return (ft_strlen(tmp));
	}
	if (*(indt->args) != ESCCH)
		++size;
	++(indt->args);
	return (size);
}

t_llist	*strsizeexc(t_indata *indt, t_cchar end, f_hash hashf)
{
	t_cchar	*tmp;
	int		size;
	t_llist	*llst;

	size = 0;
	llst = NULL;
	tmp = indt->args;
	while (*(indt->args) && !(*(indt->args) == end && *(indt->args - 1) != ESCCH))
		size += setsize(indt, &llst, end, hashf);
	llst = llistadd_front(&llst, llistnewnode(crtintdt(size)));
	indt->args = tmp;
	return (llst);
}

int	setresstr(char	*res, t_cchar *args, t_cchar end, t_llist *llst)
{
	int		i;
	t_cchar	*tmp;

	tmp = args;
	i = 0;
    while (*args && !(*args == end && *args != ESCCH))
    {
		if (*args == VARCH && llst)
		{
			i = ft_strcpy(res + i, (t_cchar *)llst->data) - res; 
			while (*args && *args != SPCCH)
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
	return ((int)(args - tmp));
}

char    *strhandler(t_indata *indt, t_crd *crd, t_cchar end, f_hash hashf)
{
	t_cchar	*tmp;
	char    *res;
	t_llist	*llst;

	tmp = indt->args;
	indt->args += crd->i;
	llst = strsizeexc(indt, end, hashf);
	res = malloc(*((int *)llst->data) * sizeof(char));
	if (!res)
		return (ft_perror(MALLOCERROR));
	crd->i += setresstr(res, indt->args + crd->i, end, llst->next);
	free(llst->data);
	llistclear(&llst, fakefree);
	indt->args = tmp;
	return (res);
}

t_cchar	*hash(t_cchar *key, char **hashtb)
{
	return (ft_strdup("ABC"));
}

int	main()
{
	t_indata	indt;
	t_crd		crd;
	t_cchar		end = '"';
	char		*res;

	indt.args = ft_strdup("echo\\\"");
	res = strhandler(&indt, &crd, end, hash);
	printf("%s\n", res);
	return (0);
}
// echo \"data \\\"DATA\\\" $var after var\" >> file.txt