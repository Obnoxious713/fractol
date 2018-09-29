/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_complex_polar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 16:54:16 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/28 16:54:17 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

t_complex			ft_create_complex_polar(double r, double angle)
{
	t_complex		ret;

	ret.r = r;
	ret.polar = angle;
	ret.real = r * cos(angle);
	ret.imag = r * sin(angle);
	return (ret);
}
