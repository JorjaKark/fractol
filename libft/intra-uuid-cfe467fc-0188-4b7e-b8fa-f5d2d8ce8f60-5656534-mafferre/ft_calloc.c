/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:31:27 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 16:59:25 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elementos, size_t size)
{
	unsigned int	to_allocate;
	char			*ptr;

	to_allocate = num_elementos * size;
	ptr = malloc(to_allocate);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, to_allocate);
	return (ptr);
}
