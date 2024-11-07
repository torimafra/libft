/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:07:12 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 14:20:38 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Aplica a função ’f’ para cada caractere da string ’s’
// Passa o índice de s como primeiro argumento
// Ao contrário da striteri, cria e retorna uma nova string com os caracteres alterados pela função ’f’

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	i = 0;
	result = malloc((ft_strlen(s) + 1) * sizeof(char)); // Malloca espaço para a string nova alterada que vai ser gerada
	if (result == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
