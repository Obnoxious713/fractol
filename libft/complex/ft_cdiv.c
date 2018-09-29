/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdiv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:20:33 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/27 14:20:34 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

t_complex		ft_cdiv(t_complex x, t_complex y)
{
	return (ft_create_complex_polar(x.r / y.r, x.polar - y.polar));
}
