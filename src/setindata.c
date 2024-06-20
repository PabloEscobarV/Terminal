/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setindata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:20:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/20 14:43:53 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

t_args    *allocargs(const char *path, const char **argv, const char **envp)
{
    t_args	*apparg;

	apparg = malloc(sizeof(t_args));
	if (!apparg)
		return (NULL);
	apparg->path = ft_strdup(path);
	apparg->argv = ft_strsdup(argv);
	apparg->envp = ft_strsdup(envp);
	return (apparg);
}

t_args	crtargs(const char *path, const char **argv, const char **envp)
{
	t_args	args;

	args.path = ft_strdup(path);
	args.argv = ft_strsdup(argv);
	args.envp = ft_strsdup(envp);
	return (args);
}

t_argv	*alloct_argv(t_uchar redir, t_args *args)
{
	t_argv	*targv;

	targv = malloc(sizeof(t_argv));
	if (!targv)
		return (NULL);
	targv->redir = redir;
	targv->args = args;
	return (targv);
}

void	printmatrix(char **matrix)
{
	while (*matrix)
	{
		printf("%s\n", *matrix);
		++matrix;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	args = crtargs("path data", (const char **)argv, (const char **)envp);
	printf("args->path: %s\n", args.path);
	printf("ARGV:\n");
	printmatrix(args.argv);
	printf("ENVP:\n");
	printmatrix(args.envp);

	// t_args	*args;

	// args = allocargs("path data", (const char **)argv, (const char **)envp);
	// printf("args->path: %s\n", args->path);
	// printf("ARGV:\n");
	// printmatrix(args->argv);
	// printf("ENVP:\n");
	// printmatrix(args->envp);
	return (0);
}