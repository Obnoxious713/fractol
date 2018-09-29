/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recreate_complex_polar.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:13:05 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/28 17:13:05 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

t_complex			ft_recreate_complex_polar(t_complex ret)
{
	return (ret = ft_create_complex_polar(ret.r, ret.polar));
}
