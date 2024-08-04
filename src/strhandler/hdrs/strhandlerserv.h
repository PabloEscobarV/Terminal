/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandlerserv.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:25:47 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/04 18:59:39 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../hdrs/strhandler.h"

#define QTSERRMSG	"Syntax Error: Missing closing single quote (')."

///////////////////////////////OPERATIONS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
char	*subbraces(t_arg *strt, char *end, t_hash *hst);
char	*subexicd(t_arg *strt, t_hash *hst);
char	*subvar(t_arg *strt, t_hash *hst);
///////////////////////////////REALLOC STR\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
char	*reallocstr(char *args, int size);
///////////////////////////////KEF\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
void	setnewparam(t_arg *argt);
float	updatekef(float kef, int diff);
///////////////////////////////GETVARSTR\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
char	*getvalstr(t_arg *strt, int oper, t_strtosub *strtosub, t_hash *hst);
///////////////////////////////GET FUNC\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
char	*getvarval(char *args, int size, t_hash *hst);
char	*getvar(t_arg *strt, int size, t_hash *hst);
int		getoperation(t_arg *strt, char **substr);
///////////////////////////////CHEKS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
int		checkvarend(char args);
int		checkvarfront(char args);
///////////////////////////////REALLOC\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
char	*reallocstr(char *args, int size);
void	setargt(t_arg *argt, char *str, int x, int size);