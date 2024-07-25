/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/25 13:26:19 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"

t_llist	*netdata(t_cchar *args, t_hash *hst)
{
	t_llist	*llargt;
	t_llist	*llargvt;

	llargt = spliter(args,
		crtsplqtt(ft_split(QTS, SPLTCH), ft_split(SPLTS, SPLTCH)), hst);
	if (!llargt)
		return (ft_perror("ERROR in SPLITTR!!!"));

}


