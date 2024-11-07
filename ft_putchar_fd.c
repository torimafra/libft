/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:33:24 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 11:57:24 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Tem como saída o caractere ’c’ para o file descriptor especificado
// c: o caractere a ser escrito
// fd: o file descriptor no qual o caracter será escrito

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
