/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setindata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:20:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/25 14:01:01 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void	printllist(void *data)
{
	printf("[0]: %d\t[1]: %d\t|%s|\n", ((t_arg *)(data))->x,
		((t_arg *)(data))->size, ((t_arg *)(data))->arg);
}

void	printmatrix(char **matrix)
{
	while (*matrix)
	{
		printf("%s\n", *matrix);
		++matrix;
	}
}

int main()
{
    t_llist *llst;
    char    **splt;

    splt = ft_split("|||0||0$$0$0 $ 0 $$ 0|0 | 0 || ", '0');
    // printmatrix(splt);
	llst = ft_splits("grep -A2 main.: || wc -l | cd .. $ ls -a $$ sudo", (const char **)splt);
    llistiter(llst, printllist);
	ft_free_d((void **)splt);
	llistclear(&llst, delllst);
    return (0);
}

