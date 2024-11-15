/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:18:22 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/15 16:38:45 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Conta o número de nós de uma lista

// Recebe o primeiro node de uma lista
int	ft_lstsize(t_list *lst)
{
	t_list	*ptr; // Criamos node auxiliar para ajudar no avanço da lista
	int		counter;

	counter = 0;
	if (!lst) // Se o node for nulo
		return (counter); // Retorna counter, que nesse caso ainda é zero
	ptr = lst; // Iguala ptr ao primeiro node da lista
	// Loopa pela lista
	while (ptr != NULL)
	{
		counter++; // A cada loop, adiciona no counter
		ptr = ptr->next; // E seta ptr como o próximo node da lista
	}
	return (counter); // Retorna o contador
}
