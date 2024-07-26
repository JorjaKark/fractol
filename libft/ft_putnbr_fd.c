/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:07:01 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 16:23:14 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n *= -1;
			ft_putnbr_fd(n, fd);
		}
		else if (n / 10 == 0)
		{
			n = n + 48;
			write (fd, &n, 1);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
/*
int main() 
{
    ft_putnbr_fd(123, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(-456, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(0, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(-2147483648, 1);
    write(1, "\n", 1);

    return 0;
}
*/
