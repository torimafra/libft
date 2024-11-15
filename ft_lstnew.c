/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:18:41 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/15 16:33:24 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Aloca e retorna um novo nó
// A variável ’content’ é inicializada com o valor do parâmetro ’content’
// A variável ’next’ é inicializada com NULL

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node; // Cria ponteiro para uma nova instância da estrutura

	new_node = (t_list *)malloc(sizeof(t_list)); // Malloca espaço para ela
	if (new_node == NULL) // Proteção malloc
		return (NULL);
	new_node->content = content; // Seta o content com o argumento passado ao chamar a função
	new_node->next = NULL; // Seta next como NULL
	return (new_node); // Retorna o node criado
}
