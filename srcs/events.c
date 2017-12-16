/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 22:39:37 by dhill             #+#    #+#             */
/*   Updated: 2017/12/14 17:01:33 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_event(int keycode, t_ini *var)
{
	if (keycode == 53)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	if (keycode == 18 && var->f != m)
		var->f = m;
	if (keycode == 19 && var->f != j)
		var->f = j;
	if (keycode == 20 && var->f != b)
		var->f = b;
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		arrow_movement(keycode, var);
	start(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
	return (0);
}

void	arrow_movement(int key, t_ini *var)
{
	if (key == 124)
	{
		var->min_re -= 0.025;
		var->max_re -= 0.025;
		var->max_im = var->min_im + (var->max_re - var->min_re);
	}
	else if (key == 123)
	{
		var->min_re += 0.025;
		var->max_re += 0.025;
		var->max_im = var->min_im + (var->max_re - var->min_re);
	}
	else if (key == 126)
	{
		var->min_im -= 0.025;
		var->max_im = (var->min_im + (var->max_re - var->min_re)) - 0.025;
	}
	else if (key == 125)
	{
		var->min_im += 0.025;
		var->max_im = (var->min_im + (var->max_re - var->min_re)) + 0.025;
	}
	var->re_factor = (var->max_re - var->min_re) / (IMG_SZ - 1);
	var->im_factor = (var->max_im - var->min_im) / (IMG_SZ - 1);
}

int		close_window(t_ini *var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
	return (0);
}

int		mouse_clicks(int keycode, int x, int y, t_ini *var)
{
	if (keycode == 2 && x >= 0 && y >= 0)
		var->set + 1 == 5 ? var->set = 0 : var->set++;
	if (keycode == 5 || keycode == 4)
	{
		if (keycode == 4)
		{
			var->min_re += (var->min_re * ZM);
			var->max_re += (var->max_re * ZM);
			var->min_im += (var->min_im * ZM);
			var->max_im += ((var->min_im + (var->max_re - var->min_re)) * ZM);
		}
		if (keycode == 5)
		{
			var->min_re -= (var->min_re * ZM);
			var->max_re -= (var->max_re * ZM);
			var->min_im -= (var->min_im * ZM);
			var->max_im -= ((var->min_im + (var->max_re - var->min_re)) * ZM);
		}
		var->re_factor = (var->max_re - var->min_re) / (IMG_SZ - 1);
		var->im_factor = (var->max_im - var->min_im) / (IMG_SZ - 1);
	}
	start(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
	return (x + y);
}

int		drag(int x, int y, t_ini *var)
{
	if (var->f == j && x >= 0 && x <= IMG_SZ && y >= 0 && x <= IMG_SZ)
	{
		if (var->last_x == 0 && var->last_y == 0)
		{
			var->last_x = IMG_SZ / 2;
			var->last_y = IMG_SZ / 2;
		}
		else
		{
			var->k_im += (var->last_y - y) * 0.0025;
			var->k_re += (var->last_x - x) * 0.0025;
			var->last_x = x;
			var->last_y = y;
			start(var);
			mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
		}
	}
	return (0);
}
