/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recreate_complex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:12:59 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/28 17:13:00 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftcomplex.h"

t_complex			ft_recreate_complex(t_complex ret)
{
	return (ret = ft_create_complex(ret.real, ret.imag));
}
