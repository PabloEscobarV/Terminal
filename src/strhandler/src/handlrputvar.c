/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlrputvar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:13:57 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/29 15:27:13 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../HashTable/hdrs/hashtable.h"
#include "../hdrs/strhandlerserv.h"
#include "../../../libft/libft.h"
#include "../../../hdrs/commondata.h"
#include <stdio.h>

static int	check_key(const char *var)
{
	if (ft_isdigit(*var))
		return (E_KO);
	while (ft_isalnum(*var) && *var != VARSIGNE)
		++var;
	if (*var != VARSIGNE)
		return (E_KO);
	return (E_OK);
}

static char	*variablevalue(const char *data)
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

static const char	*skip_spaces(const char *str)
{
	while (*str && ft_isspace(*str))
		++str;
	return (str);
}

const char	*handlvariable(const char *str, t_hashtable *hst)
{
	const char	*tmp;
	char		*var;

	tmp = str;
	while (*tmp && *tmp != VARSIGNE)
		++tmp;
	if (check_key(str))
		return (str);
	var = ft_strldup(str, tmp - str);
	str = tmp + 1;
	tmp = variablevalue(tmp + 1);
	str += ft_strlen(tmp);
	if (*str)
	{
		str = skip_spaces(str);
		printf("minishell: %s: command not found...\n", str);
		return (NULL);
	}
	hst->add(hst, var, tmp);
	free(var);
	free((void *)tmp);
	return (str);
}