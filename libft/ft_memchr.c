/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:57:32 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 16:13:22 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr;

	ptr = (const char *)s;
	while (n > 0)
	{
		if (*ptr == (char)c)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
/*
int	main()
{
	char	str[] = "bad idea - girl in red";
	char	*result_ft = ft_memchr(str, 'g', strlen(str));
	char	*result_std = memchr(str, 'g', strlen(str));

	printf("Deu %p\n", (void *)result_ft);
	printf("Deve dar %p\n", (void *)result_std);

	return 0;
}
*/
