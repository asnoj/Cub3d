/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 23:13:31 by jcrochet          #+#    #+#             */
/*   Updated: 2025/10/24 03:15:46 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_barrow_fill(int fd, char *barrow, char *shovel)
{
	ssize_t	nb;

	nb = 1;
	if (!barrow)
	{
		if (shovel[0] != 0)
			barrow = ft_strdup(shovel);
		else
			barrow = ft_strdup("");
	}
	while (nb > 0 && !ft_strchr(barrow, '\n'))
	{
		nb = read(fd, shovel, BUFFER_SIZE);
		if (nb < 0)
		{
			free(barrow);
			shovel[0] = 0;
			return (NULL);
		}
		if (nb == 0)
			break ;
		shovel[nb] = '\0';
		barrow = ft_strjoin(barrow, shovel);
	}
	return (barrow);
}

void	ft_update_shovel(char *barrow, char *shovel)
{
	char	*newline_pos;
	char	*new_barrow;
	size_t	i;

	i = 0;
	newline_pos = ft_strchr(barrow, '\n');
	if (!newline_pos)
		return ;
	new_barrow = ft_strdup(newline_pos + 1);
	if (!new_barrow)
	{
		shovel[0] = 0;
		free(barrow);
		return ;
	}
	while (new_barrow[i])
	{
		shovel[i] = new_barrow[i];
		i++;
	}
	shovel[i] = '\0';
	free(barrow);
	free(new_barrow);
}

char	*get_next_line(int fd)
{
	char		*barrow;
	static char	shovel[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	barrow = NULL;
	barrow = ft_barrow_fill(fd, barrow, shovel[fd]);
	if (!barrow)
		return (NULL);
	ptr = ft_strchr(barrow, '\n');
	if (ptr)
	{
		line = ft_substr(barrow, 0, ptr - barrow + 1);
		ft_update_shovel(barrow, shovel[fd]);
		return (line);
	}
	if (*barrow)
		return (shovel[fd][0] = 0, barrow);
	return (shovel[fd][0] = 0, free(barrow), NULL);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	i = 1;
// 	if (argc < 2)
// 		return (1);
// 	while (argv[i])
// 	{
// 		fd = open(argv[i], O_RDONLY);
// 		if (fd == -1)
// 			return (1);
// 		line = get_next_line(fd);
// 		while (line)
// 		{
// 			printf("%s", line);
// 			free(line);
// 			line = get_next_line(fd);
// 		}
// 		close(fd);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
