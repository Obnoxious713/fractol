/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:20:23 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/27 14:20:24 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex		ft_csub(t_complex x, t_complex y)
{
	t_complex	result;

	result.real = x.real - y.real;
	result.imag = x.imag - y.imag;
	return (result);
}
