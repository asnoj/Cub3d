/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:13:35 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/20 12:09:05 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return ((size_t)ft_strlen((char *)src));
}

// int main(void)
// {
// 	char src[] = "Hello";
// 	char dst1[10];
// 	char dst2[10];

// 	printf("Test 1 - Buffer assez grand\n");
// 	printf("ft_strlcpy: %zu - '%s'\n", ft_strlcpy(dst1, src, 10), dst1);

// 	printf("Test 2 - Buffer petit\n");
// 	printf("ft_strlcpy: %zu - '%s'\n", ft_strlcpy(dst2, src, 3), dst1);

// 	return (0);
// }
