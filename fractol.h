/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:58:10 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/29 13:58:11 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x_size;
	int		y_size;
	double	nbr;
	char	*arg1;
	char	*arg2;
}			t_data;

typedef struct s_graphic
{
	double	r;
	double	i;

}			t_graphic;

typedef struct s_window
{
	int		x_window;
	int		y_window;
	double	nbr;
}			t_window;

// arg_checkers.c
int			is_mandelbrot(char *argv);
int			is_arg_valid(int argc, char **argv);
long double	ft_atod(const char *nbr);
int			is_valid_number(char *arg);

// mandelbrot.c
t_graphic	window_to_graphic(t_window pixel);
t_graphic	formula(t_graphic c, t_graphic z_prev);
int			discover_color(int disclaimer);
int			belongs_to_mbrot_julia(t_data img, t_window pixel);
t_window	iterate_all_pixels(t_data img);

// main.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			handle_key(int keycode, t_data *data);
int			handle_close(t_data *data);
int			nbr_scale(int button, int x, int y, t_data *img);

// put_img.c
void		put_img_julia(t_data *img, char **argv);
void		put_size_scale(t_data *img);

#endif
