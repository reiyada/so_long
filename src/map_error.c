/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:30:31 by ryada             #+#    #+#             */
/*   Updated: 2025/02/07 16:35:26 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_is_rectanglar(char **map, int width)
{
    int y;
    int cur_width;

    if (!map || !*map)
        return (0);
    y = 1;
    while (map[y])
    {
        cur_width = ft_strlen(map[y]);
        if (map[y][cur_width - 1] == '\n') // ✅ Ignore trailing newline
            cur_width--;
        if (cur_width != width)
        {
            ft_putstr_fd("Error: Not rectangular\n", 2);
            return (0);
        }
        y++;
    }
    return (1);
}


// int ft_is_rectanglar(char **map, int width)
// {
//     int y;
//     int cur_width;

//     if (!map || !*map)
//         return (0);
//     y = 1;
//     while (map[y])
//     {
//         cur_width = ft_strlen(map[y]);
//         if (cur_width != width)
//         {
//             ft_putstr_fd("Error not rectanglar\n", 2);
//             return (0);
//         }
//         y++;
//     }
//     return (1);
// }

int ft_is_covered(char **map, int height, int width)
{
    int y;
    int x;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
            {
                if (map[y][x] != '1')
                {
                    ft_putstr_fd("Error not covered\n", 2);
                    return (0);
                }
            }
            x++;
        }
        y++;
    }
    return (1);
}

int ft_is_valid_char (char **map, int height, int width)
{
    int y;
    int x;

    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C'
                && map[y][x] != 'E' && map[y][x] != 'P' && map[y][x] != 'H')
                {
                    ft_putstr_fd("Error Invalid char\n", 2);
                    return (0);
                }
            x++;
        }
        y++;
    }
    return (1);
}

int ft_check_char_count(char **map, int height, int width)
{
    int c;
    int e;
    int p;
    int temp_width;

    c = 0;
    e = 0;
    p = 0;
    while(--height >= 0)
    {
        temp_width = width;
        while(--temp_width >= 0)
        {
            if (map[height][temp_width] == 'C')
                c++;
            else if (map[height][temp_width] == 'E')
                e++;
            else if (map[height][temp_width] == 'P')
                p++;
        }
    }
    if (!c || e != 1 || p != 1)
    {
        ft_putstr_fd("Error char count\n", 2);
        return (0);
    }
    return (1);
}

int ft_check_valid_path(char **map)
{
    t_pos player;
    int y;
    int x;
    char **map_copy;

    map_copy = ft_copy_map(map);
    ft_find_player(map_copy, &player);
    ft_flood_fill(map_copy, player.column, player.row);
    y = 0;
    while (map_copy[y])
    {
        x = 0;
        while (map_copy[y][x])
        {
            if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
            {
                ft_putstr_fd("Error path\n", 2);
                ft_free_map(map_copy);
                return (0);
            }
            x++;
        }
        y++;
    }
    ft_free_map(map_copy);
    return (1);
}

int ft_is_valid_map(char **map, int height, int width)
{
    if (!(ft_is_rectanglar(map, width) && ft_is_covered(map, height, width)
        && ft_is_valid_char(map, height, width) && ft_check_char_count(map, height, width)
        && ft_check_valid_path(map)))
        return (0);
    else
        return (1);
}
