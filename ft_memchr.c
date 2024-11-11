/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:40:19 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/09 14:31:30 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The  memchr()  function  scans  the  initial n bytes of the memory area
// pointed to by s for the first instance of c

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i; // Índice para percorrer os bytes de memória
	unsigned char	*ptr;
	unsigned char	temp_c;

	i = 0;
	// O tipo unsigned char é frequentemente usado para representar um byte
	// Ele tem um intervalo de valores de 0 a 255, o que corresponde exatamente ao intervalo de valores que um único byte pode armazenar
	// Isso elimina qualquer ambiguidade que poderia surgir se os bytes fossem interpretados como char, que pode ser tanto signed (-) quanto unsigned (+)
	// Ao forçar a interpretação como unsigned char, o comportamento da função se torna previsível em diferentes plataformas
	ptr = (unsigned char *)(s);
	temp_c = (unsigned char)(c);
	if (n == 0)
		return (NULL);
	while (i < n) // Percorremos a aŕea de memória limitada por n bytes
	{
		if (ptr[i] == temp_c) // Encontrado c
			return (&ptr[i]); // Retorna seu ponteiro
		i++;
	}
	return (NULL); // Não encontrando, retorna NULL
}
