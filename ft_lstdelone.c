/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:45:00 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/15 16:54:21 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Pega como um parâmetro um nó e libera a memória de seu conteúdo usando a função ’del’ dada como um parâmetro e libera o nó
// A memória do ’next’ não deve ser liberada

// Recebe o primeiro nó de uma lista, e uma função del
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content); // Usa a função del no conteúdo do nó passado
	free(lst); // Dá free no nó passado, deletando ele
}
