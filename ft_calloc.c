/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:36:09 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 10:55:55 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The  calloc() function allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory
// The memory is set to zero
// If nmemb or size is 0, then calloc() a unique pointer value that can later be successfully passed to free()
// If the multiplication of nmemb and size would result in integer overflow, then calloc() returns an error

// A diferença da calloc() para a malloc() é que ela seta os bytes da memória alocada para 0

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	
	if (nmemb * size > 2147483647) // Checa se a multiplicação nmemb * size ultrapassa valor máximo do int 
		return (NULL); 
	if ((int)(nmemb) < 0 || (int)(size) < 0) // Checa se algum dos parâmetros passados é negativo
	// Size_t não admite valores negativos, para chegar se foi passado algo negativo precisa fazer casting para int
		return (NULL);
	ptr = malloc(nmemb * size); // Aloca a memória usando malloc()
	if (ptr == NULL) // Proteção malloc
		return (NULL);
	ft_memset(ptr, 0, nmemb * size); // Seta todos os bytes alocados para 0
	return (ptr);
}
