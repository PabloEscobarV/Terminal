/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perrormsg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 23:24:00 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/07/26 23:45:36 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/libft.h"

void	*putsprintf(char *msg, int *ern)
{
	*ern = -1;
	ft_perror(msg);
	free(msg);
	return (NULL);	
}

void	*pmsgsetern(char *msg, int *ern)
{
	*ern = -1;
	ft_perror(msg);
	return (NULL);
}
