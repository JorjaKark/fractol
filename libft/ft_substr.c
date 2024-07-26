/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:55:26 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 16:45:59 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;
	size_t	i;

	i = 0;
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if ((unsigned int)ft_strlen(s) - start < len)
		size = (unsigned int)ft_strlen(s) - start;
	else
		size = len;
	sub = (char *)malloc((size + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start + i] && size > 0)
	{
		sub[i] = s[start + i];
		size--;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int main() {
    const char *test_string = "Testing the ft_substr function";
    unsigned int start_index = 8;
    size_t substring_length = 6;
    char *substring = ft_substr(test_string, start_index, substring_length);
    if (substring == NULL) {
        printf("Erro: Falha na alocação de memória para a substring.\n");
        return 1;
    }
    printf("Substring: %s\n", substring);
    free(substring);

    return 0;
}
*/
