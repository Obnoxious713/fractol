/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:34:59 by jfleisch          #+#    #+#             */
/*   Updated: 2018/09/28 17:35:00 by jfleisch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTCOMPLEX_H
# define LIBFTCOMPLEX_H

# include "../libft.h"
# include <math.h>
# include <complex.h>

typedef struct		s_complex
{
	long double		real;
	long double		imag;
	long double		r;
	long double		polar;
}					t_complex;

t_complex			ft_create_complex(double real, double imag);
t_complex			ft_recreate_complex(t_complex ret);
t_complex			ft_create_complex_polar(double r, double angle);
t_complex			ft_recreate_complex_polar(t_complex ret);
t_complex			ft_cadd(t_complex x, t_complex y);
t_complex			ft_csub(t_complex x, t_complex y);
t_complex			ft_cmult(t_complex x, t_complex y);
t_complex			ft_cdiv(t_complex x, t_complex y);
t_complex			ft_cpow(t_complex x, double e);

#endif
