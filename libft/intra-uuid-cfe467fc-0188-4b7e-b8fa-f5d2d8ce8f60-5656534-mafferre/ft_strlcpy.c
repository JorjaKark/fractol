/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:45:14 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 18:03:47 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (!size)
		return (len);
	while (size > 1 && *src != '\0')
	{
		*dst++ = *src++;
		size--;
	}
	if (size > 0)
		*dst = '\0';
	return (len);
}

/*

int	main() {

	char src[] = "Tomboy - Destiny Rogers";
	char dst[23];

	size_t result = ft_strlcpy(dst, src, sizeof(dst));

	printf("A string copiada: %s\n", dst);
	printf("O retorno (length da src) %zu\n", result);
	
	return 0;
}

*/
