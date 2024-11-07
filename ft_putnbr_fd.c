/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:08:24 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 11:59:45 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Tem como saída o inteiro ’n’ para o file descriptor especificado
// n: o inteiro a ser escrito
// fd: o file descriptor no qual o inteiro será escrito

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	char	*str;
	char	*int_min;

	i = 0;
	str = ft_itoa(n);
	int_min = "-2147483648";
	if (n == -2147483648)
		ft_putstr_fd(int_min, fd);
	else
	{
		while (str[i] != '\0')
		{
			write(fd, &str[i], 1);
			i++;
		}
	}
	free(str);
}
