/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:35:39 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 14:41:26 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns a pointer to the last occurrence of the character c in the string s

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0) // Loopa de trás para frente em s até o índice 1, procurando c
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i--;
	}
	// Devido à condição i--, dentro do loop só podemos ir até o índice 1 para evitar que, ao chegar em zero, i seja decrementado para -1
	if (s[i] == (char)c) // Checa se o índice 0 de s é igual a c
		return ((char *)(&s[i]));
	return (NULL);
}
