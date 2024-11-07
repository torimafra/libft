/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:25:37 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 10:47:02 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The bzero() function erases the data in the n bytes of the memory
// Starting at the location pointed to by s
// By writing zeros (bytes containing '\0') to that area.

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0; // Índice para percorrer os bytes da região da memória 
	ptr = (unsigned char *)(s); // Casting de s de void para unsigned char
	// Valores de um ponteiro void não podem ser alterados
	// Como precisamos setar todos os bytes para '\0', é necessário fazer o casting
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
