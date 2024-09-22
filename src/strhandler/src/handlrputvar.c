/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlrputvar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:13:57 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/22 23:56:14 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../HashTable/hdrs/hashtable.h"
#include "../hdrs/strhandlerserv.h"
#include "../../../libft/libft.h"

static int	checkvar(const char *var)
{
	if (ft_isdigit(*var))
		return (E_KO);
	while (*var && *var != VARSIGNE)
	{
		if (!ft_isalnum(*var) || *var != VARSIGNE)
			return (E_KO);
		++var;
	}
	if (*var)
		return (E_KO);
	return (E_OK);
}

static char	*getvarval(const char *data)
{
	int		size;
	char	*var;

	size = 0;
	while (data[size] && !ft_isspace(data[size]))
		++size;
	var = malloc((size + 1) * sizeof(char));
	if (!var)
	{
		ft_putstr(MALLOCERROR);
		exit(-1);
	}
	ft_strncpy(var, data, size);
	return (var);
}

char	*nahdlvariable(const char *str, t_hashtable *hst)
{
	char	*tmp;
	char	*var;

	tmp = str;
	while (*tmp)
	{
		++tmp;
		if (*tmp == VARSIGNE && ft_isalnum(*(tmp + 1)))
			break ;
	}
	if (checkvar(str))
		return (NULL);
	var = ft_strldup(str, tmp - str);
	str = tmp + 1;
	tmp = getvarval(tmp + 1);
	hst->add(hst, var, tmp);
	str += ft_strlen(tmp);
	free(var);
	free(tmp);
	return (str);
}