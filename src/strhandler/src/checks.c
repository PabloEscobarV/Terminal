/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:17:17 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/04 17:17:53 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/strhandler.h"
#include "../../../libft/libft.h"

int	checkvarend(char args)
{
	if (ft_isalnum(args) || ft_strchr(VARSYM, args))
		return (E_OK);
	return (E_KO);
}

int	checkvarfront(char args)
{
	if (ft_isalpha(args) || ft_strchr(VARSYM, args))
		return (E_OK);
	return (E_KO);
}
