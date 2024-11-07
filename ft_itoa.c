/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:20:41 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 11:31:52 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Função itoa converte um int para string

// Função adicional que converte o int para string
static char	*write_number(int n, char *s)
{
	char	*numbers;

	numbers = "0123456789";
	// O método de conversão é usar essa string com todos os caracteres númericos como guia
	// Usar cada dígito do int como index para pegar o char correspondente a ele
	// Inicialmente, gera uma string com o int ao contrário
	// Inverte a string e retorna
	if (n < 0) // Se n for negativo
	{
		*s = '-'; // O primeiro caractere da string precisa ser um '-'
		s++;
		if (n == -2147483648) // Se n for int min
		{
			*s = '8'; // O segundo caractere da string é um 8
			n = n / 10; // Como 8 já foi colocado, divide n por dez para ir para próximo número
			s++;
		}
		n *= -1; // Como o sinal negativo já foi escrito, transforma n em positivo para o resto da conversão
	}
	while (n > 9) //Se n > 9, significa que o int ainda tem mais de um dígito e precisa ser decrementado
	{
		*s = numbers[n % 10]; // O módulo da divisão de n por 10 isola o último dígito do número
		// E ele é usado como índice para pagar o char correspondete na string numbers
		n = n / 10; // Divide n por 10 para pegar o pŕoximo dígito na próxima iteração do loop
		s++;
	}
	// A função sai do loop quando sobra só um único dígito no int
	*s = numbers[n % 10]; // Escreve o último número
	s++;
	*s = '\0'; // Null terminates a string
	return (s);
}

// Função adicional que conta quantos dígitos tem o int
static int	digit_counter(int n)
{
	int	counter;

	counter = 1; // Começa em 1, por vai ter no mínimo 1
	if (n < 0) // Converte para positivo
		n = n * (-1);
	while (n > 9)
	{
		n = n / 10;
		counter++;
		// Conta quantas vezes ele é dividido por 10
	}
	return (counter);
}

// Função adicional que inverte uma string
static char	*ft_swap(char *s, int n)
{
	size_t	init;
	size_t	end;
	char	temp;

	init = 0;
	if (n < 0)
		init = 1; // Se n for negativo, pula o primeiro elemento da string, que é o '-'
	end = ft_strlen(s) - 1;
	while (init < end)
	{
		temp = s[init];
		s[init] = s[end];
		s[end] = temp;
		init++;
		end--;
	}
	return (s);
}

// Função adicional que lida com n = int min
static char	*is_int_min(int n)
{
	char	*result;

	result = (char *)malloc(12 * sizeof(char)); // Malloca memória o suficiente para o sinal negativo, o número e o terminator
	if (result == NULL)
		return (NULL);
	write_number(n, result); // Gera a string
	ft_swap(result, n); // Inverte
	return (result); // Retorna
}

char	*ft_itoa(int n)
{
	char	*result;

	if (n == -2147483648)
		return (is_int_min(n));
	if (n < 0)
	{
		result = malloc((digit_counter(n) + 2) * sizeof(char)); // Se n for negativo, aloca espaço o suficiente de string para o sinal negativo e o terminator
		if (result == NULL)
			return (NULL);
	}
	else
	{
		result = malloc((digit_counter(n) + 1) * sizeof(char)); // Aloca espaço suficiente para o número + terminator
		if (result == NULL)
			return (NULL);
	}
	write_number(n, result); // Gera string
	ft_swap(result, n); // Inverte
	return (result); // Retorna
}
