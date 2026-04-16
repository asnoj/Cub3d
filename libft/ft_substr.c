/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 01:45:15 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/14 22:35:30 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (!s)
		return (NULL);
	i = -1;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (++i < len)
		dest[i] = s[start + i];
	dest[i] = '\0';
	return (dest);
}

// int	main(int ac, char **av)
// {
// 	if (ac < 4)
// 		return 1;
// 	ft_putendl(av[1]);
// 	ft_putendl(ft_strsub(av[1], ft_atoi(av[2]), ft_atoi(av[3])));
// }
