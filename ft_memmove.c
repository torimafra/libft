/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:18:29 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 11:53:39 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 // The  memmove() function copies n bytes from memory area src to memory area dest
 // The memory areas may overlap
 // Se tiver overlap, explicação abaixo de como o processo é alterado

// Função adicional de cópia simples de n bytes, se não houver overlap
static unsigned char	*copy(unsigned char *s1, unsigned char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

// Se houver overlap entra as áreas de memória, a cópia a partir do último byte, voltando até o primeiro
// Para não correr o risco de alterar bytes que ainda vão ser copiados
static unsigned char	*r_copy(unsigned char *s1, unsigned char *s2, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		s1[i - 1] = s2[i -1];
		i--;
	}
	return (s1);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)(dest);
	ptr_src = (unsigned char *)(src);
	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	if (ptr_dest < ptr_src) // Se a área de dest for antes de src, cópia simples
	{
		copy(ptr_dest, ptr_src, n);
	}
	else if (ptr_dest > ptr_src) // Se a aŕea de dest começar depois de src, há o risco de overlap
	{
		r_copy(ptr_dest, ptr_src, n); // Realiza cópia reversa
	}
	return (dest);
}
