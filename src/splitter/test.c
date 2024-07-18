/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:56:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/18 19:20:39 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/splitter.h"
#include "../../libft/libft.h"
#include <stdio.h>

// int main(int argc, char **argv)
// {
// 	t_llist *llst;
//     t_splqt	*splqt;

// 	printf("GOT DATA:\n%s\n", argv[1]);
// 	splqt = crtsplqtt((t_cchar **)ft_split("\"0'", SPLTCH),
// 		(t_cchar **)ft_split("||0$$0<<0|0$0<0>", SPLTCH), ' ');
//     // printmatrix(splqt->qts);
// 	// printmatrix(splqt->splts);
// 	llst = spliter(argv[1], splqt);
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("%d\t", i);
// 	// for (int i = 0; i < size; ++i)
// 	// 	printf("%c\t", str[i]);
// 	// printf("\n%s\n", str);
// 	llistiter(llst, printllist);
// 	freesplqtt(splqt);
// 	llistclear(&llst, freeargt);
//     return (0);
// }

int main()
{
	char	str[] =  "echo \"data in \\\"in qoutes\\\" quotes\" >> file.txt";
	t_llist *llst;
    t_splqt	*splqt;

	printf("GOT DATA:\n%s\n", str);
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

// "< file.txt grep 135 | wc -l > file1.txt";