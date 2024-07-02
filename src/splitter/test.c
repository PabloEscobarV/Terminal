/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:56:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/02 14:43:36 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/splitter.h"
#include "../../libft/libft.h"

int main()
{
	char	str[] =  "< file.txt grep 135 | wc -l > file1.txt";
	t_llist *llst;
    t_splqt	*splqt;

	splqt = crtsplqtt((t_cchar **)ft_split("\"0'", SPLTCH),
		(t_cchar **)ft_split("||0$$0<<0|0$0<0>", SPLTCH), ' ');
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