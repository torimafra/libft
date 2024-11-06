/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:08:24 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/02 18:10:02 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
