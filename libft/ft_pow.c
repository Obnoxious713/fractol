/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 13:34:36 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/28 13:34:37 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double				ft_pow(double base, int power)
{
	double			ret;

	ret = 1;
	if (power < 0)
	{
		base = 1.0 / base;
		power = -power;
	}
	while (power)
	{
		if (power & 1)
			ret *= base;
		base *= base;
		power >>= 1;
	}
	return (ret);
}
