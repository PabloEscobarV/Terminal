// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   strhnddrdqt.c                                      :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/07/23 13:12:57 by polenyc           #+#    #+#             */
// /*   Updated: 2024/07/27 18:21:05 by Pablo Escob      ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../hdrs/servicespltr.h"
// #include "../hdrs/splitter.h"
// #include "../../../libft/libft.h"
// #include "../../../ft_printf/headers/ft_printf_bonus.h"
// #include <unistd.h>

// #define T_INT(llist) (*((int *)((llist)->data)))

// t_uchar	checkvarend(t_cchar *args, t_cchar *end)
// {
// 	if (ft_strlcmp(args, end))
// 		return (E_OK);
// 	if (!ft_isprint(*args))
// 		return (E_OK);
// 	if (*args == BKSLASH || *args == SLASH || *args == VARCH || *args == SPCCH)
// 		return (E_OK);
// 	return (E_KO);
// }

// t_uchar	checkvarname(t_cchar *args, t_cchar *end, t_cchar var)
// {
// 	if (*args != var)
// 		return (E_KO);
// 	if (*(args - 1) == BKSLASH)
// 		return (E_KO);
// 	if (checkvarend(++args, end) == E_OK)
// 		return (E_KO);
// 	return (E_OK);
// }

// t_cchar	*setsize(t_cchar *args, t_cchar *end, t_llist *llst, t_hash *hst)
// {
// 	if (!checkvarname(args, end, VARCH))
// 	{
// 		llistadd_back(&llst, llistnewnode(hst->hash(args, hst->hashtb)));
// 		T_INT(llst) += ft_strlen((t_cchar *)llst->previous->data);
// 		while (checkvarend(++args, end));
// 		return (args);
// 	}
// 	if (*(args - 1) != BKSLASH && ft_strlcmp(args, PROCID))
// 	{
// 		llistadd_back(&llst, llistnewnode(ft_itoa(getpid())));
// 		T_INT(llst) += ft_strlen((t_cchar *)llst->previous->data);
// 		return (args + ft_strlen(PROCID));
// 	}
// 	if (!(*args == BKSLASH && ft_strchr(ESCSMBS, *(args + 1))))
// 		++T_INT(llst);
// 	return (++args);
// }

// t_llist	*getstrlen(t_cchar *args, t_cchar *end, t_hash *hst)
// {
// 	t_cchar	*tmp;
// 	t_llist	*llst;

// 	llst = llistnewnode((void *)crtintdt(0));
// 	tmp = args;
// 	while (!(ft_strlcmp(args, end) && *(args - 1) != BKSLASH))
// 		args = setsize(args, end, llst, hst);
// 	if (!(*args))
// 		return (llistclear(&llst, free));
// 	llistinsert(llst, llistnewnode((void *)crtintdt(args - tmp)));
// 	return (llst);
// }

// char	*setdatares(char *res, t_cchar **args, t_cchar *end, t_llist **llst)
// {
// 	if (*llst && !checkvarname(*args, end, VARCH))
// 	{
// 		res = ft_strcpy(res, (t_cchar *)(*llst)->data); 
// 		while (checkvarend(++(*args), end));
// 		*llst = (*llst)->next;
// 		return (res);
// 	}
// 	if (*((*args) - 1) != BKSLASH && ft_strlcmp(*args, PROCID))
// 	{
// 		res = ft_strcpy(res, (t_cchar *)(*llst)->data);
// 		*llst = (*llst)->next;
// 		*args += ft_strlen(PROCID);
// 		return (res);
// 	}
// 	if (!(**args == BKSLASH && ft_strchr(ESCSMBS, *((*args) + 1))))
// 	{
// 		*res = **args;
// 		++res;
// 	}
// 	++(*args);
// 	return (res);
// }

// t_cchar	*setresstr(char *res, t_cchar *args, t_cchar *end, t_llist *llst)
// {
//     while (args < end)
// 		res = setdatares(res, &args, end, &llst);
// 	*res = '\0';
// 	return (end + 1);
// }

// char	*dqtshandler(t_cchar **args, t_crds *crd, t_cchar *end, t_hash *hst)
// {
// 	char		*res;
// 	t_llist		*llst;

// 	llst = getstrlen(*args, end, hst);
// 	if (!llst)
// 		return (pmsgsetern(MALLOCERROR, &(crd->size)));
// 	res = malloc((T_INT(llst) + 1) * sizeof(char));
// 	if (!res)
// 		return (pmsgsetern(MALLOCERROR, &(crd->size)));
// 	*args = setresstr(res, *args, *args + T_INT(llst->next), llst->next->next);
// 	llistclear(&llst, free);
// 	return (res);
// }
