/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhanler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:40:24 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/22 15:27:56 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

char	isqtssv(t_cchar *str, t_cchar *qts)
{
	t_cchar	*tmp;

	while (*qts && *str != *qts)
		++qts;
	return (*qts);
}

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

static t_uchar	checkvarch(t_cchar *str, t_cchar var)
{
	if (*str != var)
		return (0);
	if (*(str - 1) == ESCCH)
		return (0);
	if (*(str + 1) == SPCCH || *(str + 1) == ESCCH)
		return (0);
	return (1);
}

static t_llist	*strsizeexc(t_cchar *args, t_cchar end, t_hash *hst)
{
	int		size;
	t_llist	*llst;

	llst = NULL;
	size = 0;
	while (*args && !(*args == end && *(args - 1) != ESCCH))
	{
		if (checkvarch(args, VARCH))
		{
			size += ft_strlen((char *)(llistadd_back(&llst,
				llistnewnode((void *)hst->hash(args, hst->hashtb)))));
			while (*args && *args != SPCCH && *args != end)
				++args;
			continue ;
		}
		if (*args != ESCCH)
			++size;
		++args;
	}
	if (!(*args))
		return (llistclear(&llst, free));
	llst = llistadd_front(&llst, llistnewnode(crtintdt(size)));
	return (llst);
}

static int	setresstr(char	*res, t_cchar *args, t_cchar end, t_llist *llst)
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
	res[i] = '\0';
	return ((int)(args - tmp));
}

char	*dqtshandler(t_cchar *str, t_crd *crd, t_cchar end, t_hash *hst)
{
	char		*res;
	t_llist		*llst;;

	llst = strsizeexc(str, end, hst);
	if (!llst)
	{
		crd->size = -1;
		return (ft_perror("ERROR in string handler"));
	}
	res = malloc((*((int *)llst->data) + 1) * sizeof(char));
	if (!res)
		return (ft_perror(MALLOCERROR));
	crd->i += setresstr(res, str, end, llst->next);
	// free(llst->data);
	llistclear(&llst, free);
	return (res);
}

char	*sqtshadler(t_cchar *args, t_crd *crd, t_cchar end)
{
	char	*res;

	res = (char *)args;
	while (*res && *res != end)
		++res;
	if (!(*res))
	{
		crd->size = -1;
		return (ft_perror("ERROR!!! Is not end single quote"));
	}
	crd->size = res - args;
	res = malloc((crd->size + 1) * sizeof(char));
	if (!res)
		return(ft_perror("ALLOC ERROR!!! in sqtshandler"));
	crd->i += crd->size;
	res[crd->size] = '\0';
	while (crd->size)
	{
		--crd->size;
		res[crd->size] = args[crd->size];
	}
	return (res);
}

char    *strhandler(t_cchar *args, t_crd *crd, t_cchar *qts, t_hash *hst)
{
	char		end;

	args + crd->i;
	end = isqtssv(args, qts);
	if (!end)
		return (NULL);
	++args;
	crd->i += 2;
	if (end == QTS[I_DQTS])
		return (dqtshandler(args, crd, end, hst));
	return (sqtshadler(args, crd, end));
}

t_cchar	*hash(t_cchar *key, char **hashtb)
{
	return (ft_strdup("ABC"));
}

int	main()
{
	t_hash		hst;
	t_cchar		*args;
	t_crd		crd;
	t_cchar		qts[] = "\"\'";
	char		*res;

	hst.hash = hash;
	hst.hashtb = NULL;
	crd.i = 0;
	args = ft_strdup("\"data from str. $ \\$var $var1 \\\"$vvar into $ \\$ $var\\\" into file: $var ; echo data \\\"DATA\\\" $var after var\' >> file.txt");
	res = strhandler(args, &crd, qts, &hst);
	if (!res)
		printf("ERROR!!!\n");
	else
	{
		printf("|%s|\n", res);
		printf("finded size:\t%d\n", ft_strlen(res));
		printf("size for input string:\t%d\tcrd->i:\t%d\t|%s|\n", ft_strlen(args), crd.i, args + crd.i);
	}
	// printf("real size:\t%d\n", ft_strlen(res));
	free(res);
	free((void *)args);
	return (0);
}
// echo \"data \\\"DATA\\\" $var after var\" >> file.txt
// data from str. $ \\$var $var1 \\\"$vvar into $ \\$ $var\\\" into file: $var 

// char    *strhandler(t_indata *indt, t_crd *crd, t_cchar end, f_hash hashf)
// {
// 	char    	*res;
// 	t_llist		*llst;

// 	if (!(*(indt->args + crd->i)) || !(*(indt->args + crd->i + 1)))
// 		return (ft_strdup(indt->args + crd->i));
// 	llst = strsizeexc(indt->args + crd->i, indt->hashtb, end, hashf);
// 	res = malloc((*((int *)llst->data) + 1) * sizeof(char));
// 	if (!res)
// 		return (ft_perror(MALLOCERROR));
// 	crd->i += setresstr(res, indt->args + crd->i, end, llst->next);
// 	// free(llst->data);
// 	llistclear(&llst, free);
// 	return (res);
// }