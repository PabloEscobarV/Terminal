/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:10:54 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/25 13:05:33 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define PATH			"PATH="
#define DERPATHCHAR		':'
#define REDIRIN			"<"
#define REDIROUT		">"
#define REDIROUTAPP		">>"
#define HERDOC			"<<"

#include "../libft/libft.h"

enum
{
	INREDIR,
	OUTREDIR,
	APPOUTREDIR,
	HEREDOC,
};

typedef unsigned char	t_uchar;

typedef struct	s_arg
{
	char	*arg;
	int		x;
	int		size;
}				t_arg;


typedef struct	s_args
{
	t_uchar	redir;
	char	*path;
	char	**argv;
	char	**envp;
}				t_args;

char	*getfilepath(char **envp, const char *filename);
///////////////////////////////FT_SPLITS///////////////////////////////
t_llist	*ft_splits(const char *str, const char **splt);
///////////////////////////////BIT`s OPERATIONS///////////////////////////////
void	setbit(t_uchar *data, t_uchar bit);
void	resetbit(t_uchar *data, t_uchar bit);
t_uchar	getbit(t_uchar data, t_uchar bit);
///////////////////////////////CRT T_ARGS///////////////////////////////
t_args	*allocargs(const char *path, const char **argv, const char **envp);
t_args	crtargs(const char *path, const char **argv, const char **envp);
///////////////////////////////T_ARG///////////////////////////////
t_arg	*crtargt(char *str, int x, int size);
void	delllst(void *data);
