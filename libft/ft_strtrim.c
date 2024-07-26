/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:36:07 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 16:29:50 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_c_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	if (!*s1)
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_c_in_set(s1[start], set))
		start++;
	while (end > start && ft_c_in_set(s1[end], set))
		end--;
	trim = (char *)malloc(sizeof(char) * (end - start + 1 + 1));
	if (!trim)
		return (NULL);
	i = 0;
	while (i < end - start + 1)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
/*
#include <stdio.h>

int	main(void)
{
	char * str = "ababab";
	char *nstr = ft_strtrim(str, "ab");
	printf("%s\n", nstr);
	free(nstr);
	return (0);
}
*/
