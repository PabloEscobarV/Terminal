/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:03:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/20 22:00:01 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define ESCCH	'\\'
#define VARCH	'$'

typedef unsigned char	t_uchar;
typedef const char		t_cchar;
typedef t_cchar *(* f_hash)(t_cchar *, t_cchar **);

typedef struct	s_indata
{
	t_cchar	*args;
	char	**hashtb;
}				t_indata;

typedef struct	s_crd
{
	int	i;
	int	size;
	int	strsize;
}				t_crd;

typedef struct	s_sqr
{
	t_cchar	**qts;
	t_cchar	**splts;
	t_cchar	**rdr;
}				t_sqr;

typedef struct	s_argv
{
	char	oper;
	t_cchar	*path;
	char	*str;
	char	*infile;
	char	*outfile;
	t_cchar	**argv;
	t_cchar	**envp;
}				t_argv;

/////////////////////////////////////////T_ARGV/////////////////////////////////
t_argv	*crtargvt(t_cchar **envp);
void	freeargvt(t_argv *argv);
void	*delargvt(t_argv *argv);
/////////////////////////////////////////T_SQR/////////////////////////////////
t_sqr	*crtsqrt(t_cchar **qts, t_cchar **splts, t_cchar **rdr);
void	*delsqrt(t_sqr *sqr);
void	freesqrt(t_sqr *sqr);