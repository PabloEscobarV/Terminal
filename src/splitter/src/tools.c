/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:17:18 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/01 17:17:19 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitterlcl.h"
#include <stdio.h>

void	printllist(void *data)
{
	printf("args:\t|%s|\tsplt:\t%s\n", ((t_arg *)(data))->arg,
		((t_arg *)(data))->spliter);
}

void	printmatrix(t_cchar **matrix)
{
	while (*matrix)
	{
		printf("%s\n", *matrix);
		++matrix;
	}
}
