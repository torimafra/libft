/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:35:57 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 15:11:35 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// If c is a lowercase letter, returns its uppercase equivalent
// If c is not a lowercase letter, returns c.

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32); // Pela tabela ASCII, o equivalente uppercase de uma letra está 32 elementos para trás
	return (c);
}
