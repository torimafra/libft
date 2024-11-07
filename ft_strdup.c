/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:52:36 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 13:53:25 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The  strdup() function returns a pointer to a new string which is a duplicate of the string s
// Memory for the new string  is  obtained  with malloc(3), and can be freed with free(3)

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	char			*dup;

	i = 0;
	dup = (char *)malloc(ft_strlen(s) * sizeof(char) + 1); // Malloca espaço para s + terminator na nova string
	if (dup == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i]; // Cópia simples de s para dup
		i++;
	}
	dup[i] = '\0'; // Null terminates
	return (dup);
}
