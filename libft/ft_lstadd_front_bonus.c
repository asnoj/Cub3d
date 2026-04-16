/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:09:22 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/20 11:55:40 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*listteee = ft_lstnew("hello");
// 	t_list	*neww0 = ft_lstnew("  world!!");
// 	t_list	*neww1 = ft_lstnew("  world1!");
// 	t_list	*neww2 = ft_lstnew("  world22!!");
// 	t_list	*neww3 = ft_lstnew("  world333!!");

// 	ft_lstadd_front(&neww3, neww2);
// 	ft_lstadd_front(&neww2, neww1);
// 	ft_lstadd_front(&neww1, listteee);
// 	ft_lstadd_back(NULL, neww0);
// 	t_list	*content = listteee;

// 	while (content != NULL)
// 	{
// 		printf("%s", (char *)content->content);
// 		content = content->next;
// 	}
// 	printf("\n%d\n",ft_lstsize(listteee));
// 	ft_lstlast(listteee);
// }
