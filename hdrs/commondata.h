/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commondata.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:00:59 by polenyc           #+#    #+#             */
/*   Updated: 2024/09/29 16:25:05 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define SPLTCH		' '
#define SLASH		'/'
#define BKSLASH		'\\'
#define VARCH		'$'
#define SPCCH		' '
#define PROCID		"$$"
#define ESCSMBS		"\\$\"\'"
#define MALLOCERROR	"MEMMORY ALLOCATE ERROR!!!"
#define TOKENERROR	"syntax error near unexpected token"
#define HRDOC		"<<"
#define QTS			"\" \'"
#define SPLN		"|| $$ | $"
#define RDR			">> > <"
#define SPLTS		"<< >> || < > | \" \'"

// enum	e_errorcodes
// {
// 	E_ERR = -1,
// 	E_OK,
// 	E_KO,
// 	E_ERROR,
// };

// enum	e_quet
// {
// 	I_DQTS,
// 	I_SQTS,
// 	IQTSSIZE,
// };

// enum	e_rdr
// {
// 	I_APPOFILE,
// 	I_OFILE,
// 	I_IFILE,
// 	IOSIZE,
// };

// enum	e_operations
// {
// 	O_NULL,
// 	O_HRDOC,
// 	O_APPND,
// 	O_OR,
// 	O_IFILE,
// 	O_OFILE,
// 	O_PIPE,
// 	O_DQTS,
// 	O_SQTS,
// 	O_SIZE,
// };

// typedef unsigned char	t_uchar;
// typedef const char		t_cchar;

// typedef struct	s_arg
// {
// 	char	*arg;
// 	int		x;
// 	int		size;
// }				t_arg;

// typedef struct	s_splts
// {
// 	t_cchar	*hrdoc;
// 	t_cchar	**qts;
// 	t_cchar	**spln;
// 	t_cchar	**rdr;
// 	t_cchar	**splts;
// }				t_splqt;

// typedef struct	s_argv
// {
// 	char	oper;
// 	char	appnd;
// 	t_cchar	*path;
// 	t_llist	*argll;
// 	char	*infile;
// 	char	*outfile;
// 	t_cchar	**argv;
// 	t_cchar	**envp;
// }				t_argv;

// ///////////////////////////////T_ARG///////////////////////////////
// void	freeargtonly(void *data);
// void	freeargt(void *data);
// t_arg	*crtargt(char *str, int x, int size);
