/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 01:22:50 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/14 23:12:18 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;
	size_t				i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (str1[i] - str2[i] != 0)
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

// int main (int ac, char **av)
// {
// 	int res;
// 	if (ac < 3)
// 		return (1);
// 	printf("str1 = %s\nstr2 = %s\n", av[1], av[2]);
// 	printf("%d\n", ft_memcmp(av[1], av[2], ft_atoi(av[3])));
// }
