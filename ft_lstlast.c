/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:50:40 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/15 16:48:28 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Retorna o último nó de uma lista

// Recebe o primeiro node de uma lista
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr; // Criamos node auxiliar para ajudar no avanço da lista
	int		list_size;
	int		counter;

	counter = 1;
	// Usamos list size para pegar o tamanho da lista
	list_size = ft_lstsize(lst);
	if (!lst) // Se lst for nulo
		return (NULL); // Retorna nulo
	if (list_size == 1) // Se o tamanho da lista for 1
		return (lst); // Retorna counter, que é inicializado como 1
	ptr = lst; // Iguala ptr ao primeiro nó da lista
	// Aqui setei o loop para ela só rodar até o penúltimo nó da lista, ou seja, até um menos que o list_size
	while (counter < list_size)
	{
		ptr = ptr->next; // Seta ptr para ser o próximo nó da lista
		counter++; // Incrementa counter
	}
	// A função vai sair do loop quando ptr for igual ao endereço do último nó
	// Que é o que procuramos, então retornamos ptr
	return (ptr);
}
