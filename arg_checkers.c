/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:57:35 by mafferre          #+#    #+#             */
/*   Updated: 2024/07/29 13:57:36 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_mandelbrot(char *argv)
{
	return (ft_strncmp(argv, "mandelbrot", 10) == 0 && ft_strlen(argv) == 10);
}

int	is_julia(char *argv)
{
	return (ft_strncmp(argv, "julia", 5) == 0 && ft_strlen(argv) == 5);
}

int	is_arg_valid(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (argc == 2 && is_mandelbrot(argv[1]))
	{
		return (1);
	}
	else if (argc == 4 && is_julia(argv[1]))
	{
		if (is_valid_number(argv[2]) == 0)
			return (0);
		if (is_valid_number(argv[3]) == 0)
			return (0);
		return (1);
	}
	return (0);
}

int	is_valid_number(char *arg)
{
	int	i;
	int	ponto;

	i = 0;
	ponto = 0;
	if (arg[i] == ' ')
		i++;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	if (arg[i] == '.' || arg[i] == ',')
	{
		ponto++;
		i++;
	}
	while (((arg[i] >= '0' && arg[i] <= '9') || (arg[i] == '.'
				|| arg[i] == ',')) && ponto < 2)
	{
		if (arg[i] == '.' || arg[i] == ',')
			ponto++;
		i++;
	}
	if (arg[i] || ponto >= 2)
		return (0);
	return (1);
}

long double	ft_atod(const char *nbr)
{
	long double	n;
	long double	sign;
	long double	c;
	int			i;

	i = 0;
	c = 1;
	n = 0.0;
	sign = 1;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	if (nbr[i] == '-')
		sign = -1;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9')
		n = nbr[i++] + n * 10 - 48;
	if (nbr[i] == '.' || nbr[i] == ',')
	{
		i++;
		while (nbr[i] >= '0' && nbr[i] <= '9')
			n = n + ((nbr[i++] - 48.0) / 10.0) / pow(10.0, c++ - 1);
	}
	return (n * sign);
}
