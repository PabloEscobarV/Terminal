/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setindata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:20:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/26 15:42:24 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    t_llist *llst;
    char    **splt;

    splt = ft_split(SPLTQTS, '0');
    printmatrix(splt);
	llst = ft_splits("grep -A2 main.: || wc -l | cd .. $ ls -a $$ sudo \"sudo data\"", (const char **)splt);
    llistiter(llst, printllist);
	ft_free_d((void **)splt);
	llistclear(&llst, freeargt);
    return (0);
}

