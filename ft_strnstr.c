/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:34:39 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/11 18:47:03 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates the first occurrence of the null-terminated string "little" in the string "big"
// Not more than len characters are searched
// Characters that appear after a ‘\0’ character are not searched
// If "little" is an empty string, "big" is returned
// If "little" occurs nowhere in "big", NULL is returned
// Otherwise a pointer to the first character of the first occurrence of "little" is returned

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i_big;
	char			*big_len;
	char			*big_loop;

	i_big = 0;
	if (!(*little)) // Se "little" for nula
		return ((char *)(big)); // Retorna big
	if (len > ft_strlen(big) || (int)(len) < 0)
	// Se o número de bytes para buscar for maior que o tamanho de "big", ou se o len passado for negativo
	// Para verificar se len é negativo, precisa fazer o casting para int, já que size_t não admite valores negativos
		len = ft_strlen(big); // Ajusta len para o tamanho de big
	big_len = ft_substr(big, 0, len); // Trimma big para o tamanho de len
	if (big_len == NULL)
		return (NULL);
	// Se o primeiro caractere de "little" não for encontrado em "big", ou se len for 0
	if (ft_strchr(big_len, little[0]) == NULL || len == 0)
	{
		free(big_len);
		return (NULL);
	}
	while (i_big < len)
	{
		// Procura o primeiro caracter de "little" em na big trimmada, avançando o index a cada iteração
		big_loop = ft_strchr(big_len + i_big, little[0]);
		// Se encontrar little[0]
		if (big_loop != NULL && \
				// Compara little com big_len a partir do primeiro caracter de little encontrado nela, por "n = comprimento de little" bytes
				// Se a comparação der zero, "little" inteira foi encontrada em "big"
				ft_strncmp(little, big_loop, ft_strlen(little)) == 0)
		{
			free(big_len);
			// Retorna o char * para a primeira ocorrência de little [0] em big, a partir do ponto que estamos do loop
			return (ft_strchr(big + i_big, little[0]));
		}
		i_big++;
	}
	free(big_len);
	return (NULL);
}
