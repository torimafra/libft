/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:48:06 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 15:11:19 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// If c is an uppercase letter, returns its lowercase equivalent
// If c is not an uppercase letter, returns c

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32); // Pela tabela ASCII, o equivalente lowercase de uma letra está 32 elementos a frente
	return (c);
}
