/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:56:56 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/15 17:47:49 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deleta e libera o nó especificado e todos os sucessores deste nó, utilizando a função ’del’ e free(3)
// No final, o ponteiro para a lista deve ser definido para NULL

// Recebe um ponteiro para uma lista, e uma função del para deletar o conteúdo de cada nó
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr; // Node auxiliar para ajudar a correr a lista
	t_list	*temp; // Node auxiliar para ajudar a guardar o endereço do próximo node
	// Que está guardado no node ptr que vai ser deletado

	if (!*lst || !del) // Se algum parâmetro for nulo
		return ; // Encerra a função
	ptr = *lst; // Iguala ptr ao primeiro node indicado
	while (ptr != NULL)
	{
		temp = ptr->next; // "temp" guarda o endereço do próximo node
		del(ptr->content); // Deleta o conteúdo de ptr
		free(ptr); // Dá free em ptr
		ptr = temp; // Iguala ptr ao node seguinte, que estava guardado em "temp"
	}
	*lst = NULL; // Faz o ponteiro passado como argumento apontar para um nulo
}
