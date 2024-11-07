/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:25:29 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 14:13:21 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strlcat() function appends the NUL-terminated string src to the end of dst
// It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result, as long as there is at least one byte free in dst
// A byte for the NUL should be included in size
// Returns the total length of the string they tried to create

// Idealmente, o size passado vai ser o tamanho total do buffer de dst
// Ou seja, a len de dst + seus bytes vazios a serem preenchidos
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	// Dst precisa ter espaço para ser preenchida por n bytes de src
	if (dst_len >= size) // Se não tiver espaço
		return (src_len + size); // Retorna a len da string que a função tentou criar: src + len
	while (src[i] != '\0' && (dst_len + 1 + i) < size)
	// Enquanto a soma da len de dst + espaço para o terminator + o byte que estamos de src for menor que size
	{
		dst[dst_len + i] = src[i]; // Copia
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
