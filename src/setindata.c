/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setindata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:20:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/01 18:58:03 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../hdrs/pipex.h>
#include "splitter/hdrs/splitter.h"
#include <stdlib.h>
#include <stdio.h>



t_argv	*getargv(t_cchar *args, t_cchar **envp, t_splqt *splqt)
{
	t_llist	*llst;

	llst = spliter(args, splqt);
	if (!llst)
		return (NULL);
}