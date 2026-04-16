/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 01:42:53 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/20 11:57:57 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const	*set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*dest;

	start = 0;
	while (s1[start] && is_set(s1[start], set))
		start++;
	end = start;
	while (s1[end])
		end++;
	end--;
	while (end > start && is_set(s1[end], set))
		end--;
	dest = (char *)malloc((end - start + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (start <= end)
		dest[i++] = s1[start++];
	dest[i] = '\0';
	return (dest);
}

// int	main(int ac, char **av)
// {
// 	if (ac < 2)
// 		return (1);
// 	ft_putendl(av[1]);
// 	ft_putendl(ft_strtrim(av[1], av[2]));
// }
