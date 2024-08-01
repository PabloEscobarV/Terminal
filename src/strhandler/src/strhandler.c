/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:54:29 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/01 13:27:49 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../../../libft/libft.h"
#include "../../../hdrs/commondata.h"

int	getvarend(t_cchar *args, t_cchar end)
{
	int	size;

	size = 0;
	while (*args && *args != end)
	{
		++args;
		++size;
	}
	if (!(*args))
		return (0);
	return (size);
}

int	checkvarend(t_cchar *args)
{
	if (!ft_isprint(*args))
		return (E_OK);
	if (*args == BKSLASH || *args == SLASH || *args == SPCCH)
		return (E_OK);
	return (E_KO);
}

int	checkvarname(t_cchar *args, int size, t_cchar var)
{
	if (*args != var)
		return (E_KO);
	if (size && *(args - 1) == BKSLASH)
		return (E_KO);
	if (checkvarend(++args) == E_OK)
		return (E_KO);
	return (E_OK);
}

char	*getvarval(t_cchar *args, int size, t_hash *hst)
{
	char	*varval;

	args = ft_strldup(*args, size);
	varval = hst->hash(args, hst->hashtb);
	free(args);
	return (varval);
}

char	*getvarvalop(t_cchar **args, int size, t_hash *hst)
{
	char	*varval;
	
	if (!size)
		return (NULL);
	*varval = getvarval(*args, size, hst);
	if (!varval)
	{
		ft_putstr(MALLOCERROR);
		exit(-1);
	}
	*args += size;
	return (varval);
}

char	*braceshndlr(t_cchar **args, t_hash *hst)
{
	if (**args != VARCH || *(++(*args)) != BRACES[I_LBRACES])
		return (NULL);
	++(*args);
	return (getvarvalop(args, getvarend(*args, BRACES[I_RBRACES]), hst));
}

char	*pidhndlr(t_cchar **args, t_hash *hst)
{
	if (**args != VARCH || *(++(*args)) != VARCH)
		return (NULL);
	return (getvarvalop(args, ft_strlen(PID), hst));
}

char	*varhndlr(t_cchar **args, t_hash *hst)
{
	int		size;

	size = 0;
	if (**args != VARCH)
		return (NULL);
	while (checkvarend((*args)[size]))
		++size;
	return (getvarvalop(args, size, hst));
}

char	*checkifvar(t_cchar *args, int size, t_hash *hst)
{
	char	*varval;

	if (checkvarname(args, size, VARCH))
		return (E_OK);
	++args;
	size = pidhndlr(args, hst);
	if (size > 0)
		return ();
}

int		getfinsize(t_cchar *args, t_strhndlr *strhndl, t_hash *hst)
{

}

char	*strhandler(t_cchar *args, t_strhndlr *strhndl, t_hash *hst)
{

}


// }