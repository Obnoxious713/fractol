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

#include "libft.h"

void			ft_cdiv(t_complex x, t_complex y)
{
	t_complex	result;

	if (y.real != 0 && y.imag != 0)
	{
		result.real = (x.real * y.real + x.imag * y.imag)
						/ (y.imag * y.imag + y.imag * y.imag);
		result.imag = (x.imag * y.real - x.real * y.imag)
						/ (y.real * y.real + y.imag * y.imag);
	}
}
