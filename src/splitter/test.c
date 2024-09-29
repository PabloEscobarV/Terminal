/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:56:40 by blackrider        #+#    #+#             */
/*   Updated: 2024/09/29 20:41:27 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/servicespltr.h"
#include "hdrs/splitter.h"
#include "../../libft/libft.h"
#include "../../get_next_line/get_next_line_bonus.h"
#include "../strhandler/hdrs/strhandler.h"
#include "../../hdrs/commondata.h"
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>

int	main()
{
	char		*str;
	char		*line;
	t_llist		*llst;
	t_splqt		*splqt;
	t_strtosub	tmpt;
	t_hashtable *hashtable;
	
	tmpt.qts = ft_strdup("\"\'");
	tmpt.substr = ft_split(SUBSTR, SPLTCH);
	tmpt.subend = ft_split(SUBEND, SPLTCH);
	splqt = crtsplqtt(QTS, RDR, SPLN, SPLTS);
	hashtable = crthashtable(64);
	printmatrix(splqt->spln);
	while (1)
	{
		line = readline("Pablo Escobar:\t");
		if (!ft_strcmp(line, "exit"))
			break ;
		printf("%s\n", line);
		str = strhandler(line, &tmpt, hashtable);
		llst = spliter(str, splqt);
		llistiter(llst, printllist);
		llistclear(&llst, freeargt);
		free(str);
		free(line);
	}
	freesplqtt(splqt);
	free(tmpt.qts);
	free(line);
	ft_free_d((void **)tmpt.substr);
	ft_free_d((void **)tmpt.subend);
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