/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:45:01 by ryada             #+#    #+#             */
/*   Updated: 2025/02/08 10:09:37 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_load_images(t_game *game)
{
    game->img.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->img.width, &game->img.height);
    game->img.player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->img.width, &game->img.height);
    game->img.collect = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm", &game->img.width, &game->img.height);
    game->img.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->img.width, &game->img.height);
    game->img.empty = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &game->img.width, &game->img.height);
    game->img.enemy = mlx_xpm_file_to_image(game->mlx, "textures/enemy.xpm", &game->img.width, &game->img.height);

    if (!game->img.wall) ft_putstr_fd("Error: Missing textures/wall.xpm\n", 2);
    if (!game->img.player) ft_putstr_fd("Error: Missing textures/player.xpm\n", 2);
    if (!game->img.collect) ft_putstr_fd("Error: Missing textures/collect.xpm\n", 2);
    if (!game->img.exit) ft_putstr_fd("Error: Missing textures/exit.xpm\n", 2);
    if (!game->img.empty) ft_putstr_fd("Error: Missing textures/floor.xpm\n", 2);
    if (!game->img.enemy) ft_putstr_fd("Error: Missing textures/enemy.xpm\n", 2);

    if (!game->img.wall || !game->img.player || !game->img.collect ||
        !game->img.exit || !game->img.empty || !game->img.enemy)
    {
        exit(1);
    }
}

void ft_draw_map(t_game *game)
{
    int x, y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x * 64, y * 64);
            else if (game->map[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img.player, x * 64, y * 64);
            else if (game->map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img.collect, x * 64, y * 64);
            else if (game->map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x * 64, y * 64);
            else if (game->map[y][x] == 'H')
                mlx_put_image_to_window(game->mlx, game->win, game->img.enemy, x * 64, y * 64);
            else
                mlx_put_image_to_window(game->mlx, game->win, game->img.empty, x * 64, y * 64);
            x++;
        }
        y++;
    }
}
