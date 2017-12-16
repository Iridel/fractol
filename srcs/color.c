/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:46:25 by dhill             #+#    #+#             */
/*   Updated: 2017/12/10 20:42:10 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	greyscale(t_ini *var)
{
	if (!var->inside && var->n >= 1 && var->n <= 5)
		put_to_img(var, var->x, var->y, GREY5);
	if (!var->inside && var->n >= 6 && var->n <= 10)
		put_to_img(var, var->x, var->y, GREY4);
	if (!var->inside && var->n >= 11 && var->n <= 15)
		put_to_img(var, var->x, var->y, GREY3);
	if (!var->inside && var->n >= 16 && var->n <= 20)
		put_to_img(var, var->x, var->y, GREY2);
	if (!var->inside && var->n >= 21 && var->n <= 25)
		put_to_img(var, var->x, var->y, GREY1);
	if (!var->inside && var->n >= 26 && var->n <= 30)
		put_to_img(var, var->x, var->y, GREY0);
}

void	muted(t_ini *var)
{
	if (!var->inside && var->n >= 1 && var->n <= 5)
		put_to_img(var, var->x, var->y, MUTED0);
	if (!var->inside && var->n >= 6 && var->n <= 10)
		put_to_img(var, var->x, var->y, MUTED1);
	if (!var->inside && var->n >= 11 && var->n <= 15)
		put_to_img(var, var->x, var->y, MUTED2);
	if (!var->inside && var->n >= 16 && var->n <= 20)
		put_to_img(var, var->x, var->y, MUTED3);
	if (!var->inside && var->n >= 21 && var->n <= 25)
		put_to_img(var, var->x, var->y, MUTED4);
	if (!var->inside && var->n >= 26 && var->n <= 30)
		put_to_img(var, var->x, var->y, MUTED5);
}

void	ice(t_ini *var)
{
	if (!var->inside && var->n >= 1 && var->n <= 5)
		put_to_img(var, var->x, var->y, ICE_5);
	if (!var->inside && var->n >= 6 && var->n <= 10)
		put_to_img(var, var->x, var->y, ICE_4);
	if (!var->inside && var->n >= 11 && var->n <= 15)
		put_to_img(var, var->x, var->y, ICE_3);
	if (!var->inside && var->n >= 16 && var->n <= 20)
		put_to_img(var, var->x, var->y, ICE_2);
	if (!var->inside && var->n >= 21 && var->n <= 25)
		put_to_img(var, var->x, var->y, ICE_1);
	if (!var->inside && var->n >= 26 && var->n <= 30)
		put_to_img(var, var->x, var->y, ICE_0);
}

void	spring(t_ini *var)
{
	if (!var->inside && var->n >= 1 && var->n <= 5)
		put_to_img(var, var->x, var->y, SPRN_Y);
	if (!var->inside && var->n >= 6 && var->n <= 10)
		put_to_img(var, var->x, var->y, SPRN_G);
	if (!var->inside && var->n >= 11 && var->n <= 15)
		put_to_img(var, var->x, var->y, SPRN_B);
	if (!var->inside && var->n >= 16 && var->n <= 20)
		put_to_img(var, var->x, var->y, SPRN_P);
	if (!var->inside && var->n >= 21 && var->n <= 25)
		put_to_img(var, var->x, var->y, SPRN_PI);
	if (!var->inside && var->n >= 26 && var->n <= 30)
		put_to_img(var, var->x, var->y, SPRN_R);
}

void	other(t_ini *var)
{
	if (!var->inside && var->n >= 1 && var->n <= 5)
		put_to_img(var, var->x, var->y, OTHR_N);
	if (!var->inside && var->n >= 6 && var->n <= 10)
		put_to_img(var, var->x, var->y, OTHR_B);
	if (!var->inside && var->n >= 11 && var->n <= 15)
		put_to_img(var, var->x, var->y, OTHR_T);
	if (!var->inside && var->n >= 16 && var->n <= 20)
		put_to_img(var, var->x, var->y, OTHR_Y);
	if (!var->inside && var->n >= 21 && var->n <= 25)
		put_to_img(var, var->x, var->y, OTHR_O);
	if (!var->inside && var->n >= 26 && var->n <= 30)
		put_to_img(var, var->x, var->y, OTHR_P);
}
