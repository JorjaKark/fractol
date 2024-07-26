/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:38:30 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 18:09:24 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (*s1 == '\0')
			break ;
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/*
int	main() 
{
	const char *str1 = "Snuff";
	const char *str2 = "Slipknot";
	int result = ft_strncmp(str1, str2, 5);
	int esperado = strncmp(str1, str2, 5);

       	printf("deu %d\n", result);
	printf("deve dar %d\n", esperado);
	return 0;
}

*/
