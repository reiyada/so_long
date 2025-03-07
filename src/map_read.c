/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:45:26 by ryada             #+#    #+#             */
/*   Updated: 2025/03/07 15:52:22 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//fill the map by passing the input to gnl

char **ft_read_map(const char *filename)
{
    int fd;
    int i;
    int height;
    char **map;

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
        {
            map[i] = NULL;
            return(ft_free_map(map), NULL);
        }
        i++;
    }
    map[height] = NULL;
    close(fd);
    return (map);
}
