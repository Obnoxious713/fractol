/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ipow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 13:43:39 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/28 13:43:41 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_ipow(double base, int power)
{
	double 			result;

	if (power < 0)
	{
		base = 1.0 / base;
		power = -power;
	}
	while (power)
	{
		if (power & 1)
			result *= base;
		base *= base;
		power >>= 1;
	}
	return ((int)result);
}
