/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:34:39 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/05 12:28:31 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i_big;
	char			*big_len;
	char			*big_loop;

	i_big = 0;
	if (!(*little))
		return ((char *)(big));
	if (len > ft_strlen(big) || (int)(len) < 0)
		len = ft_strlen(big);
	big_len = ft_substr(big, 0, len);
	if (big_len == NULL)
		return (NULL);
	if (ft_strchr(big_len, little[0]) == NULL || len == 0)
		return (NULL);
	while (i_big < len)
	{
		big_loop = ft_strchr(big_len + i_big, little[0]);
		if (big_loop != NULL && \
				ft_strncmp(little, big_loop, ft_strlen(little)) == 0)
			return (ft_strchr(big + i_big, little[0]));
		i_big++;
	}
	return (NULL);
}
