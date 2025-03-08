/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:29:48 by ryada             #+#    #+#             */
/*   Updated: 2025/03/08 17:06:55 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
    game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "./so_long");

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
    ft_find_enemy_position(&game);
    game.move_count = 0;
    if (!ft_is_valid_map(&game))
        return (ft_free_map(game.map), ft_putstr_fd("[Error] Invalid map\n", 2), 1);
    ft_display_window(&game);
    
}
