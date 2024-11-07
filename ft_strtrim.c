/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:09:30 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 14:55:54 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Aloca e retorna uma cópia de ’s1’ com os caracteres especificados em ’set’ removidos do início e do final da string
// Isso significa que ela procura por cada elemento de set separadamente, não a ocorrência da string set inteira

// Função adicional para buscar e remover os elementos de set a partir do final de s1, voltando
// Retorna o index imediatamente anterior à última ocorrência de set em s1
static unsigned int	last_index(char const *s1, char const *set)
{
	unsigned int	index;
	int				a;
	size_t			b;

	a = ft_strlen(s1);
	b = 0;
	index = 0;
	while (a >= 0)
	{
		while (b <= ft_strlen(set)) // Loopa por set para procurar cada elemento dela em s1
		{
			if (s1[a] == set[b]) // Se encontrar
			{
				index = a - 1; // Redefine o index para o elemento anterior, diferente de set
				break ; // Sai desse while interno e volta para o (a >= 0)
			}
			b++;
		}
		if (b == ft_strlen(set) + 1) // Se set inteiro já tiver sido percorrido
			break ; // Sai do loop maior e retorna o index
		b = 0; // Se não, reseta o b
		a--; // E segue o loop decrementado em s1
	}
	return (index);
}

// Função adicional para buscar e remover os elementos de set a partir do início de s1
static unsigned int	first_index(char const *s1, char const *set)
{
	unsigned int	index;
	size_t			a;
	size_t			b;

	a = 0;
	b = 0;
	index = 0;
	while (a <= ft_strlen(s1)) // Loopa por s1
	{
		while (b <= ft_strlen(set)) // Loopa por set para procurar cada elemento dela em s1
		{
			if (s1[a] == set[b]) // Se encontrar
			{
				index = a + 1; // // Redefine o index para o elemento posterior, diferente de set
				break ; // Sai desse while interno e volta para o (a >= 0)
			}
			b++;
		}
		if (b == ft_strlen(set) + 1) // Se set inteiro já tiver sido percorrido
			break ; // Sai do loop maior e retorna o index
		b = 0; // Se não, reseta o b
		a++; // E segue o loop em s1
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char				*result;
	unsigned int		last;
	unsigned int		first;

	first = first_index(s1, set);
	last = last_index(s1, set);
	if (last < 0)
	// Se last for menor que zero, significa que a string toda foi percorrida de trás para frente e todos os seus elementos eram iguais a algum elemento de set
		return (ft_strdup("")); // Retorna uma string vazia, já que tudo foi trimmado
	// Usando os índices de set encontrados, cria a substring de s1 que é o resultado da "apara"
	// Índice inicial é o first, o cálculo de len é o índice final menos o inicial + 1
	result = ft_substr(s1, first, (last - first + 1));
	if (result == NULL)
		return (NULL);
	return (result);
}
