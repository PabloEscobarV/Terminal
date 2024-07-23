/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:42:04 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/23 13:10:12 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"

int		checkendtxt(t_cchar *args, t_cchar	***qrs)
{
	int	tmp;

	while (*qrs)
	{
		tmp = cmpstrv(args, *qrs);
		if (tmp)
			return (tmp);
		++qrs;
	}
	return (-1);
}

static int	sizerdr(t_cchar *args, t_cchar	***qrs)
{
	t_cchar	*tmp;

	tmp = args;
	while (*tmp && *tmp != SPCCH && *tmp != ESCCH && !checkendtxt(tmp, qrs))
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
	if (!argvt->outfile || !argvt->infile)
		crd->size = -1;
}

char	*rdrhandler(t_cchar *args, t_crd *crd, t_sqr *sqr, t_argv *argvt)
{
	int		key;

	args += crd->i;
	key = findrdr(args, crd, sqr->rdr);
	if (key >= IOSIZE)
		return (NULL);
	args += crd->size;
	crd->i += crd->size;
	crd->size = sizerdr(args, sqr->qrs);
	crd->i += crd->size;
	f_options(args, crd, key, argvt);
	return (argvt);
}
