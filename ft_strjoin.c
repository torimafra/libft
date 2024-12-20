/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:58:40 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/11 18:42:47 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Aloca (with malloc(3)) e retorna uma nova string, que é o resultado da concatenação de ’s1’ e ’s2’

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(((ft_strlen(s1) + \
				ft_strlen(s2)) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcpy(result + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (result);
}

