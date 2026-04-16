/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:36:03 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/16 19:08:46 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = s;
	while (i < n)
		ptr[i++] = '\0';
}

// int	main(int ac, char **av)
// {
// 	char	*ptr;
// 	ptr = malloc(900);
// 	if (!ptr)
// 		return (1);
// 	if (ac < 3)
// 		return (1);
// 	ft_memset(ptr, ft_atoi(av[1]), ft_atoi(av[2]));
// 	printf("%s\n", ptr);
// 	ft_bzero(ptr, ft_atoi(av[2]));
// 	printf("%s\n", ptr);
// 	free(ptr);
// }
