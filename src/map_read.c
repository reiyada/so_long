/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:45:26 by ryada             #+#    #+#             */
/*   Updated: 2025/03/17 10:37:40 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_lines(char **map, int i, int fd)
{
	while (i >= 0)
		free(map[i--]);
	free(map);
	close(fd);
}

char	**ft_read_map(const char *filename)
{
	int		fd;
	int		i;
	int		height;
	char	**map;

	height = ft_map_height(filename);
	map = malloc((height + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(map), NULL);
	i = 0;
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			ft_free_lines(map, i, fd);
		i++;
	}
	map[height] = NULL;
	close(fd);
	return (map);
}
