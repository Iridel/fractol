/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:30:56 by dhill             #+#    #+#             */
/*   Updated: 2017/12/14 17:04:36 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define BLACK		0x00000000

# define GREY5		0x00343d46
# define GREY4		0x004f5b66
# define GREY3		0x0065737e
# define GREY2		0x00a7adba
# define GREY1		0x00c0c5ce
# define GREY0		0x00fafbfc

# define MUTED5		0x00dfdfde
# define MUTED4		0x00a2798f
# define MUTED3		0x00d7c6cf
# define MUTED2		0x008caba8
# define MUTED1		0x00ebdada
# define MUTED0		0x00fcdec6

# define ICE_5		0x00d5eeee
# define ICE_4		0x00b3ecec
# define ICE_3		0x0089ecda
# define ICE_2		0x0043e8d8
# define ICE_1		0x000e0d0
# define ICE_0		0x00bd6c6

# define SPRN_Y		0x00feffb5
# define SPRN_G		0x00dbffb1
# define SPRN_B		0x00cee8ff
# define SPRN_P		0x00d5d2ff
# define SPRN_PI	0x00ffd6ef
# define SPRN_R		0x00ecb6b6

# define OTHR_Y		0x00ffbe4f
# define OTHR_B		0x006bd2db
# define OTHR_T		0x000ea7b5
# define OTHR_N		0x000c457d
# define OTHR_O		0x00e8702a
# define OTHR_P		0x00A30051

# define WIN_SZ		1200
# define IMG_SZ		1200
# define ZM			0.025
# define MAX		30

typedef enum		e_type
{
	m,
	j,
	b
}					t_type;

typedef struct		s_initalize
{
	void			*win;
	void			*img;
	void			*mlx;
	char			*img_addr;
	int				bpp;
	int				line_size;
	int				endian;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			re_factor;
	double			im_factor;
	double			c_im;
	double			c_re;
	double			z_re;
	double			z_im;
	double			z_re2;
	double			z_im2;
	double			k_im;
	double			k_re;
	unsigned int	x;
	unsigned int	y;
	unsigned int	n;
	int				last_x;
	int				last_y;
	int				inside;
	int				set;
	t_type			f;
	void			(*fractol[3])(struct s_initalize*);
	void			(*color[5])(struct s_initalize*);
}					t_ini;

/*
** fractol.c
*/
void				create(t_ini *var);
void				put_to_img(t_ini *var, unsigned x, unsigned y, int color);
void				validate(int ac, char **av, t_ini *var);
/*
** draw
*/
void				mandelbrot(t_ini *var);
void				julia(t_ini *var);
void				burningship(t_ini *var);
void				start(t_ini *var);
/*
** events.c
*/
int					key_event(int keycode, t_ini *var);
int					close_window(t_ini *var);
int					mouse_clicks(int keycode, int x, int y, t_ini *var);
int					drag(int x, int y, t_ini *var);
void				arrow_movement(int key, t_ini *var);
/*
** color.c
*/
void				greyscale(t_ini *var);
void				muted(t_ini *var);
void				ice(t_ini *var);
void				spring(t_ini *var);
void				other(t_ini *var);
#endif
