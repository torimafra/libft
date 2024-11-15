/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:35:39 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/15 16:08:42 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The strchr() function returns a pointer to the first occurrence of the character c in the string s


char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if ((char)(c) == '\0') // Se o caracter c procurado for o caracter nulo
		return ((char *)(&s[ft_strlen(s)])); // Retorna ponteiro para o caracter nulo de s
	while (s[i] != '\0') // Percorre a string
	{
		if (s[i] == (char)c) // Se encontrar c
			return ((char *)(&s[i])); // Retorna seu ponteiro
		i++;
	}
	return (NULL);
}
