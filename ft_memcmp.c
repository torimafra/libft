/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:55:04 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 11:45:36 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 // The memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	// Converter as duas áreas para unsigned char, para facilitar e deixar a comparação mais confiável
	ptr_s1 = (unsigned char *)(s1);
	ptr_s2 = (unsigned char *)(s2);
	if (n == 0)
		return (0);
	while (i < n) // Percorre os n bytes definidos
	{
		// Até encontrar algum valor diferente
		if (ptr_s1[i] != ptr_s2[i])
			return (ptr_s1[i] - ptr_s2[i]); // Retorna comparação desse valor
		i++;
	}
	return (0); // Se não encontrar valores diferentes, retorna 0 (as duas áreas são iguais)
}
