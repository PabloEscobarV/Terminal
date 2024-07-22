/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdrhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:42:04 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/22 18:46:56 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"

int		sizerdr(t_cchar *args)
{
	t_cchar	*tmp;

	tmp = args;
	while (*tmp && *tmp != SPCCH && ft_isprint(*tmp))
		++tmp;
	return (tmp - args);
}

int	sedirectoin(t_cchar *args, t_cchar **rdr, t_crd *crd)
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
}

char	*rdrhandler(t_cchar *args, t_crd *crd, t_cchar **rdr, t_argv *argvt)
{
	char	*iordr;

	args += crd->i;
	crd->size = cmpstrv(args, rdr); 
	if (!crd->size)
		return (NULL);
	args += crd->size;
	crd->i += crd->size;
	crd->size = sizerdr(args);
	iordr = ft_strldup(args, crd->size);
	if (!iordr)
		return (ft_perror("MALLOC ERROR!!! In rdrhandler"));
	
	return ();
}