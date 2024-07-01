/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:03:51 by polenyc           #+#    #+#             */
/*   Updated: 2024/07/01 16:00:40 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitterlcl.h"
#include <stdio.h>

void	printllist(void *data)
{
	printf("[0]: %d\t[1]: %d\t|%s|\n", ((t_arg *)(data))->x,
		((t_arg *)(data))->size, ((t_arg *)(data))->arg);
}

void	printmatrix(t_cchar **matrix)
{
	while (*matrix)
	{
		printf("%s\n", *matrix);
		++matrix;
	}
}
