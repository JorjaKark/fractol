/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:01:02 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 16:15:08 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*new_dest;
	char	*new_src;

	new_dest = (char *)dest;
	new_src = (char *)src;
	if (!dest && !src)
		return (dest);
	while (n > 0)
	{
		*new_dest++ = *new_src++;
		n--;
	}
	return (dest);
}

/*
int	main(void)
{
    char source[] = "Say anything - Girl in Red";
    char destination[10];
    
    ft_memcpy(destination, source, sizeof(source));
    printf("Copied string: %s\n", destination);

    return 0;
}
*/
