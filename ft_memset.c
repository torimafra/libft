/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:07:26 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 11:55:40 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	// Valores de um ponteiro void não pode ser alterados
	ptr = (unsigned char *)(s); // Casting de s para unsigned char
	if (n == 0)
		return (s);
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
