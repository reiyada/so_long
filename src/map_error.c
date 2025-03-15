/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:30:31 by ryada             #+#    #+#             */
/*   Updated: 2025/03/15 15:21:00 by ryada            ###   ########.fr       */
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
            return (0);
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
                    return (0);
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
                return (0);
            x++;
        }
        y++;
    }
    return (1);
}

int ft_count_element(t_game *game, char c)
{
    int y;
    int x;
    int count;

    y = 0;
    count = 0;
    while(game->map[y])
    {
        x = 0;
        while(game->map[y][x])
        {
            if (game->map[y][x] == c)
                count++;
            x++;
        }
        y++;
    }
    return (count);
}

int ft_check_char_count(t_game *game)
{
    int c;
    int e;
    int p;
    int h;

    c = ft_count_element(game, 'C');
    e = ft_count_element(game, 'E');
    p = ft_count_element(game, 'P');
    h = ft_count_element(game, 'H');
    if (!c || e != 1 || p != 1 || h > 1)
        return (0);
    return (1);
}

int ft_check_valid_path(t_game *game)
{
    int y;
    int x;
    char **map_copy;

    if (ft_check_enemy(game) && game->height < 4)
        return (0);
    map_copy = ft_copy_map(game->map);
    if (!map_copy) // Ensure the map was copied correctly
        return (0);
    ft_flood_fill(map_copy, game->player.column, game->player.row);
    y = 0;
    while (map_copy[y])
    {
        x = 0;
        while (map_copy[y][x])
        {
            if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
                return (ft_free_map(map_copy),0);
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
