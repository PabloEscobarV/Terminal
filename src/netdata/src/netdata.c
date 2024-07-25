/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:02:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/25 13:55:36 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/netdata.h"
#include "../../../libft/libft.h"
#include "../../splitter/hdrs/splitter.h"

#define T_ARG(llst)	((t_arg *)((llst)->data))

t_argv	*setargvt(t_cchar *args, t_splqt *splt, t_llist **llargt)
{
	t_argv	*argvt;

	argvt = crtargvt();
	if (!argvt)
		return (ft_perror("MALLOC ERROR!!!: crtargvt"));
	while (*llargt && cmpsplsav(args + T_ARG(*llargt)->size, splt->splts))
	{
		
		*llargt = (*llargt)->next;
	}
}

t_llist	*nodeargvt(t_cchar *args, t_splqt *splt)
{

}

t_llist	*netdata(t_cchar *args, t_hash *hst)
{
	t_llist	*llargt;
	t_llist	*llargvt;

	llargt = spliter(args,
		crtsplqtt(ft_split(QTS, SPLTCH), ft_split(SPLTS, SPLTCH)), hst);
	if (!llargt)
		return (ft_perror("ERROR in SPLITTER!!!"));

}


