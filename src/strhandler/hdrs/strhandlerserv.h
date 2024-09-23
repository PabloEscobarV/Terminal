/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strhandlerserv.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:25:47 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/09/23 21:51:04 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../hdrs/strhandler.h"
#include "../../../HashTable/hdrs/hashtable.h"

#define QTSERRMSG	"Syntax Error: Missing closing single quote (')."
#define VARSIGNE    '='

///////////////////////////////OPERATIONS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
char	*subbraces(t_arg *strt, char *end, t_hashtable *hst);
char	*subexicd(t_arg *strt, t_hashtable *hst);
char	*subvar(t_arg *strt, t_hashtable *hst);
///////////////////////////////REALLOC STR\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
char	*reallocstr(char *args, int size);
///////////////////////////////KEF\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
void	setnewparam(t_arg *argt);
float	updatekef(float kef, int diff);
///////////////////////////////GETVARSTR\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
char	*getvalstr(t_arg *strt, int oper, t_strtosub *strtosub, t_hashtable *hst);
///////////////////////////////GET FUNC\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
t_cchar	*getvarval(char *args, int size, t_hashtable *hst);
t_cchar	*getvar(t_arg *strt, int size, t_hashtable *hst);
int		getoperation(t_arg *strt, char **substr);
///////////////////////////////CHEKS\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
int		checkvarend(char args);
int		checkvarfront(char args);
///////////////////////////////REALLOC\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
char	*reallocstr(char *args, int size);
void	setargt(t_arg *argt, char *str, int x, int size);

const char	*handlvariable(const char *str, t_hashtable *hst);