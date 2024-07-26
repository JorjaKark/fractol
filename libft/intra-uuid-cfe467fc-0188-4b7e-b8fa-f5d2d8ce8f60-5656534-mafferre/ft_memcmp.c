/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:30:29 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 16:14:07 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		n--;
		ptr1++;
		ptr2++;
	}
	return (0);
}
/*
int	main()
{
	char	girl_in_red[] = "Apartment 402";
	char	clairo[] = "Bags";

	int	result_ft = ft_memcmp(girl_in_red, clairo, 3);
	int	result_std = memcmp(girl_in_red, clairo, 3);

	printf("Deu %d\n", result_ft);
	printf("Deve dar %d\n", result_std);

	return 0;
}

*/
