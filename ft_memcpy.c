/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:30:54 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 11:48:58 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memcpy() function copies n bytes from memory area src to memory area dest
// Não trata se as áreas tem overlap
// Se tiverem, pode gerar comportamento indefinido

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	i = 0;
	ptr_dest = (unsigned char *)(dest);
	ptr_src = (unsigned char *)(src);
	if (dest == NULL && src == NULL) // Se alguma das aŕeas for nula
		return (NULL); // Retorna NULL
	if (n == 0) // Se não houver bytes para comparar
		return (dest); // Retorna pointer para dest
	while (i < n) // Percorre os n bytes definidos
	{
		ptr_dest[i] = ptr_src[i]; // Cópia simples de src para dest
		i++;
	}
	return (dest); //Retorna pointeiro para dest
	// Se não retorna nulo, vai sempre retornar um ponteiro para dest
}
