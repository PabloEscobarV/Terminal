/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:33:14 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/30 14:11:50 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line_bonus.h"
#include "../ft_printf/headers/ft_printf_bonus.h"
#include "../hdrs/pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int	main(int argc, char **argv, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split("ls -l > file1.txt", ' ');
	path = getfilepath(envp, args[0]);
	printf("PATH:\t%s\n", path);
	printmatrix((t_cchar **)args);
	execve(path, args, envp);
	return (0);
}
