/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhanler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:40:24 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/21 17:58:10 by blackrider       ###   ########.fr       */
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

t_uchar	checkvarch(t_cchar *str, t_cchar var)
{
	if (*str != var)
		return (0);
	if (*(str - 1) == ESCCH)
		return (0);
	if (*(str + 1) == SPCCH || *(str + 1) == ESCCH)
		return (0);
	return (1);
}

t_llist	*strsizeexc(t_cchar *args, char **hashtb, t_cchar end, f_hash hashf)
{
	t_cchar	*tmp;
	int		size;
	t_llist	*llst;

	llst = NULL;
	size = 0;
	while (*args && !(*args == end && *(args - 1) != ESCCH))
	{
		if (checkvarch(args, VARCH))
		{
			tmp = hashf(args, hashtb);
			llistadd_back(&llst, llistnewnode((void *)tmp));
			while (*args && *args != SPCCH && *args != end)
				++args;
			size += ft_strlen(tmp);
			continue ;
		}
		if (*args != ESCCH)
			++size;
		++args;
	}
	llst = llistadd_front(&llst, llistnewnode(crtintdt(size)));
	return (llst);
}

int	setresstr(char	*res, t_cchar *args, t_cchar end, t_llist *llst)
{
	int		i;
	t_cchar	*tmp;

	tmp = args;
	i = 0;
    while (*args && !(*args == end && *(args - 1) != ESCCH))
    {
		if (checkvarch(args, VARCH) && llst)
		{
			i = ft_strcpy(res + i, (t_cchar *)llst->data) - res; 
			while (*args && *args != SPCCH && *args != end)
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
	t_indata	tmp;
	char    	*res;
	t_llist		*llst;

	tmp.args = indt->args + crd->i;
	tmp.hashtb = indt->hashtb;
	indt->args += crd->i;
	if (!(*(tmp.args)) || !(*(tmp.args + 1)))
		return (ft_strdup(tmp.args));
	llst = strsizeexc(tmp.args, tmp.hashtb, end, hashf);
	res = malloc((*((int *)llst->data) + 1) * sizeof(char));
	if (!res)
		return (ft_perror(MALLOCERROR));
	printf("finded size:\t%d\n", *(int *)llst->data);
	crd->i += setresstr(res, tmp.args, end, llst->next);
	// free(llst->data);
	llistclear(&llst, free);
	return (res);
}

// t_cchar	*hash(t_cchar *key, char **hashtb)
// {
// 	return (ft_strdup("ABC"));
// }

// int	main()
// {
// 	t_indata	indt;
// 	t_crd		crd;
// 	t_cchar		end = '"';
// 	char		*res;

// 	crd.i = 0;
// 	indt.args = ft_strdup("data from str. $ \\$var $var1 \\\"$vvar into $ \\$ $var\\\" into file: $var ; echo data \\\"DATA\\\" $var after var >> file.txt");
// 	res = strhandler(&indt, &crd, end, hash);
// 	printf("|%s|\n", res);
// 	printf("real size:\t%d\n", ft_strlen(res));
// 	free(res);
// 	free((void *)indt.args);
// 	return (0);
// }
// echo \"data \\\"DATA\\\" $var after var\" >> file.txt
// data from str. $ \\$var $var1 \\\"$vvar into $ \\$ $var\\\" into file: $var 

// int		setsize(t_indata *indt, t_llist **llst, t_cchar end, f_hash hashf)
// {
// 	int		size;
// 	t_cchar	*tmp;

// 	size = 0;
// 	while (*(indt->args) && !(*(indt->args) == end && *(indt->args - 1) != ESCCH))
// 	{
// 		if (checkvarch(indt->args, VARCH))
// 		{
// 			tmp = hashf(indt->args, indt->hashtb);
// 			llistadd_back(llst, llistnewnode((void *)tmp));
// 			while (*(indt->args) && *(indt->args) != SPCCH && *(indt->args) != end)
// 				++indt->args;
// 			size += ft_strlen(tmp);
// 			continue ;
// 		}
// 		if (*(indt->args) != ESCCH)
// 			++size;
// 		++indt->args;
// 	}
// 	return (size);
// }