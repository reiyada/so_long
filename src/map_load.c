/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:45:01 by ryada             #+#    #+#             */
/*   Updated: 2025/03/08 14:20:21 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_load_images(t_game *game)
{
    int img_size;

    img_size = TILE_SIZE;
    game->img.wall = mlx_xpm_file_to_image(game->mlx, "./textures/1.xpm", &img_size, &img_size);
    game->img.player = mlx_xpm_file_to_image(game->mlx, "./textures/p_down.xpm", &img_size, &img_size);
    game->img.collect_pink = mlx_xpm_file_to_image(game->mlx, "./textures/c_0.xpm", &img_size, &img_size);
    game->img.collect_green = mlx_xpm_file_to_image(game->mlx, "./textures/c_1.xpm", &img_size, &img_size);
    game->img.collect_yellow = mlx_xpm_file_to_image(game->mlx, "./textures/c_2.xpm", &img_size, &img_size);
    game->img.collect_brown = mlx_xpm_file_to_image(game->mlx, "./textures/c_3.xpm", &img_size, &img_size);
    game->img.exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm", &img_size, &img_size);
    game->img.empty = mlx_xpm_file_to_image(game->mlx, "./textures/0.xpm", &img_size, &img_size);
    game->img.enemy = mlx_xpm_file_to_image(game->mlx, "./textures/h_down.xpm", &img_size, &img_size);

    if (!game->img.wall || !game->img.player || (!game->img.collect_pink &&
        !game->img.collect_green && !game->img.collect_yellow && !game->img.collect_brown )||
        !game->img.empty || !game->img.enemy||!game->img.exit)
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
    char *move_text;

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
            {
                if (x % 4 == 0)
                    img = game->img.collect_pink;
                else if (x % 4 == 1)
                    img = game->img.collect_green;
                else if (x % 4 == 2)
                    img = game->img.collect_yellow;
                else
                    img = game->img.collect_brown;
            }
                
            else if (game->map[y][x] == 'E')
                img = game->img.exit;
            else if (game->map[y][x] == 'H')
                img = game->img.enemy;
            mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
    move_text = ft_itoa(game->move_count);
    if (move_text)
    {
        mlx_string_put(game->mlx, game->win, 10, 10, 0xFF0000, "Moves: ");
        mlx_string_put(game->mlx, game->win, 80, 10, 0xFF0000, move_text);
        free(move_text);
    }
}
