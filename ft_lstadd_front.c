/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:23:45 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/15 16:35:45 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adiciona o nó ’new’ no início da lista

// Recebe uma lista e um node para ser adicionado a ela
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst) // Se a lista não for nula
	{
		if (*lst) // E já tiver um node nela
			new->next = *lst; // Seta o next de new para apontar para esse node, que passar a ser o segundo da lista
	}
	*lst = new; // Coloca new como o node apontado pelo ponteiro para a lista
}
