/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:57:42 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/29 13:57:43 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		if (data->mlx && data->img)
			mlx_destroy_image(data->mlx, data->img);
		if (data->mlx && data->mlx_win)
			mlx_destroy_window(data->mlx, data->mlx_win);
		if (data->mlx)
			mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	return (0);
}

int	handle_close(t_data *data)
{
	if (data->mlx && data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx && data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	nbr_scale(int button, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (button == Button4)
	{
		img->nbr = img->nbr / 0.9;
	}
	if (button == Button5)
	{
		img->nbr = img->nbr * 0.9;
	}
	iterate_all_pixels(*img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		img;
	t_window	pixel;

	if (is_arg_valid(argc, argv) == 0)
	{
		write (1, "./fractol mandelbrot\n", 22);
		write (1, "./fractol julia -0.8 0.156\n", 28);
		return (0);
	}
	put_size_scale(&img);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.x_size, img.y_size, "fractol");
	img.img = mlx_new_image(img.mlx, img.x_size, img.y_size);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	if (argc == 4)
		put_img_julia(&img, argv);
	pixel = iterate_all_pixels(img);
	mlx_key_hook(img.mlx_win, handle_key, &img);
	mlx_hook(img.mlx_win, 17, 0, handle_close, &img);
	mlx_mouse_hook(img.mlx_win, nbr_scale, &img);
	mlx_loop(img.mlx);
	return (0);
}
