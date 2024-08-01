/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:54:29 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/07/30 16:59:47 by Pablo Escob      ###   ########.fr       */
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

char	*getvarval(t_cchar *args, int size, t_hash *hst)
{
	char	*varval;

	if (!size)
		return (NULL);
	args = ft_strldup(*args, size);
	varval = hst->hash(args, hst->hashtb);
	free(args);
	return (varval);
}

int	braceshndlr(char **varval, t_cchar **args, t_cchar *braces, t_hash *hst)
{
	int		size;

	if (**args != REPLSCH || *(++(*args)) != braces[I_LBRACES])
		return (E_KO);
	++(*args);
	size = getvarend(*args, braces[I_RBRACES]);
	*varval = getvarval(args, size, hst);
	if (!(*varval))
		return (E_KO);
	*args += size;
	return (E_OK);
}

int		pidhndlr(char **varval, t_cchar **args, t_cchar *pid, t_hash *hst)
{
	int		size;

	if (!ft_strlcmp(*args, pid))
		return (E_KO);
	size = ft_strlen(pid);
	*varval = getvarval(args, size, hst);
	if (!(*varval))
		return (E_KO);
	*args += size;
	return (E_OK);
}

int	checkvarend(t_cchar *args)
{
	if (!ft_isprint(*args))
		return (E_OK);
	if (*args == BKSLASH || *args == SLASH || *args == SPCCH)
		return (E_OK);
	return (E_KO);
}

int	checkvarname(t_cchar *args, t_cchar var)
{
	if (*args != var)
		return (E_KO);
	if (*(args - 1) == BKSLASH)
		return (E_KO);
	if (checkvarend(++args) == E_OK)
		return (E_KO);
	return (E_OK);
}

int		varhndlr(char **varval, t_cchar **args, t_hash *hst)
{

}

int		getfinsize(t_cchar *args, t_strhndlr *strhndl, t_hash *hst)
{

}

char	*strhandler(t_cchar *args, t_strhndlr *strhndl, t_hash *hst)
{

}