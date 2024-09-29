/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:36:48 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/29 15:29:05 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hdrs/strhandler.h"
#include "../../libft/libft.h"
#include "../../HashTable/hdrs/hashtable.h"
#include "../../hdrs/commondata.h"

#include <stdio.h>
#include <readline/readline.h>

void	*hash(t_cchar *key, char **hashtb)
{
	return ((void *)ft_strdup("ABC"));
}

int	main()
{
	char		*argt;
	char		*line;
	char		**substr;
	char		**subend;
	t_hashtable	*hst;
	t_strtosub	tmpt;
	
	hst = crthashtable(64);
	tmpt.qts = ft_strdup("\"\'");
	tmpt.substr = ft_split(SUBSTR, SPLTCH);
	tmpt.subend = ft_split(SUBEND, SPLTCH);
	while (1)
	{
		line = readline("Pablo Escobar:\t");
		if (!ft_strcmp(line, "exit"))
			break ;
		printf("%s\n", line);
		argt = strhandler(line, &tmpt, hst);
		printf("|%s|\n", argt);
		free(argt);
		free(line);
	}
	free(line);
	ft_free_d((void **)tmpt.subend);
	ft_free_d((void **)tmpt.substr);
	free(tmpt.qts);
	freehashtablet(hst);
	return (0);
}
