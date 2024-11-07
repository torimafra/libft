/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:39:03 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 15:07:52 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Retorna uma substring da string ’s’ que começa no índice ’start’ e tem o tamanho máximo de ’len’

// Função adicional que copia o trecho definido de s para a nova string, que vai ser a substring retornada pela função principal
static char	*make_subs(unsigned int start, unsigned int final_index, \
				char const *s, char *str)
{
	// Star e final index são os limites do trecho de s que vão ser copiados para str
	unsigned int	i;

	i = 0;
	while (start <= final_index)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		final_index;
	char				*str;
	unsigned int		s_len;

	s_len = ft_strlen(s);
	if (len > s_len) // Se for pedido para criar uma substring maior que o tamanho original de s
		len = s_len; // Len é ajustado para o tamanho de s
	// S_len - start é o número de elementos de s que sobram contando a partir de start
	// Se len for maior que esse número, ele está ultrapassando o limite de s
	if (len >= (s_len - start))
		len = s_len - start; // Len é ajustado para o número de elementos de s que sobram a partir de start
	final_index = start + (len - 1);
	if (final_index > s_len) // Se o index final (criado para ser passado para a função make_subs) ultrapassar o tamanho inicial de s
		final_index = s_len - 1; // Ajusta o final index para não ultrapassar
	if (start >= s_len || (start == 0 && len == 0)) //Se o índice inicial da substring ultrapassar o tamanho inicial de s
	// Ou índice inicial for zero e len for zero
		return (ft_strdup("")); // Retorna uma string vazia
	str = (char *)malloc((len + 1) * sizeof(char)); // Malloca espaco para a substring que vai ser gerada
	if (str == NULL)
		return (NULL);
	make_subs(start, final_index, s, str); // Cria a substring
	return (str); // Retorna 
}
