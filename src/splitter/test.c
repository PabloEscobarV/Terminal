/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:56:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/26 15:05:51 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/servicespltr.h"
#include "hdrs/splitter.h"
#include "../../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include "../../get_next_line/get_next_line_bonus.h"

void	*hash(t_cchar *key, char **hashtb)
{
	return ((void *)ft_strdup("ABC"));
}

int	main()
{
	char	*line;
	t_llist	*llst;
	t_splqt	*splqt;
	t_hash	hst;
	
	hst.hash = hash;
	hst.hashtb = NULL;
	splqt = crtsplqtt(QTS, RDR, SPLN, SPLTS);
	printmatrix(splqt->spln);
	while (1)
	{
		line = readline("Pablo Escobar:\t");
		if (!ft_strcmp(line, "exit"))
			break ;
		printf("%s\n", line);
		llst = spliter(line, splqt, &hst);
		llistiter(llst, printllist);
		llistclear(&llst, freeargt);
	}
	freesplqtt(splqt);
	return (0);
}

// int	main()
// {
// 	char	*line;
// 	t_llist	*llst;
// 	t_splqt	*splqt;
	
// 	splqt = crtsplqtt((t_cchar **)ft_split("\"0'", SPLTCH),
// 		(t_cchar **)ft_split("||0$$0<<0|0$0<0>", SPLTCH), ' ');
// 	while (1)
// 	{
// 		ft_putstr("Pablo Escobar:\t");
// 		line = get_next_line(0);
// 		if (ft_strlcmp(line, "exit"))
// 			break ;
// 		printf("%s", line);
// 		llst = spliter(line, splqt);
// 		llistiter(llst, printllist);
// 		llistclear(&llst, freeargt);
// 	}
// 	freesplqtt(splqt);
// 	return (0);
// }

// void	testescsqs(char *str)
// {
// 	while (*str)
// 	{
// 		// if (*str == '\\')
// 		// 	printf("DAROVA\n");
// 		write(1, str, 1);
// 		++str;
// 	}
// }

// int main(int argc, char **argv)
// {
// 	t_llist *llst;
//     t_splqt	*splqt;

// 	printf("GOT DATA:\n%s\n", argv[1]);
// 	ft_putstr(argv[1]);
// 	ft_putchar('\n');
// 	testescsqs(argv[1]);
// 	ft_putchar('\n');
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

// int main()
// {
// 	char	str[] =  "echo \"data in \\\"in qoutes\\\" quotes\" >> file.txt";
// 	t_llist *llst;
//     t_splqt	*splqt;

// 	printf("GOT DATA:\n%s\n", str);
// 	splqt = crtsplqtt((t_cchar **)ft_split("\"0'", SPLTCH),
// 		(t_cchar **)ft_split("||0$$0<<0|0$0<0>", SPLTCH), ' ');
//     printmatrix(splqt->qts);
// 	printmatrix(splqt->splts);
// 	llst = spliter(str, splqt);
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

// "< file.txt grep 135 | wc -l > file1.txt";