/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:10:15 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/20 12:14:38 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = n;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (s < d)
	{
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
		return (dest);
	}
	if (s > d)
	{
		return (ft_memcpy(dest, src, n));
	}
	return (dest);
}

// #include <string.h>
// int main(void)
// {
// 	char str[20] = "Hello World";
// 	char cmp[20];

// 	printf("Original: %s\n", str);
// 	ft_memmove(str + 3, str, 8);
// 	printf("ft_memmove: %s\n", str);

// 	strcpy(str, "Hello World");
// 	strcpy(cmp, str);
// 	memmove(cmp + 3, cmp, 8);
// 	printf("memmove:    %s\n", cmp);

// 	return (0);
// }
