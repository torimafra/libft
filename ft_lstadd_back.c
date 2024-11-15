/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:03:25 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/15 16:52:40 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adiciona o nó ’new’ ao final da lista

// Recebe uma lista, e o nó a ser adicionado ao fim dela
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new) // Se algum parâmetro for nulo
		return ; // Encerra a função
	if (*lst == NULL) // Se o primeiro nó da lista for nulo, ou seja, for passada uma lista vazia
	{
		*lst = new; // Seta new como o primeiro nó da lista
		return ; // Encerra
	}
	ft_lstlast(*lst)->next = new; // Usa lstlast para pegar o último nó da lista
	// Aqui estamos considerando a possibilidade de new ser o primeiro nó de uma outra lista, e que podemos estar adicionando outra lista ao fim de lst
	if (ft_lstsize(new) == 1) // Mas se new for um único node, e não o início de uma nova lista
		new->next = NULL; // Seta o next de new como NULL, pq ele é o último node
}
