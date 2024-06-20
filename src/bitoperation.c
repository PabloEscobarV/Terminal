/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitoperation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:40:03 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/20 14:26:56 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pipex.h"
#include <stdio.h>

void	setbit(t_uchar *data, t_uchar bit)
{
	*data |= (t_uchar)1 << bit;
}

void	resetbit(t_uchar *data, t_uchar bit)
{
	*data &= ~((t_uchar)1 << bit);
}

t_uchar	getbit(t_uchar data, t_uchar bit)
{
	return ((((t_uchar)1 << bit) & data) >> bit);
}

// void	printbits(t_uchar *data)
// {
// 	for (int i = 0; i < 8; ++i)
// 		printf("%d ", getbit(*data, i));
// 	printf("\n");
// }

// int	main()
// {
// 	t_uchar test = 0;
	
// 	printbits(&test);
// 	printf("START SETING BITS\n");
// 	for (int i = 0; i < 8; ++i)
// 	{
// 		setbit(&test, i);
// 		printbits(&test);
// 	}
// 	printf("START RESETING BITS\n");
// 	printbits(&test);
// 	for (int i = 7; i > -1; --i)
// 	{
// 		resetbit(&test, i);
// 		printbits(&test);
// 	}
// 	return (0);
// }
