/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:20:56 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/14 22:39:32 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*str;

	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	ft_bzero(str, nmemb * size);
	return (str);
}

// int	main(int ac, char **av)
// {
// 	if (ac < 3)
// 		return (1);
// 	char *ptr = (char *)ft_calloc(ft_atoi(av[1]),
// 		ft_atoi(av[2]));
// 	ft_putendl_fd(ptr, 1);
// 	free(ptr);
// }
