/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:16:30 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 14:21:28 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Aplica a função ’f’ em cada caractere de uma string passada como argumento
// Passa o índice de s como primeiro argumento
// Cada caractere é passado por endereço para ’f’ para serem modificados se necessário
// Altera os caracteres originais de s

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i] != '\0') // Loopa pela string
	{
		f(i, &s[i]); // Aplica função f em cada elemento
		// Cada elemento passado por endereço, com &
		i++;
	}
}
