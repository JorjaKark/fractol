/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:57:51 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/29 13:57:52 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_graphic	window_to_graphic(t_window pixel)
{
	t_graphic	c_point;

	c_point.r = (pixel.x_window - 333) / pixel.nbr;
	c_point.i = (pixel.y_window - 210) / pixel.nbr;
	return (c_point);
}

t_graphic	formula(t_graphic c, t_graphic z_prev)
{
	t_graphic	z;

	z = z_prev;
	z.r = z_prev.r * z_prev.r - z_prev.i * z_prev.i + c.r;
	z.i = 2 * z_prev.r * z_prev.i + c.i;
	return (z);
}

int	discover_color(int disclaimer)
{
	if (disclaimer == 100)
		return (0x000000);
	else if (disclaimer < 8)
		return (0xFF69B4);
	else if (disclaimer < 16)
		return (0xA020F0);
	else if (disclaimer < 42)
		return (0x87CEEB);
	else if (disclaimer < 64)
		return (0x4682B4);
	else if (disclaimer < 80)
		return (0xFFFFFF);
	else if (disclaimer < 100)
		return (0x4B0082);
	return (0);
}

int	belongs_to_mbrot_julia(t_data img, t_window pixel)
{
	auto t_graphic c;
	auto t_graphic z;
	auto int count = 0;
	if (ft_strncmp(img.arg1, "mandelbrot", 10) == 0)
	{
		c = window_to_graphic(pixel);
		z = c;
	}
	else
	{
		c.r = ft_atod(img.arg1);
		c.i = -ft_atod(img.arg2);
		z = window_to_graphic(pixel);
	}
	while (count < 100)
	{
		z = formula(c, z);
		if ((z.r * z.r + z.i * z.i) > 4)
			return (count);
		count++;
	}
	return (count);
}

t_window	iterate_all_pixels(t_data img)
{
	auto t_window pixel;
	auto int y = 0;
	auto int x = 0;
	auto int color;
	pixel.nbr = img.nbr;
	while (y < img.y_size)
	{
		while (x < img.x_size)
		{
			pixel.y_window = y;
			pixel.x_window = x;
			color = discover_color(belongs_to_mbrot_julia(img, pixel));
			my_mlx_pixel_put(&img, x, y, color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	return (pixel);
}
