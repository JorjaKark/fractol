/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:40:42 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 16:41:44 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = s;
	i = n;
	while (i > 0)
	{
		*ptr = 0;
		ptr++;
		i--;
	}
}
/*
int main(void)
{
    char str[] = "Lana del Rey - Sad Girl";
    ft_bzero(str + 5, 8);
    printf("%s\n", str);

    return (0);
}
*/
