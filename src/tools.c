/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:13:57 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/02 15:19:06 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include <stdio.h>
#include <errno.h>

void	*puterror(t_cchar *msg)
{
	perror(msg);
	return (NULL);
}
