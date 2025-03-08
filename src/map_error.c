/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:30:31 by ryada             #+#    #+#             */
/*   Updated: 2025/03/08 17:04:29 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_is_rectanglar(t_game *game)
{
    int y;
    int cur_width;

    if (!game->map || !game->map[0])
        return (0);
    y = 1;
    while (game->map[y])
    {
        cur_width = ft_strlen(game->map[y]);
        if (game->map[y][cur_width - 1] == '\n')
            cur_width--;
        if (cur_width != game->width)
            return (ft_putstr_fd("Error: Not rectangular\n", 2), 0);
        y++;
    }
    return (1);
}

int ft_is_covered(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (y == 0 || y == game->height - 1 || x == 0 || x == game->width - 1)
            {
                if (game->map[y][x] != '1')
                    return (ft_putstr_fd("Error: Not covered\n", 2), 0);
            }
            x++;
        }
        y++;
    }
    return (1);
}

int ft_is_valid_char(t_game *game)
{
    int y, x;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] != '0' && game->map[y][x] != '1' && game->map[y][x] != 'C'
                && game->map[y][x] != 'E' && game->map[y][x] != 'P' && game->map[y][x] != 'H') 
                return (ft_putstr_fd("Error: Invalid char\n", 2), 0);
            x++;
        }
        y++;
    }
    return (1);
}

int ft_check_char_count(t_game *game)
{
    int c;
    int e;
    int p;
    int h;
    int y;
    int x;

    c = 0;
    e = 0;
    p = 0;
    h = 0;
    y = 0;
    while(y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == 'C')
                c++;
            else if (game->map[y][x] == 'E')
                e++;
            else if (game->map[y][x] == 'P')
                p++;
            else if (game->map[y][x] == 'H')
                h++;
            x++;
        }
        y++;
    }
    if (!c || e != 1 || p != 1 || h > 1)
        return (ft_putstr_fd("Error_Invalid char count\n", 2), 0);
    return (1);
}


int ft_check_valid_path(t_game *game)
{
    // t_pos player;
    int y;
    int x;
    char **map_copy;

    map_copy = ft_copy_map(game->map);
    ft_flood_fill(map_copy, game->player.column, game->player.row);
    y = 0;
    while (map_copy[y])
    {
        x = 0;
        while (map_copy[y][x])
        {
            if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
                return (ft_putstr_fd("Error path\n", 2), ft_free_map(map_copy),0);
            x++;
        }
        y++;
    }
    return (ft_free_map(map_copy), 1);
}

int ft_is_valid_map(t_game *game)
{
    return (ft_is_rectanglar(game) &&
            ft_is_covered(game) &&
            ft_is_valid_char(game) &&
            ft_check_char_count(game) &&
            ft_check_valid_path(game));
}
