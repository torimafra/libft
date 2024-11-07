/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:58:40 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 13:59:32 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Aloca (with malloc(3)) e retorna uma nova string, que é o resultado da concatenação de ’s1’ e ’s2’

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	a;
	unsigned int	b;
	char			*result;

	a = 0; // Índice para rodar pelas strings passadas
	b = 0; // Índice para rodar por result
	result = (char *)malloc(((ft_strlen(s1) + \
				ft_strlen(s2)) + 1) * sizeof(char)); // Malloca espaço para result que é a soma do comprimento de s1 e s2, mais o terminator
	if (result == NULL)
		return (NULL);
	while (s1[a] != '\0') // Roda por s1
	{
		result[b] = s1[a]; // E copia
		a++;
		b++;
	}
	a = 0;
	while (s2[a] != '\0') // Roda por s2
	{
		result[b] = s2[a]; // E copia
		a++;
		b++;
	}
	result[b] = '\0'; // Null terminates
	return (result);
}
