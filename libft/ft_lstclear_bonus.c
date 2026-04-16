/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:01:28 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/20 11:54:19 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*tmp;

	if (!*lst || !lst)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		del(current->content);
		free(current);
		current = tmp;
	}
	*lst = NULL;
}

//void  del(void *content)
//{
//  free(content);
//}

//int   main(void)
//{
//  t_list  *list;
//  t_list  *node1;
//  t_list  *node2;
//  t_list  *node3;

//  node1 = ft_lstnew(strdup("Hello"));
//  node2 = ft_lstnew(strdup("World"));
//  node3 = ft_lstnew(strdup("!"));

//  node1->next = node2;
//  node2->next = node3;
//  list = node1;

//  puts(list->content);
//  puts(list->next->content);
//  puts(list->next->next->content);
//  ft_lstclear(&list, del);

//  if (list == NULL)
//      printf("test reussis");
//  return (0);
//}
