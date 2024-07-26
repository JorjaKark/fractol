/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:25:33 by mafferre          #+#    #+#             */
/*   Updated: 2024/05/17 18:07:16 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	joined = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	while (s1[i])
		joined[j++] = s1[i++];
	i = 0;
	while (s2[i])
		joined[j++] = s2[i++];
	joined[j] = '\0';
	return (joined);
}
/*
int main() {
    // Strings de teste
    const char *prefix = "Hello, ";
    const char *suffix = "world!";

    // Chamada da função ft_strjoin
    char *result = ft_strjoin(prefix, suffix);

    // Verificação se a alocação de memória foi bem-sucedida
    if (result == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        return 1;
    }

    // Impressão do resultado
    printf("Resultado da concatenação: %s\n", result);

    // Liberação da memória alocada
    free(result);

    return 0;
}
*/
