/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 22:04:53 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/20 11:53:36 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

//void  f(void *content)
//{
//  printf("%s\n", (char *)content);
//}

//int   main(void)
//{
//  t_list  *list;

//  list = ft_lstnew("Hello");
//  list->next = ft_lstnew("World");
//  list->next->next = ft_lstnew("!");

//  ft_lstiter(list, f);
//  return (0);
//}
