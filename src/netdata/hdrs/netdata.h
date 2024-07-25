/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netdata.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:03:44 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/25 13:55:21 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../../libft/libft.h"
#include "../../../hdrs/commondata.h"

///////////////////////////////////////T_ARGV////////////////////////////////////
t_argv	*crtargvt();
void	freeargvt(t_argv *argv);
void	*delargvt(t_argv *argv);
///////////////////////////////////////TOOLS////////////////////////////////////
void	fakefree(void *data);