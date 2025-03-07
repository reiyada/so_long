/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:45:01 by ryada             #+#    #+#             */
/*   Updated: 2025/03/07 17:35:34 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_load_images(t_game *game)
{
    int img_size;

    img_size = TILE_SIZE;
    game->img.wall = mlx_xpm_file_to_image(game->mlx, "./textures/1.xpm", &img_size, &img_size);
    game->img.player = mlx_xpm_file_to_image(game->mlx, "./textures/p_down.xpm", &img_size, &img_size);
    game->img.collect = mlx_xpm_file_to_image(game->mlx, "./textures/c.xpm", &img_size, &img_size);
    game->img.exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &img_size, &img_size);
    game->img.empty = mlx_xpm_file_to_image(game->mlx, "./textures/0.xpm", &img_size, &img_size);
    game->img.enemy = mlx_xpm_file_to_image(game->mlx, "./textures/h_down.xpm", &img_size, &img_size);

    if (!game->img.wall || !game->img.player || !game->img.collect ||
        !game->img.empty || !game->img.enemy
        ||!game->img.exit
        )
    {
        ft_putstr_fd("[Error] Failed to load images\n", 2);
        ft_free_map(game->map); // Free allocated memory
        exit(1);
    }
}

void ft_draw_map(t_game *game)
{
    int x;
    int y;
    void *img;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            img = game->img.empty;
            if (game->map[y][x] == '1')
                img = game->img.wall;
            else if (game->map[y][x] == 'P')
                img = game->img.player;
            else if (game->map[y][x] == 'C')
                img = game->img.collect;
            else if (game->map[y][x] == 'E')
                img = game->img.exit;
            else if (game->map[y][x] == 'H')
                img = game->img.enemy;
            mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}
