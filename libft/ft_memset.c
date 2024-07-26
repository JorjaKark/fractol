/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:49:36 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 16:16:26 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int				i;
	unsigned char	*ptr;

	ptr = str;
	i = n;
	while (i > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		i--;
	}
	return (str);
}
/*
int main(void)
{
    char str[] = "Lana del Rey - Sad Girl";
    int a = 'a';
    ft_memset(str, a, 8);
    printf("%s\n", str);

    return (0);
}
*/
