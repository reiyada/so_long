/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:56:29 by ryada             #+#    #+#             */
/*   Updated: 2025/03/12 10:14:21 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_move_enemy(t_game *game)
{
    int dx = 1, dy = 1;
    int new_x, new_y;

    if (game->player.column > game->enemy.column) // Move Right
        dx = 1;
    else if (game->enemy.column > game->player.column) // Move Left
        dx = -1;
    if (game->player.row > game->enemy.row) // Move Down
        dy = 1;
    else if (game->enemy.row > game->player.row) // Move Up
        dy = -1;
    new_x = game->enemy.column + dx;
    new_y = game->enemy.row;
    if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'C' && game->map[new_y][new_x] != 'E')
    {
        if (game->map[new_y][new_x] == 'P') // Enemy reaches player
        {
            ft_printf("You lose! The enemy caught you!\n");
            ft_free_elements(game);
            // ft_free_map(game->map);
            exit(1);
        }
        if (dx == 1)
            ft_change_pose(game, 'H', 'R'); // Right
        else if (dx == -1)
            ft_change_pose(game, 'H', 'L'); // Left
        game->map[game->enemy.row][game->enemy.column] = '0'; // Clear old position
        game->enemy.column = new_x;
        game->map[new_y][new_x] = 'H'; // Place enemy
    }
    else
    {
        new_x = game->enemy.column;
        new_y = game->enemy.row + dy;
        if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'C' && game->map[new_y][new_x] != 'E')
        {
            if (game->map[new_y][new_x] == 'P') // Enemy reaches player
            {
                ft_printf("You lose! The enemy caught you!\n");
                ft_free_elements(game);
                // ft_free_map(game->map);
                exit(1);
            }
            if (dy == 1)
                ft_change_pose(game, 'H', 'D'); // Down
            else if (dy == -1)
                ft_change_pose(game, 'H', 'U'); // Up
            game->map[game->enemy.row][game->enemy.column] = '0'; // Clear old position
            game->enemy.row = new_y;
            game->map[new_y][new_x] = 'H'; // Place enemy
        }
    }
}

