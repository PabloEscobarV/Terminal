/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhndlrsqt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:16:06 by polenyc           #+#    #+#             */
/*   Updated: 2024/07/23 15:44:58 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/splitter.h"
#include "../../../libft/libft.h"

char	*sqtshadler(t_cchar **args, t_cchar *end)
{
	int		size;
	char	*res;
	char	*tmp;

	res = (char *)*args;
	while (*res && !ft_strlcmp(res, end))
		++res;
	if (!(*res))
		return (ft_perror("ERROR!!! Is not end single quote"));
	size = res - *args;
	res = malloc((size + 1) * sizeof(char));
	if (!res)
		return(ft_perror("ALLOC ERROR!!! in sqtshandler"));
	tmp = res;
	while (res - tmp < size)
	{
		*res = **args;
		++res;
		++(*args);
	}
	*res = '\0';
	return (tmp);
}
