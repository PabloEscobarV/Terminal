/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:54:29 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/01 16:06:19 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../../../libft/libft.h"
#include "../../../hdrs/commondata.h"

int	getoperation(t_arg *argt)
{
	int		i;

	if (argt->arg[argt->x] != VARCH)
		return (E_ERR);
	if (argt->x && ft_strchr(argt->arg[argt->x - 1], FESC))
		return (E_ERR);
	i = 0;
	++(argt->x);
	while (argt->arg[argt->x] != SUBSTR[i])
		++i;
	return (i);
}

char	*getvarval(t_cchar *args, int size, t_hash *hst)
{
	char	*varval;

	args = ft_strldup(*args, size);
	varval = hst->hash(args, hst->hashtb);
	free(args);
	return (varval);
}

char	*getvar(t_arg *argt, int size, t_hash *hst)
{
	char	*varval;
	
	if (!size)
		return (NULL);
	*varval = getvarval(argt->arg, size, hst);
	if (!varval)
	{
		ft_putstr(MALLOCERROR);
		exit(-1);
	}
	return (varval);
}

char	*subbraces(t_arg *argt, t_cchar end, t_hash *hst)
{
	int	size;

	size = argt->x;
	while (argt->arg[size] && argt->arg[size] != end)
		++size;
	if (size == argt->x || !(argt->arg[size]))
		return (ft_perror("Command not found"));
	size -= argt->x;
	argt->x += size;
	return (getvar(argt, size, hst));
}

char	*subpid(t_arg *argt, t_cchar end, t_hash *hst)
{
	if (*(argt->arg + 1) != end)
		return (NULL);
	
}

char	*getvarval(t_arg *argt, t_hash *hst)
{
	int	oper;

	oper = getoperation(argt);
	if (oper == E_ERR)
		return (NULL);
	switch (oper)
	{
	case (I_BRACES):
		break;
	default:
		break;
	}
}


// int	getvarend(t_cchar *args, t_cchar end)
// {
// 	int	size;

// 	size = 0;
// 	while (*args && *args != end)
// 	{
// 		++args;
// 		++size;
// 	}
// 	if (!(*args))
// 		return (0);
// 	return (size);
// }

// int	checkvarend(t_cchar *args)
// {
// 	if (!ft_isprint(*args))
// 		return (E_OK);
// 	if (*args == BKSLASH || *args == SLASH || *args == SPCCH)
// 		return (E_OK);
// 	return (E_KO);
// }

// int	checkvarname(t_cchar *args, int size, t_cchar var)
// {
// 	if (*args != var)
// 		return (E_KO);
// 	if (size && *(args - 1) == BKSLASH)
// 		return (E_KO);
// 	if (checkvarend(++args) == E_OK)
// 		return (E_KO);
// 	return (E_OK);
// }

// char	*braceshndlr(t_arg *argt, t_hash *hst)
// {
// 	return (getvar(argt, getvarend(*args, BRACES[I_RBRACES]), hst));
// }

// char	*pidhndlr(t_cchar **args, t_hash *hst)
// {
// 	if (*((*args) + 1) != VARCH)
// 		return (NULL);
// 	return (getvar(args, ft_strlen(PID), hst));
// }

// char	*varhndlr(t_cchar **args, t_hash *hst)
// {
// 	int		size;

// 	size = 0;
// 	while (checkvarend((*args)[size]))
// 		++size;
// 	return (getvar(args, size, hst));
// }
