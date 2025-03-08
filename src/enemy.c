/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:56:29 by ryada             #+#    #+#             */
/*   Updated: 2025/03/08 14:52:36 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void ft_move_player(t_game *game, int x_move, int y_move)
// {
//     int new_x;
//     int new_y;

//     new_x = game->player.column + x_move;
//     new_y = game->player.row + y_move;
//     if (game->map[new_y][new_x] == '1')//Check if it's a wall
//         return;
//     if (game->map[new_y][new_x] == 'E' && ft_check_collective(game))//If it's the exit and all the collectivs were colleted
//     {
//         ft_printf("You win!\n");
//         exit(0);
//     }
//     else if (game->map[new_y][new_x] == 'H')//If the player meets the enemy
//     {
//         ft_printf("You lose!\n");
//         exit(1);
//     }
//     if (y_move == -1)//up
//         ft_change_pose(game, 'U');
//     else if (y_move == 1)//down
//         ft_change_pose(game, 'D');
//     else if (x_move == 1)//right
//         ft_change_pose(game, 'R');
//     else if (x_move == -1)//right
//         ft_change_pose(game, 'L');
//     if (game->map[new_y][new_x] == 'E')
//     {
//         new_x = game->player.column;
//         new_y = game->player.row;
//     }
//     else
//         game->map[game->player.row][game->player.column] = '0';//Remove old position
//     game->map[new_y][new_x] = 'P';//Place player in new position
//     game->player.column = new_x;//update the new player position
//     game->player.row = new_y;
//     count++;
//     ft_printf("Moves: %d\n", count);
//     ft_draw_map(game);
// }

void ft_move_enemy(t_game *game)
{
    int dx = 0, dy = 0;
    int new_x, new_y;

    // Calculate the direction towards the player
    if (game->enemy.column < game->player.column) // Move Right
        dx = 1;
    else if (game->enemy.column > game->player.column) // Move Left
        dx = -1;
    if (game->enemy.row < game->player.row) // Move Down
        dy = 1;
    else if (game->enemy.row > game->player.row) // Move Up
        dy = -1;
    // Prioritize horizontal movement if there's space
    new_x = game->enemy.column + dx;
    new_y = game->enemy.row;
    if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'C' && game->map[new_y][new_x] != 'E')
    {
        if (game->map[new_y][new_x] == 'P') // Enemy reaches the player
        {
            ft_printf("You lose! The enemy caught you!\n");
            exit(1);
        }
        // Move enemy
        game->map[game->enemy.row][game->enemy.column] = '0'; // Clear old position
        game->enemy.column = new_x;
        game->map[new_y][new_x] = 'H'; // Place enemy
    }
    else // If horizontal movement is blocked, try vertical movement
    {
        new_x = game->enemy.column;
        new_y = game->enemy.row + dy;
        if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'C' && game->map[new_y][new_x] != 'E')
        {
            if (game->map[new_y][new_x] == 'P') // Enemy reaches the player
            {
                ft_printf("You lose! The enemy caught you!\n");
                exit(1);
            }
            // Move enemy
            game->map[game->enemy.row][game->enemy.column] = '0'; // Clear old position
            game->enemy.row = new_y;
            game->map[new_y][new_x] = 'H'; // Place enemy
        }
    }
    ft_draw_map(game); // Redraw the map with the updated enemy position
}


// static int dir = 0;
// void ft_move_enemy(t_game *game)
// {
    
//     int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//     int new_x;
//     int new_y;
    
//     new_x = game->enemy.column + directions[dir][0];
//     new_y = game->enemy.row + directions[dir][1];
//     int i = 0;
//     while (i < 4)
//     {
//         if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'E' && game->map[new_y][new_x] != 'C')
//         {
//             // Check if enemy encounters the player
//             if (game->map[new_y][new_x] == 'P')
//             {
//                 ft_printf("You lose! The enemy caught you!\n");
//                 exit(1);
//             }
//             // Move the enemy
//             if (dir == 0)//down
//                 ft_change_pose(game, 'H', 'D');
//             else if (dir == 1)//right
//                 ft_change_pose(game, 'H', 'R');
//             else if (dir == 2)//up
//                 ft_change_pose(game, 'H', 'U');
//             else if (dir == 3)//left
//                 ft_change_pose(game, 'H', 'L');
//             game->map[game->enemy.row][game->enemy.column] = '0';
//             game->enemy.row = new_y;
//             game->enemy.column = new_x;
//             game->map[new_y][new_x] = 'H';
//             ft_draw_map(game);
//             return; // Exit after a successful move
//         }
//         i++;
//     }
//     dir = (dir + 1) % 4;
//     ft_draw_map(game);
// }


// static int direction_patterns[10][4] = {
//     {0, 1, 2, 3},  // Down, Right, Up, Left
//     {3, 0, 1, 2},  // Left, Down, Right, Up
//     {1, 3, 0, 2},  // Right, Left, Down, Up
//     {2, 0, 3, 1},  // Up, Down, Left, Right
//     {3, 2, 0, 1},  // Left, Up, Down, Right
//     {1, 0, 3, 2},  // Right, Down, Left, Up
//     {2, 3, 1, 0},  // Up, Left, Right, Down
//     {0, 2, 3, 1},  // Down, Up, Left, Right
//     {1, 2, 0, 3},  // Right, Up, Down, Left
//     {3, 1, 2, 0}   // Left, Right, Up, Down
// };


// void ft_move_enemy(t_game *game)
// {
//     static int pattern_index = 0; // Current movement pattern
//     static int dir_index = 0;     // Current step in the pattern

//     int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
//     int new_x, new_y;

//     // Get the next movement direction from the current pattern
//     int dir = direction_patterns[pattern_index][dir_index];

//     new_x = game->enemy.column + directions[dir][0];
//     new_y = game->enemy.row + directions[dir][1];

//     // Check if the new position is valid
//     if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'E' && game->map[new_y][new_x] != 'C')
//     {
//         if (game->map[new_y][new_x] == 'P')
//         {
//             ft_printf("You lose! The enemy caught you!\n");
//             exit(1);
//         }

//         // Change enemy sprite direction if needed
//         if (dir == 0) ft_change_pose(game, 'H', 'D'); // Down
//         else if (dir == 1) ft_change_pose(game, 'H', 'R'); // Right
//         else if (dir == 2) ft_change_pose(game, 'H', 'U'); // Up
//         else if (dir == 3) ft_change_pose(game, 'H', 'L'); // Left

//         // Move the enemy
//         game->map[game->enemy.row][game->enemy.column] = '0';
//         game->enemy.row = new_y;
//         game->enemy.column = new_x;
//         game->map[new_y][new_x] = 'H';

//         ft_draw_map(game);

//         // Move to the next direction in the same pattern
//         dir_index = (dir_index + 1) % 4;

//         // If we've completed a full cycle of 4 moves, switch to a new pattern
//         if (dir_index == 0)
//             pattern_index = (pattern_index + 1) % 10;

//         return; // Exit after a successful move
//     }

//     // If blocked, try the next direction in the pattern
//     dir_index = (dir_index + 1) % 4;

//     // If completely stuck, switch to a new pattern
//     if (dir_index == 0)
//         pattern_index = (pattern_index + 1) % 10;
// }






