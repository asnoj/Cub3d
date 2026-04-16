/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:30:37 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/15 13:36:50 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			str = ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (str);
}

// char	*ft_strrchr(const char *s, int c)
// {
// 	char	*str;
// 	char	ch;

// 	ch = (char)c;
// 	str = NULL;
// 	while (*s)
// 	{
// 		if (*s == ch)
// 			str = (char *)s;
// 		s++;
// 	}
// 	if (ch == '\0')
// 		return ((char *)s);
// 	return (str);
// }

// int	main()
// {
// 	char *ptr = ft_strrchr("tripouille", 't' + 256);
// 	char *ptr2 = ft_strrchr2("tripouille", 't' + 256);
// 	printf("%s\n", ptr);
// 	printf("%s\n", ptr2);
// }
