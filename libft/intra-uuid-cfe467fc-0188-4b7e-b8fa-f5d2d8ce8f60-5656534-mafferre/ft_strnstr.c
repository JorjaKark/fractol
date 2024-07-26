/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:46:50 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 16:40:05 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && (i + j) < len)
		{
			j++;
			if (!little[j])
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

/*
int main()
{
    const char *big = "Tomboy - Destiny Rogers";
    const char *little = "Destiny";
    size_t len = 20;

    char *result = ft_strnstr(big, little, len);

    if (result != NULL)
    {
        printf("Substring encontrada: %s\n", result);
    }
    else
    {
        printf("Substring não encontrada.\n");
    }

    return 0;
}
*/
