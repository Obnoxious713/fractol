/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:19:35 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/27 14:19:36 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

t_complex		ft_cmult(t_complex x, t_complex y)
{
	return (ft_create_complex(x.real * y.real - x.imag * y.imag,
								x.real * y.imag + x.imag * y.real));
}
