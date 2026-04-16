/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 07:11:37 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/14 18:51:54 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
		ptr[i++] = (unsigned char)c;
	return (s);
}

// int	main(int ac, char **av)
// {
// 	char	*ptr;
// 	int		i = 0;
// 	ptr = malloc(9);
// 	while (i < 30)
// 		ptr[i++] = 's';
// 	if (!ptr)
// 		return (1);
// 	if (ac < 3)
// 		return (1);
// 	ft_memset(ptr, ft_atoi(av[1]), ft_atoi(av[2]));
// 	printf("%s\n", ptr);
// 	free(ptr);
// }
