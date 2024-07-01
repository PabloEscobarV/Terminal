/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:56:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/01 16:11:47 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/splitter.h"
#include "hdrs/splitterlcl.h"
#include "../../libft/libft.h"

int main()
{
	char	str[] =  "|  greap -A20   |  cd .. ||";
	t_llist *llst;
    t_splqt	*splqt;

	splqt = crtsplqtt((t_cchar **)ft_split("\"0'", SPLTCH),
		(t_cchar **)ft_split("||0$$0>>0<<0|0$0", SPLTCH), ' ');
    printmatrix(splqt->qts);
	printmatrix(splqt->splts);
	llst = spliter(str, splqt);
	// for (int i = 0; i < size; ++i)
	// 	printf("%d\t", i);
	// for (int i = 0; i < size; ++i)
	// 	printf("%c\t", str[i]);
	// printf("\n%s\n", str);
	llistiter(llst, printllist);
	freesplqtt(splqt);
	llistclear(&llst, freeargt);
    return (0);
}