/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:10:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/02 15:45:56 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define ERRORMALLOC		"Allocation memmory error!!!\n"
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
#include "../src/splitter/hdrs/splitter.h"

// enum	e_quotes
// {
// 	DBQUETE,
// 	SGQUOTE,
// };

enum	e_spltrs
{
	INRDR,
	OUTRDR,
	PIPE,
	END,
	OR,
	APPND,
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

typedef struct s_splts
{
	char	**iordr;
	char	**splt;
	t_splqt	*splqt;
}				t_spltrs;


typedef struct	s_argv
{
	t_uchar	oper;
	char	*path;
	char	*infile;
	char	*outfile;
	char	**argv;
	char	**envp;
}				t_argv;

char		*getfilepath(char **envp, const char *filename);
///////////////////////////////BIT`s OPERATIONS///////////////////////////////
void		setbit(t_uchar *data, t_uchar bit);
void		resetbit(t_uchar *data, t_uchar bit);
t_uchar		getbit(t_uchar data, t_uchar bit);
///////////////////////////////T_ARGS///////////////////////////////
t_argv		*allocargv(const char *path, const char **argv, const char **envp);
t_argv		crtargv(const char *path, const char **argv, const char **envp);
t_argv		*crtargvt(t_cchar *path, t_cchar **argv, t_cchar **envp);
void		*freeargvt(t_argv *args);
///////////////////////////////T_SPLTRS///////////////////////////////
t_spltrs	*crtspltst(t_cchar space, t_cchar *qts, t_cchar *iordr, t_cchar *splt);
void        *freespltrst(t_spltrs *spltrs);
///////////////////////////////TOOLS///////////////////////////////
void		*puterror(t_cchar *msg);

