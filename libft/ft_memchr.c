/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 03:33:44 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/15 21:47:09 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	i = 0;
	ptr = (const unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == ptr[i])
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}

// int	main(int ac, char **av)
// {
// 	char	str[] = "tie un tigre caca abc W K Z jsp";
// 	char *ptr;
// 	if (ac < 3)
// 		return (1);
// 	printf("%s\n", str);
// 	ptr = ft_memchr(str, (int)av[1][0], ft_atoi(av[2]));
// 	if (ptr)
// 		printf("%s\n", ptr);
// 	else
// 		printf("Caractère non trouve\n");
// }
