/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:57:26 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/29 13:57:28 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_img_julia(t_data *img, char **argv)
{
	img->arg1 = argv[2];
	img->arg2 = argv[3];
}

void	put_size_scale(t_data *img)
{
	img->y_size = 420;
	img->x_size = 666;
	img->nbr = 200.0;
	img->arg1 = "mandelbrot";
}
