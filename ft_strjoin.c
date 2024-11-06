/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:58:40 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/05 18:24:24 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	a;
	unsigned int	b;
	char			*result;

	a = 0;
	b = 0;
	result = (char *)malloc(((ft_strlen(s1) + \
				ft_strlen(s2)) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[a] != '\0')
	{
		result[b] = s1[a];
		a++;
		b++;
	}
	a = 0;
	while (s2[a] != '\0')
	{
		result[b] = s2[a];
		a++;
		b++;
	}
	result[b] = '\0';
	return (result);
}
