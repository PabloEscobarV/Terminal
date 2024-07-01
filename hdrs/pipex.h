/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:10:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/29 15:30:29 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define PATH			"PATH="
#define DIRSLASH		"/"
#define DERPATHCHAR		':'
#define REDIRIN			"<"
#define REDIROUT		">"
#define REDIROUTAPP		">>"
#define HERDOC			"<<"
#define SPLTCH			'0'
#define SPLTQTS			"\"0'"
#define SPLTS			"$$0||0>>0<<0>0<0|0$"
// #define SPLTS			" $$ 0$$0 || 0||0>>0<<0 | 0 $ 0<0>0|0\"0'0`0\\0*0"

#include "../libft/libft.h"

enum	e_quotes
{
	DBQUETE,
	SGQUOTE,
};

// enum	e_operations
// {
// 	AND,
// 	OR,
// 	APPFILE,
// 	HEREDOC,
// 	INFILE,
// 	OUTFILE,
// 	PIPE,
// 	DQUOTE,
// 	SINGQUOTE,
// 	BACKTICKS,
// 	BACKSLASH,
// 	WCRDALL,
// 	WCRDSNGL,
// };

typedef unsigned char	t_uchar;
typedef const char		t_cchar;

typedef struct	s_args
{
	t_uchar	redir;
	char	*path;
	char	**argv;
	char	**envp;
}				t_args;


char	*getfilepath(char **envp, const char *filename);
///////////////////////////////BIT`s OPERATIONS///////////////////////////////
void	setbit(t_uchar *data, t_uchar bit);
void	resetbit(t_uchar *data, t_uchar bit);
t_uchar	getbit(t_uchar data, t_uchar bit);
///////////////////////////////CRT T_ARGS///////////////////////////////
t_args	*allocargs(const char *path, const char **argv, const char **envp);
t_args	crtargs(const char *path, const char **argv, const char **envp);
///////////////////////////////TOOLS///////////////////////////////
void	printllist(void *data);
void	printmatrix(t_cchar **matrix);

