/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:54:09 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/14 14:53:05 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		lendest;
	size_t		lensrc;
	size_t		i;

	i = 0;
	lensrc = ft_strlen(src);
	lendest = 0;
	while (lendest < size && dest[lendest])
		lendest++;
	if (lendest == size)
		return (lendest + lensrc);
	while (src[i] && lendest + i + 1 < size)
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (lendest + lensrc);
}

// int	main(int ac, char **av)
// {
// 	if (ac < 3)
// 		return (1);
// 	char	*dest;
// 	dest = malloc((ft_strlen(av[1]) + ft_strlen(av[2]) + 1) * sizeof(char));
// 	ft_strcpy(dest, av[1]);
// 	printf("av1 = %s av2 = %s | ft_strcat = %s\n",
//	av[1], av[2], ft_strcat(dest, av[2]));
// }
