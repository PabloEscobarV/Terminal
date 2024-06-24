/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setindata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:20:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/24 12:53:18 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

void	printllist(void *data)
{
	printf("[0]: %d\t[1]: %d\n", ((int *)(data))[0], ((int *)(data))[1]);
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
	char	**argv;

    splt = ft_split("|||0||0|0 | 0 || ", '0');
    // printmatrix(splt);
	argv = ft_splits("objdump -M intel -D a.out | grep -A2 main.: || wc -l", splt);
	printmatrix(argv);
    // llst = setllstdata("grep -A2 || wc -l | cd ..", (const char **)splt);
    // llistiter(llst, printllist);
	ft_free_d(argv);
	ft_free_d(splt);
    return (0);    
}

