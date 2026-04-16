/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:13:26 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/14 22:44:40 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	if (!src && !dest)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// int	main(int ac, char **av)
// {
// 	char	*ptr;
// 	char	*dest;
// 	dest = malloc(900);
// 	ptr = malloc(900);
// 	if (!ptr)
// 		return (1);
// 	if (ac < 4)
// 		return (1);
// 	ft_memset(ptr, ft_atoi(av[1]), ft_atoi(av[2]));
// 	printf("%s\n", ptr);
// 	printf("%s\n", dest);
// 	ft_memcpy(dest, ptr, ft_atoi(av[3]));
// 	printf("%s\n", dest);
// 	free(ptr);
// }
