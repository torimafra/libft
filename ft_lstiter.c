/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:41:49 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/15 17:50:21 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Itera a lista ’lst’ e aplica a função ’f’ no conteúdo de cada nó, alterando a lista lst

// Recebe o primeiro node de uma lista, e uma função f
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr; // Node auxiliar para a ajudar a percorrer a lista

	if (!lst || !f) // Se algum parâmetro passado for nulo
		return ; // Encerra
	ptr = lst; // Iguala ptr a ao node passado para a função
	while (ptr != NULL)
	{
		f(ptr->content); // Aplica a função f no conteúdo de cada node
		ptr = ptr->next; // Passa para o próximo
	}
}
