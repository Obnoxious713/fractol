/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:06:18 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/28 17:06:19 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

t_complex			ft_create_complex(double real, double imag)
{
	t_complex		ret;

	ret.real = real;
	ret.imag = imag;
	ret.polar = atan(imag / real);
	ret.r = sqrt(ret.real * ret.real + ret.imag * ret.imag);
	return (ret);
}
