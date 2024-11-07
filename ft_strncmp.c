/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:25:30 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 14:25:56 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compares only the first (at most) n bytes of s1 and s2
// Returns an integer less than, equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or be greater than s

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0) // Se n = 0, nenhum byte vai ser comparado
		return (0); // Retorna 0
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
		// Enquanto os s1 e s2 (até o limite máxima de n - 1) forem iguais, segue o loop
	}
	// Função sai do loop quando encontra caracteres diferentes, e retorna a diferença entre eles
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
