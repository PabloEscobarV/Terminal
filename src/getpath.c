/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:04:18 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/19 16:52:05 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../hdrs/pipex.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	printmatrix(char **matrix)
{
	while (*matrix)
	{
		printf("%s\n", *matrix);
		++matrix;
	}
}

char	**getpath(const char **envp)
{
	size_t	size;
	char	*path;
	char	**paths;

	size = ft_strlen(PATH);
	while (ft_strncmp(*envp, PATH, size))
		++envp;
	path = ft_substr(*envp, size, ft_strlen((char *)*envp));
	paths = ft_split(path, DERPATHCHAR);
	free(path);
	return (paths);
}

char	**crtfullpath(char **path, const char *filename)
{
	char	**tmp;

	if (!path)
		return (NULL);
	tmp = path;
	while (*path)
	{
		*path = ft_strjoinfree(*path, (char *)filename, 0);
		++path;
	}
	return (tmp);
}

char	*getfilepath(char **envp, const char *filename)
{
	char	*filepath;
	char	**tmp;

	if (!envp || !filename)
		return (NULL);
	envp = crtfullpath(getpath((const char **)envp), filename);
	tmp = envp;
	while (access(*envp, F_OK))
		++envp;
	filepath = ft_strdup(*envp);
	ft_free_d((void **)tmp);
	return (filepath);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;

	path = getfilepath(envp, "/cd");
	if (!path)
	{
		printf("ERROR!!!\n");
		return (0);
	}
	printf("%s\n", path);
	// printmatrix(envp);
	// char	**path;

	// path = getpath((const char **)envp);
	// path = crtfullpath(path, "/ls");
	// printmatrix(path);
	free(path);
	return (0);
}
