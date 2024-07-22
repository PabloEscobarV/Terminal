/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:42:04 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/22 20:48:47 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"

static int		sizerdr(t_cchar *args)
{
	t_cchar	*tmp;

	tmp = args;
	while (*tmp && *tmp != SPCCH && ft_isprint(*tmp))
		++tmp;
	return (tmp - args);
}

static int	findrdr(t_cchar *args, t_crd *crd, t_cchar **rdr)
{
	int		i;
	t_cchar	*tmp;

	i = 0;
	while (rdr[i])
	{
		tmp = ft_strlcmp(args, *rdr);
		if (tmp)
		{
			crd->size = tmp - args;
			return (i);
		}
		++i;
	}
	return (i);
}

static void	f_options(t_cchar *args, t_crd	*crd, int key, t_argv *argvt)
{
	switch (key)
	{
	case (I_OFILE):
		argvt->outfile = ft_strldup(args, crd->size);
		break ;
	case (I_IFILE):
		argvt->infile = ft_strldup(args, crd->size);
		break ;
	case (I_APPOFILE):
		argvt->outfile = ft_strldup(args, crd->size);
		argvt->appnd = 1;
		break ;
	}
}

char	*rdrhandler(t_cchar *args, t_crd *crd, t_cchar **rdr, t_argv *argvt)
{
	int		key;

	args += crd->i;
	key = findrdr(args, crd, rdr);
	if (key >= IOSIZE)
		return (NULL);
	args += crd->size;
	crd->i += crd->size;
	crd->size = sizerdr(args);
	f_options(args, crd, key, argvt);

	if (!iordr)
		return (ft_perror("MALLOC ERROR!!! In rdrhandler"));
	
	return ();
}