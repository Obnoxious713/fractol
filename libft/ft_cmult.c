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

#include "libft.h"

t_complex		ft_cmult(t_complex x, t_complex y)
{
	t_complex	result;

	result.real = (x.real * y.real) - (x.imag * y.imag);
	result.imag = (x.real * y.imag) + (x.imag * y.imag);
	return (result);
}
