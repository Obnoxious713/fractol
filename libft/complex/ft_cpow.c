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

#include "libftcomplex.h"

t_complex		ft_cpow(t_complex x, int e)
{
	int			i;
	t_complex	ret;

	i = -1;
	ret = x;
	while (++i < e - 1)
		ret = ft_cmult(ret, x);
	return (ret);
}
