/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:58:15 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/01 15:59:32 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef const char	t_cchar;

typedef struct	s_arg
{
	char	*arg;
	int		x;
	int		size;
}				t_arg;

typedef struct	s_splts
{
	char	spcs;
	t_cchar	**qts;
	t_cchar	**splts;
}				t_splqt;

typedef struct	s_crds
{
	int	i;
	int	size;
	int	strsize;
}				t_crds;
