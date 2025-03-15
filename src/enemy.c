/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:56:29 by ryada             #+#    #+#             */
/*   Updated: 2025/03/15 15:00:46 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_dis ft_set_distanc(t_game *game)
{
    t_dis d;

    d.x = 1;
    d.y = 1;
    if (game->player.column > game->enemy.column) // Move Right
        d.x = 1;
    else if (game->enemy.column > game->player.column) // Move Left
        d.x = -1;
    if (game->player.row > game->enemy.row) // Move Down
        d.y = 1;
    else if (game->enemy.row > game->player.row) // Move Up
        d.y = -1;
    return (d);
}

void ft_move_holiz(t_game *game, t_dis d, int new_x, int new_y)
{
    if (game->map[new_y][new_x] == 'P') // Enemy reaches player
        ft_exit('P', game);
    if (d.x == 1)
        ft_change_pose(game, 'H', 'R'); // Right
    else if (d.x == -1)
        ft_change_pose(game, 'H', 'L'); // Left
    game->map[game->enemy.row][game->enemy.column] = '0'; // Clear old position
    game->enemy.column = new_x;
    game->map[new_y][new_x] = 'H'; // Place enemy
}

void ft_move_virt(t_game *game, t_dis d, int new_x, int new_y)
{
    if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'C' && game->map[new_y][new_x] != 'E')
    {
        if (game->map[new_y][new_x] == 'P') // Enemy reaches player
            ft_exit('P', game);
        if (d.y == 1)
            ft_change_pose(game, 'H', 'D'); // Down
        else if (d.y == -1)
            ft_change_pose(game, 'H', 'U'); // Up
        game->map[game->enemy.row][game->enemy.column] = '0'; // Clear old position
        game->enemy.row = new_y;
        game->map[new_y][new_x] = 'H'; // Place enemy
    }
}

void ft_move_enemy(t_game *game)
{
    t_dis d;
    int new_x;
    int new_y;

    d = ft_set_distanc(game);
    new_x = game->enemy.column + d.x;
    new_y = game->enemy.row;
    if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'C' && game->map[new_y][new_x] != 'E')
        ft_move_holiz(game, d, new_x, new_y);
    else
    {
        new_x = game->enemy.column;
        new_y = game->enemy.row + d.y;
        ft_move_virt(game, d, new_x, new_y);
    }
}

// void ft_set_direction(t_game *game, int d.x, int d.y)
// {
//     d.x = 1;
//     d.y = 1;
//     if (game->player.column > game->enemy.column) // Move Right
//         d.x = 1;
//     else if (game->enemy.column > game->player.column) // Move Left
//         d.x = -1;
//     if (game->player.row > game->enemy.row) // Move Down
//         d.y = 1;
//     else if (game->enemy.row > game->player.row) // Move Up
//         d.y = -1;
// }

// void ft_move_enemy(t_game *game)
// {
//     int d.x;
//     int d.y;
//     int new_x;
//     int new_y;

//     d.x = 1;
//     d.y = 1;
//     if (game->player.column > game->enemy.column) // Move Right
//         d.x = 1;
//     else if (game->enemy.column > game->player.column) // Move Left
//         d.x = -1;
//     if (game->player.row > game->enemy.row) // Move Down
//         d.y = 1;
//     else if (game->enemy.row > game->player.row) // Move Up
//         d.y = -1;
//     new_x = game->enemy.column + d.x;
//     new_y = game->enemy.row;
//     if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'C' && game->map[new_y][new_x] != 'E')
//     {
//         if (game->map[new_y][new_x] == 'P') // Enemy reaches player
//         {
//             ft_printf("You lose! The enemy caught you!\n");
//             ft_free_elements(game);
//             // ft_free_map(game->map);
//             exit(1);
//         }
//         if (d.x == 1)
//             ft_change_pose(game, 'H', 'R'); // Right
//         else if (d.x == -1)
//             ft_change_pose(game, 'H', 'L'); // Left
//         game->map[game->enemy.row][game->enemy.column] = '0'; // Clear old position
//         game->enemy.column = new_x;
//         game->map[new_y][new_x] = 'H'; // Place enemy
//     }
//     else
//     {
//         new_x = game->enemy.column;
//         new_y = game->enemy.row + d.y;
//         if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'C' && game->map[new_y][new_x] != 'E')
//         {
//             if (game->map[new_y][new_x] == 'P') // Enemy reaches player
//             {
//                 ft_printf("You lose! The enemy caught you!\n");
//                 ft_free_elements(game);
//                 // ft_free_map(game->map);
//                 exit(1);
//             }
//             if (d.y == 1)
//                 ft_change_pose(game, 'H', 'D'); // Down
//             else if (d.y == -1)
//                 ft_change_pose(game, 'H', 'U'); // Up
//             game->map[game->enemy.row][game->enemy.column] = '0'; // Clear old position
//             game->enemy.row = new_y;
//             game->map[new_y][new_x] = 'H'; // Place enemy
//         }
//     }
// }

