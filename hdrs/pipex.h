/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:10:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/24 13:00:16 by polenyc          ###   ########.fr       */
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

char	*getfilepath(char **envp, const char *filename);
///////////////////////////////FT_SPLITS///////////////////////////////
char	**ft_splits(const char *str, const char **splt);
///////////////////////////////BIT`s OPERATIONS///////////////////////////////
void	setbit(t_uchar *data, t_uchar bit);
void	resetbit(t_uchar *data, t_uchar bit);
t_uchar	getbit(t_uchar data, t_uchar bit);
///////////////////////////////CRT T_ARG///////////////////////////////
t_args	*allocargs(const char *path, const char **argv, const char **envp);
t_args	crtargs(const char *path, const char **argv, const char **envp);

