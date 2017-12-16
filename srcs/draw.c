/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:46:24 by dhill             #+#    #+#             */
/*   Updated: 2017/12/14 17:07:47 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_ini *var)
{
	var->z_im = 2 * var->z_re * var->z_im + var->c_im;
	var->z_re = var->z_re2 - var->z_im2 + var->c_re;
	var->n++;
}

void	julia(t_ini *var)
{
	var->z_im = 2 * var->z_re * var->z_im + var->k_im;
	var->z_re = var->z_re2 - var->z_im2 + var->k_re;
	var->n++;
}

void	burningship(t_ini *var)
{
	var->z_im = fabs(2 * var->z_re * var->z_im + var->c_im);
	var->z_re = fabs(var->z_re2 - var->z_im2 + var->c_re);
	var->n++;
}

void	norm_help(t_ini *var)
{
	var->c_re = var->min_re + var->x * var->re_factor;
	var->z_re = var->c_re;
	var->z_im = var->c_im;
	var->inside = 1;
	var->n = 0;
}

void	start(t_ini *var)
{
	var->y = -1;
	while (++var->y < IMG_SZ)
	{
		var->c_im = var->max_im - var->y * var->im_factor;
		var->x = -1;
		while (++var->x < IMG_SZ)
		{
			norm_help(var);
			while (var->n < MAX)
			{
				var->z_re2 = var->z_re * var->z_re;
				var->z_im2 = var->z_im * var->z_im;
				if (var->z_re2 + var->z_im2 > 4)
				{
					var->inside = 0;
					break ;
				}
				(var->fractol[var->f])(var);
			}
			(var->color[var->set])(var);
			if (var->inside || var->n < 1)
				put_to_img(var, var->x, var->y, BLACK);
		}
	}
}
