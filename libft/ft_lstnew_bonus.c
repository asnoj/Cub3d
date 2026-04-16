/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 00:57:46 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/16 20:00:39 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(1 * sizeof(t_list));
	if (!list)
		return (NULL);
	list[0].content = content;
	list[0].next = NULL;
	return (list);
}

// int	main(void)
// {
// }
