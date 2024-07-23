/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhanler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:40:24 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/23 10:43:40 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int		isqtssv(t_cchar *str, t_cchar **qts)
{
	int	i;

	i = 0;
	while (qts[i] && !ft_strlcmp(str, qts[i]))
		++i;
	return (i);
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
	if (!ft_isprint(*(str + 1)))
		return (0);
	return (1);
}

static t_llist	*strsizeexc(t_cchar *args, t_cchar *end, t_hash *hst)
{
	int		size;
	t_llist	*llst;

	llst = NULL;
	size = 0;
	while (*args && !(ft_strlcmp(args, end) && *(args - 1) != ESCCH))
	{
		if (checkvarch(args, VARCH))
		{
			size += ft_strlen((char *)(llistadd_back(&llst,
				llistnewnode((void *)hst->hash(args, hst->hashtb)))));
			while (*args && *args != SPCCH && !ft_strlcmp(args, end))
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

static int	setresstr(char	*res, t_cchar *args, t_cchar *end, t_llist *llst)
{
	int		i;
	t_cchar	*tmp;

	tmp = args;
	i = 0;
    while (*args && !(ft_strlcmp(args, end) && *(args - 1) != ESCCH))
    {
		if (checkvarch(args, VARCH) && llst)
		{
			i = ft_strcpy(res + i, (t_cchar *)llst->data) - res; 
			while (*args && *args != SPCCH && !ft_strlcmp(args, end))
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

char	*dqtshandler(t_cchar *str, t_crd *crd, t_cchar *end, t_hash *hst)
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

char	*sqtshadler(t_cchar *args, t_crd *crd, t_cchar *end)
{
	char	*res;

	res = (char *)args;
	while (*res && !ft_strlcmp(res, end))
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

char    *strhandler(t_cchar *args, t_crd *crd, t_cchar **qts, t_hash *hst)
{
	int		end;

	args + crd->i;
	end = isqtssv(args, qts);
	if (!end)
		return (NULL);
	crd->size = ft_strlen(qts[end]);
	args += crd->size; 
	crd->i += crd->size + 1;
	if (end == I_DQTS)
		return (dqtshandler(args, crd, qts[end], hst));
	return (sqtshadler(args, crd, qts[end]));
}

t_cchar	*hash(t_cchar *key, char **hashtb)
{
	return (ft_strdup("ABC"));
}

void	printmatrix(t_cchar **argv)
{
	while (*argv)
	{
		printf("%s\n", *argv);
		++argv;
	}
}

int	main()
{
	t_hash		hst;
	t_cchar		*args;
	t_crd		crd;
	t_cchar		**qts = (t_cchar **)ft_split("\" \'", ' ');
	char		*res;

	hst.hash = hash;
	hst.hashtb = NULL;
	crd.i = 0;
	args = ft_strdup("echo");
	printmatrix(qts);
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

// \"$\n data from str. $ \\$var $var1 \\\"$vvar into $ \\$ $var\\\" into file: $var ; echo data \\\"DATA\\\" $var after var >> file.txt\"