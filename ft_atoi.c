/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:53:12 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 10:40:08 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Converte strings númericas para int
// Retorna o int convertido

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				sign;
	int				result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] != '\0' && ((nptr[i] >= 9 && nptr[i] <= 13) \
			|| nptr[i] == 32)) // Loopa por caracteres de whitespaces no início da string
		i++;
	if (nptr[i] == '-' || nptr[i] == '+') // Se encontrar um sinal + ou -
	{
		if (nptr[i] == '-') // Se o sinal for negativo
			sign = sign * (-1); // Sign vira -1, para multiplicar o int final e torná-lo negativo como a string original
		i++; // Segue loopando pela string
	}
	// Na atoi, a string só pode ter UM sinal, negativo ou positivo
	// Se na continuação do loop que percorre a string for encontrado um segundo sinal, a função returna 0
	while (nptr[i] >= '0' && nptr[i] <= '9') // Encontrando um caractere de número, a função entra nesse loop para iniciar a conversão de char para int
	{
		result = result * 10 + (nptr[i] - '0');
		// Subtrair o caractere '0' de um char transforma ele em int
		i++;
	}
	// Se o caractere logo depois dos whitespaces ou do primeiro sinal não for um número, a função não entra no loop acima
	// Como o valor inicial de result = 0, e ele não é modificado, vai retornar 0 * sign, retornando zero
	// Senão, retorna o resultado gerado no loop acima, multiplicado por sign
	return (result * sign);
}
