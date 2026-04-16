/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:03:18 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/15 21:53:57 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j]
			&& little[j] && (i + j) < len)
			j++;
		if (j == ft_strlen(little))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// int	main(int ac, char **av)
// {
// 	if (ac < 4)
// 		return (1);
// 	char *ptr = ft_strnstr(av[1], av[2], ft_atoi(av[3]));
// 	if (ptr)
// 		printf("%s\n", ptr);
// 	else
// 		printf("pas trouve le substr bouffon\n", av[1]);
// }
