/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_argv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:12:13 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/29 16:04:38 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"
#include <stdlib.h>

t_argv	*crtargvt()
{
	t_argv	*argv;

	argv = malloc(sizeof(t_argv));
	if (!argv)
		return (NULL);
	argv->oper = 0;
	argv->appnd = 0;
	argv->envp = NULL;
	argv->argv = NULL;
	argv->infile = NULL;
	argv->outfile = NULL;
	argv->path = NULL;
	argv->argll = NULL;
	return (argv);
}

void	freeargvt(void *data)
{
	t_argv *argv;

	argv = (t_argv *)data;
	llistclear(&(argv->argll), free);
	// ft_free_d((void **)argv->argv);
	ft_free_d((void **)argv->envp);
	free(argv->argv);
	free(argv->infile);
	free(argv->outfile);
	free((void *)argv->path);
	free(argv);
}

void	*delargvt(t_argv *argv)
{
	ft_free_d((void **)argv->argv);
	ft_free_d((void **)argv->envp);
	free(argv->infile);
	free(argv->outfile);
	free((void *)argv->path);
	free(argv);
	return (argv);
}
