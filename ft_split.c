/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:48:23 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 13:49:45 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Aloca (com malloc(3)) e retorna um array de strings obtidas pela divisão de ’s’
// Utiliza o caractere ’c’ como delimitador das divisões
// O array deve terminar com um ponteiro NULL

// Função adicional que conta quantas vezes c aparece na string
// Pensada para ser usada após a string s passar pra strtrim, e estar sem char c no início e no final
static unsigned int	c_counter(char const *s, char c)
{
	unsigned int		counter;
	size_t				i;

	i = 0;
	counter = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c && s[i - 1] != c)
		// A verificação de s[i - 1] != c é para não contar os char c repetidos, por exemplo "abcccde"
		// Que não são relevantes para a divisão em substrings
			counter++;
		i++;
	}
	return (counter);
}

// Função adicional para transformar o char c em uma char const c, para poder ser passada como argumento na strtrim
static char const	*char_const_maker(char c)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = c;
	result[1] = '\0';
	return ((char const *)(result));
}

// Função adicional que cria as char ** de retorno se:
// A string s passada for vazia
// A string str trimmada for vazia
// Não for encontrado nenhum char c na string s
static char	**result_is(char *str, int n)
{
	char	**result;

	// Se strings vazias, n é passado como 0
	// Se c não for encontrado, n é passado como 1
	if (n == 0)
	{	
		// No caso de strings vazias, o retorno é um char ** com apenas um char * = NULL
		result = (char **)malloc(sizeof(char *));
		if (result == NULL)
			return (NULL);
		result[0] = NULL;
	}
	// Se c não for encontrado, o retorno é um char ** com char[0] sendo a própria string original e char [1] = NULL
	if (n == 1)
	{
		result = (char **)malloc(2 * sizeof(char *));
		if (result == NULL)
			return (NULL);
		result[0] = ft_strdup(str);
		if (result[0] == NULL)
			return (NULL);
		result[1] = NULL; // Adiciona ponteiro nulo no final
	}
	free(str); // Liberar o espaço de memória de str
	return (result);
}

// Função adicional que cria o retorno se houver a divisão em substrings
static char	**return_is_subs(char **result, char *str, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	first;

	i = 0;
	j = 0;
	first = 0; // Esse vai ser sempre o primeiro index de cada substring
	while (i <= ft_strlen(str)) 
	{
		if (str[i] == c || i == ft_strlen(str)) // Se encontrar c ou se chegar ao final da string
		{
			result[j] = ft_substr(str, first, i - first); // Cria uma substring
			if (result == NULL)
				return (NULL);
			while (str[i] == c) // Condição para pegar caracteres c em sequência, e avançar por eles
				i++;
			first = i; // O próximo index first vai ser o próximo elemento depois do último c encontrado
			j++;
		}
		i++;
	}
	result[j] = NULL; // Adiciona ponteiro nulo no final
	free(str);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char		*str;
	char		*c_const;
	char		**result;

	c_const = (char *) char_const_maker(c); // Cria uma char const com o char c para poder ser passado como argumento na strtrim
	if (c_const == NULL)
		return (NULL);
	str = ft_strtrim(s, (const char *)c_const); // Trimma qualquer caracter c encontrado no início ou fim da string
	free(c_const); // c_const não vai ser mais usada, então ela é liberada
	if (str == NULL)
		return (NULL);
	if (s[0] == '\0' || str[0] == '\0') // Se s foi vazia ou str retornar string vazia
		return (result_is(str, 0));
	if (c_counter(str, c) == 0) // Se não forem encontrados char c na string
		return (result_is(str, 1));
	// A quantidade de substrings que vai ser formada é o retorno de c + 1
	result = (char **)malloc((c_counter(str, c) + 2) * sizeof(char *)); // Malloca espaço também para o ponteiro nulo do final
	if (result == NULL)
		return (NULL);
	return (return_is_subs(result, str, c));
}
