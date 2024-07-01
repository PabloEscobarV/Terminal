/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:03:51 by polenyc           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/06/30 15:11:14 by blackrider       ###   ########.fr       */
=======
/*   Updated: 2024/07/01 16:00:40 by blackrider       ###   ########.fr       */
>>>>>>> 0afb9eb (added make lib instruction, added spliterlcl.h, structs.h)
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
