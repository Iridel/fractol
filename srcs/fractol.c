/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:06:23 by dhill             #+#    #+#             */
/*   Updated: 2017/12/14 17:04:06 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	validate(int ac, char **av, t_ini *var)
{
	if (ac < 2)
	{
		perror("Error");
		ft_putendl("Valid Arguments: mandelbrot, julia, bship");
		exit(0);
	}
	if (ac > 2)
	{
		perror("Error");
		ft_putendl("Valid Arguments: mandelbrot, julia, bship");
		exit(0);
	}
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		var->f = m;
	else if (ft_strcmp(av[1], "julia") == 0)
		var->f = j;
	else if (ft_strcmp(av[1], "bship") == 0)
		var->f = b;
	else
	{
		perror("Error");
		ft_putendl("Valid Arguments: mandelbrot, julia, bship");
		exit(0);
	}
}

void	put_to_img(t_ini *var, unsigned x, unsigned y, int color)
{
	*((unsigned *)var->img_addr + (x + y * IMG_SZ)) = color;
}

void	create(t_ini *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, WIN_SZ, WIN_SZ, "fractol");
	var->img = mlx_new_image(var->mlx, IMG_SZ, IMG_SZ);
	var->img_addr = mlx_get_data_addr(var->img, &var->bpp,
			&var->line_size, &var->endian);
	var->fractol[m] = mandelbrot;
	var->fractol[j] = julia;
	var->fractol[b] = burningship;
	var->color[0] = greyscale;
	var->color[1] = muted;
	var->color[2] = ice;
	var->color[3] = spring;
	var->color[4] = other;
	var->min_re = -2.0;
	var->max_re = 1.0;
	var->min_im = -1.2;
	var->max_im = var->min_im + (var->max_re - var->min_re);
	var->k_re = 0.353;
	var->k_im = 0.288;
	var->re_factor = (var->max_re - var->min_re) / (IMG_SZ - 1);
	var->im_factor = (var->max_im - var->min_im) / (IMG_SZ - 1);
	start(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
}

int		main(int ac, char **av)
{
	t_ini	*var;

	var = (t_ini *)ft_memalloc(sizeof(t_ini));
	!var ? perror("Error") : 0;
	validate(ac, av, var);
	create(var);
	mlx_hook(var->win, 17, 0, close_window, var);
	mlx_hook(var->win, 2, 0, key_event, var);
	mlx_hook(var->win, 4, 0, mouse_clicks, var);
	mlx_hook(var->win, 6, 0, drag, var);
	mlx_loop(var->mlx);
}
