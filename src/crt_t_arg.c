/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crt_t_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:38:16 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/20 14:55:55 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include "../libft/libft.h"
#include <stdlib.h>

t_args    *allocargs(const char *path, const char **argv, const char **envp)
{
    t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->redir = 0;
	args->path = ft_strdup(path);
	args->argv = ft_strsdup(argv);
	args->envp = ft_strsdup(envp);
	return (args);
}

t_args	crtargs(const char *path, const char **argv, const char **envp)
{
	t_args	args;

	args.redir = 0;
	args.path = ft_strdup(path);
	args.argv = ft_strsdup(argv);
	args.envp = ft_strsdup(envp);
	return (args);
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
// 	t_args	args;

// 	args = crtargs("path data", (const char **)argv, (const char **)envp);
// 	printf("args->path: %s\n", args.path);
// 	printf("ARGV:\n");
// 	printmatrix(args.argv);
// 	printf("ENVP:\n");
// 	printmatrix(args.envp);

// 	// t_args	*args;

// 	// args = allocargs("path data", (const char **)argv, (const char **)envp);
// 	// printf("args->path: %s\n", args->path);
// 	// printf("ARGV:\n");
// 	// printmatrix(args->argv);
// 	// printf("ENVP:\n");
// 	// printmatrix(args->envp);
// 	return (0);
// }