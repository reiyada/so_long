/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:29:30 by ryada             #+#    #+#             */
/*   Updated: 2025/03/07 15:55:37 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_count_height(char **map)
{
    int height;

    height = 0;
    while (map[height])
        height++;
    return (height);
}

int ft_count_width(char **map)
{
    int width;

    if (!map || !map[0])
        return (0);
    width = ft_strlen(map[0]);
    if (map[0][width - 1] == '\n')
        width--;
    return (width);
}

void    ft_find_player(char **map, t_pos *player)
{
    int x;
    int y;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                player->column = x;
                player->row = y;
                return;
            }
            x++;
        }
        y++;
    }
}

char **ft_copy_map(char **map)
{
    int height;
    int i;
    char **copy;

    height = ft_count_height(map);
    copy = malloc((height + 1) * sizeof(char *));
    if (!copy)
        return (NULL);
    copy[height] = NULL;
    i = 0;
    while (i < height)
    {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i])
        {
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    return (copy);
}

void ft_flood_fill(char **map, int x, int y)
{
    if (y < 0 || x < 0 || !map[y] || !map[y][x])
        return;
    if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'H')
        return;
    map[y][x] = 'V'; //visited
    ft_flood_fill(map, x, y - 1);//up
    ft_flood_fill(map, x, y + 1);//down
    ft_flood_fill(map, x - 1, y);//left
    ft_flood_fill(map, x + 1, y);//right
}

void    ft_free_map(char **map)
{
    int y;

    if (!map)
        return;
    y = 0;
    while (map[y])
    {
        free(map[y]);
        y++;
    }
    free(map);
}

int ft_map_height(const char *filename)
{
    int fd;
    char *line;
    int height = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    line = get_next_line(fd);
    while (line != NULL)
    {
        free(line);
        height++;
        line = get_next_line(fd);
    }
    close(fd);
    return (height);
}

void ft_set_map_dimentions(t_game *game)
{
    game->height = ft_count_height(game->map);
    game->width = ft_count_width(game->map);
}
