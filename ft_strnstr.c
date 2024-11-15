/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:34:39 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/15 16:27:57 by vimafra-         ###   ########.fr       */
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
	char			*big_loop;

	i_big = 0;
	if (!(*little)) // Se little for vazia
		return ((char *)(big)); // Retorna big
	if (len > ft_strlen(big) || (int)(len) < 0) // Se a len passada ultrapassar o tamanho de big ou for negativa
		len = ft_strlen(big); // Ajusta para o tamanho de big
	if (len == 0) // Se len for zero
		return (NULL); // Retorna nulo
	while (i_big <= len) // Enquanto o iterador for menor ou igual ao limite de len bytes
	{
		// "big + i_big" avança o ponteiro em big, tirando os elementos já percorridos
		big_loop = ft_strchr(big + i_big, little[0]); // Procura a ocorrência do primeiro caracter de little em big
		// Se encontrar, e o comprimento de little couber em big_loop até o limite de len
		if (big_loop != NULL && (big_loop + ft_strlen(little)) <= &big[len] && \
			// E se big_loop for igual a little pelo comprimento de little
			ft_strncmp(little, big_loop, ft_strlen(little)) == 0)
			// Retorna a string a partir desse ponto em que ela está no loop
			return (big_loop);
		// Se não, continua iterando por big
		i_big++;
	}
	// Se não encontrar little em len bytes de big, retorna nulo
	return (NULL);
}

