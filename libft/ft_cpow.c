/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:19:48 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/27 14:19:49 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex		ft_cpow(t_complex x, double e)
{
	t_complex	result;

	result.real = pow(e, x.real) * cos(x.imag);
	result.imag = pow(e, x.real) * sin(x.imag);
	return (result);
}
