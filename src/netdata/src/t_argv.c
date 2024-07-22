/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_argv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:12:13 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/22 17:38:20 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"
#include <stdlib.h>

t_argv	*crtargvt(t_cchar **envp)
{
	t_argv	*argv;

	argv = malloc(sizeof(t_argv));
	if (!argv)
		return (NULL);
	argv->oper = 0;
	argv->envp = envp;
	argv->argv = NULL;
	argv->infile = NULL;
	argv->outfile = NULL;
	argv->path = NULL;
	argv->str = NULL;
	return (argv);
}

void	freeargvt(t_argv *argv)
{
	ft_free_d(argv->argv);
	ft_free_d(argv->envp);
	free(argv->infile);
	free(argv->outfile);
	free(argv->path);
	free(argv);
}

void	*delargvt(t_argv *argv)
{
	ft_free_d(argv->argv);
	ft_free_d(argv->envp);
	free(argv->infile);
	free(argv->outfile);
	free(argv->path);
	free(argv);
	llistclear(&argv->str, fakefree);
	return (argv);
}
