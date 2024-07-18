/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crtargt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:38:16 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/18 11:33:28 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

t_argv    *allocargt(const char *path, const char **argv, const char **envp)
{
    t_argv	*args;

	args = malloc(sizeof(t_argv));
	if (!args)
		return (NULL);
	args->oper = 0;
	args->path = ft_strdup(path);
	args->argv = (t_cchar **)ft_strsdup(argv);
	args->envp = (t_cchar **)ft_strsdup(envp);
	return (args);
}

// t_argv	crtargt(const char *path, const char **argv, const char **envp)
// {
// 	t_argv	args;

// 	args.oper = 0;
// 	args.path = ft_strdup(path);
// 	args.argv = ft_strsdup(argv);
// 	args.envp = ft_strsdup(envp);
// 	return (args);
// }

t_argv	*crtargvt(t_cchar *path, t_cchar **argv, t_cchar **envp)
{
    t_argv	*args;

	args = malloc(sizeof(t_argv));
	if (!args)
	{
		perror(ERRORMALLOC);
		return (NULL);
	}
	args->oper = 0;
	args->path = path;
	args->argv = argv;
	args->envp = envp;
	args->infile = NULL;
	args->outfile = NULL;
	return (args);
}

void	freeargvt(void *data)
{
	t_argv *args;

	args = (t_argv *)data;
	free(args->path);
	ft_free_d((void **)args->argv);
	ft_free_d((void **)args->envp);
	free(args);
	args = NULL;
	// return (args);
}

// void	printmatrix(char **matrix)
// {
// 	while (*matrix)
// 	{
// 		printf("%s\n", *matrix);
// 		++matrix;
// 	}
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	t_argv	args;

// 	args = crtargs("path data", (const char **)argv, (const char **)envp);
// 	printf("args->path: %s\n", args.path);
// 	printf("ARGV:\n");
// 	printmatrix(args.argv);
// 	printf("ENVP:\n");
// 	printmatrix(args.envp);

// 	// t_argv	*args;

// 	// args = allocargs("path data", (const char **)argv, (const char **)envp);
// 	// printf("args->path: %s\n", args->path);
// 	// printf("ARGV:\n");
// 	// printmatrix(args->argv);
// 	// printf("ENVP:\n");
// 	// printmatrix(args->envp);
// 	return (0);
// }