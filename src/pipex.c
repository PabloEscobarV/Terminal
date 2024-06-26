/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:33:14 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/26 13:28:57 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line_bonus.h"
#include "../ft_printf/headers/ft_printf_bonus.h"
#include "../hdrs/pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int	main(int argc, char **argv, char **envp)
{
	char	**splts;

	splts = ft_split(SPLTS, SPLTCH);
	printmatrix(splts);
	// int		i;
	// char	*data;

	// i = 0;
	// while (i < 10)
	// {
	// 	ft_printf("put your data: ");
	// 	data = get_next_line(0);
	// 	printf("data for %d step: %s", i, data);
	// 	free(data);
	// 	++i;
	// }
	// return (0);
}
