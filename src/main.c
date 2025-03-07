/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rei <rei@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:29:48 by ryada             #+#    #+#             */
/*   Updated: 2025/03/07 22:56:01 by rei              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int main(int argc, char **argv)
// {
//     char **map;
//     int height;
//     int width;

//     if (argc != 2)
//         return (ft_putstr_fd("Error\n", 2), 1);
//     map = ft_store_map(argv[1]);
//     if (!map)
//         return (ft_putstr_fd("Error\n", 2), 1);
//     height = ft_count_height(map);
//     width = ft_count_width(map);
//     if (ft_is_valid_map(map, height, width))
//         return (ft_printf("Map is valid!\n"), 0);
//     else
//         return (ft_putstr_fd("Error\n", 2), 1);
// }

// int main(int argc, char **argv)
// {
//     t_game game;

//     if (argc != 2)
//     {
//         ft_putstr_fd("Put the file name\n", 2);
//         return (1);
//     }

//     game.map = ft_read_map(argv[1]); // Read the map
//     if (!game.map)
//         return (1);

//     game.mlx = mlx_init();
//     game.win = mlx_new_window(game.mlx, ft_count_width(game.map) * 64, ft_map_height(argv[1]) * 64, "so_long");

//     ft_load_images(&game); // Load images
//     ft_draw_map(&game); // Draw the map

//     mlx_loop(game.mlx); // Keep window open
//     return (0);
// }

int ft_close_game(t_game *game)
{
    ft_free_map(game->map); // Free allocated memory for the map
    mlx_destroy_window(game->mlx, game->win); // Close the window
    exit(0); // Exit the program cleanly
    return (0);
}


void    ft_display_window(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "So Long");

    ft_load_images(game);
    ft_draw_map(game);

    mlx_hook(game->win, 2, 1L << 0, ft_key_handler, game); // Key press
    mlx_hook(game->win, 17, 0, ft_close_game, game); // Window close button

    mlx_loop(game->mlx); // Keep window open and listen for events
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        return (ft_putstr_fd("[Error] Invalid argument\n", 2), 1);
    game.map = ft_read_map(argv[1]);
    if (!game.map)
        return (ft_putstr_fd("[Error] Invalid map file\n", 2), 1);
    ft_set_map_dimentions(&game);
    ft_find_player_position(&game);
    if (!ft_is_valid_map(&game))
        return (ft_free_map(game.map), ft_putstr_fd("[Error] Invalid map\n", 2), 1);
    ft_display_window(&game);
    
}
