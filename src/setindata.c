/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setindata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:20:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/23 22:15:10 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static int		*crtdata(int x, int size)
{
	int	*tmp;

	tmp = malloc(2 * sizeof(int));
	*tmp = x;
	tmp[1] = size;
	return (tmp);
}

const char	*ft_strlcmp(const char *str, const char *cmp)
{
	while (*str && (*str == *cmp))
	{
		++str;
		++cmp;
	}
	if (!(*str) || !(*cmp))
		return (str);
	return (NULL);
}

static int		issplt(const char *str, const char **splt)
{
	char	*tmp;

	while (*splt)
	{
		tmp = ft_strlcmp(str, (const char *)*splt);
		if (tmp)
			return (tmp - str);
		++splt;
	}
	return (0);
}

static int		checksplt(const char *str, const char **splt, int strsize)
{
    int tmp;
    int i;

    i = issplt(str, splt);
    if (!i)
        return (0);
    while (i < strsize)
    {
        tmp = issplt(str + i, splt);
        if (!tmp)
            return (i);
        i += tmp;
    }
    return (strsize);
}

static t_llist	*setstrs(const char *str, const char **splt)
{
    int     i;
    int     offset;
    int     strsize;
    t_llist *llst;

    strsize = ft_strlen(str);
    i = checksplt(str, splt, strsize);
    llst = llistnewnode(crtdata(i, 0));
    while (i < strsize)
    {
        offset = checksplt(str + i, splt, strsize);
        if (offset)
        {
            if (llst->previous)
                ((int *)(llst->previous->data))[1] = i + offset;
            else
                ((int *)(llst->data))[1] = i + offset;
            i += offset;
            llistadd_back(&llst, llistnewnode(crtdata(i, 0)));
        }
        ++i;
    }
    return (llst);
}

void	printllist(void *data)
{
	printf("[0]: %d\t[1]: %d\n", ((int *)(data))[0], ((int *)(data))[1]);
}

int main()
{
    t_llist *llst;
    char    **splt;

    splt = ft_split("|||0||0|", '|');
    llst = setstrs("gerp -A2 || wc -l | cd ..", (const char **)splt);
    llistiter(llst, printllist);
    return (0);    
}