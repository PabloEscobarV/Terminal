/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:10:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/21 22:20:11 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define PATH			"PATH="
#define DERPATHCHAR		':'
#define REDIRIN			"<"
#define REDIROUT		">"
#define REDIROUTAPP		">>"
#define HERDOC			"<<"

enum
{
	INREDIR,
	OUTREDIR,
	APPOUTREDIR,
	HEREDOC,
};

typedef unsigned char	t_uchar;

typedef struct	s_args
{
	t_uchar	redir;
	char	*path;
	char	**argv;
	char	**envp;
}				t_args;

typedef struct	s_splt
{
	int			sizesplt;
	const char	*args;
	const char	*args_s;
	const char	*args_f;
	const char	**splt;
	int			*lens;
}				t_splt;


char	*getfilepath(char **envp, const char *filename);
///////////////////////////////BIT`s OPERATIONS///////////////////////////////
void	setbit(t_uchar *data, t_uchar bit);
void	resetbit(t_uchar *data, t_uchar bit);
t_uchar	getbit(t_uchar data, t_uchar bit);
///////////////////////////////CRT T_ARG///////////////////////////////
t_args	*allocargs(const char *path, const char **argv, const char **envp);
t_args	crtargs(const char *path, const char **argv, const char **envp);

