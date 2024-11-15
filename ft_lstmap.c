/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:00:20 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/15 18:00:23 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Itera a lista ’lst’ e aplica a função ’f’ no conteúdo de cada nó
// Cria uma nova lista resultante de sucessivas aplicações da função ’f’
// A função ’del’ é utilizada para deletar o conteúdo de um nó, caso necessário

// Recebe o primeiro nó de uma lista, uma função f para alterar o conteúdo dos nós, e a função del para deletar o conteúdo de um nó, se necessário
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst; // Para criar a duplicata alterada da lst passada
	t_list	*new_node; // Para criar cada duplicada de node
	t_list	*last; // Para guardar sempre o último node da lista nova

	if (!lst || !f || !del) // Se algum argumento passado for nulo
		return (NULL); // Retorna nulo
	new_lst = ft_lstnew(f(lst->content)); // Cria o primeiro node da nova lista, com o conteúdo de lst
	if (new_lst == NULL) // Proteção do malloc
		return (NULL);
	last = new_lst; // Iguala last a new lst, por enquanto o primeiro e último nó da lista
	lst = lst->next; // Avança em lst
	while (lst) // Enquanto lst não for nula
	{
		new_node = ft_lstnew(f(lst->content)); // Cria novo com o conteúdo do nó atual de lst alterado por f
		if (new_node == NULL) // Se a criação do novo nó falhar
		{
			ft_lstclear(&new_lst, del); // Apaga toda a lista criada até aqui
			// Porque ao entrar no loop sempre teremos pelo menos um node já criado com sucesso, o new_lst
			return (NULL); //Retorna nulo
		}
		last->next = new_node; // Coloca o endereço do novo node criado no next do último da lista
		last = new_node; // Iguala last a esse último novo node criado
		lst = lst->next; // Avança em lst, para continuar a duplicação
	}
	return (new_lst); // Retorna a nova lista criada, duplica de lst alterada por f
}
