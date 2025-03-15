/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:33:23 by ryada             #+#    #+#             */
/*   Updated: 2025/03/15 15:10:06 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_move_dir(t_game *game, int x_move, int y_move)
{
    if (y_move == -1)//up
        ft_change_pose(game, 'P', 'U');
    else if (y_move == 1)//down
        ft_change_pose(game, 'P', 'D');
    else if (x_move == 1)//right
        ft_change_pose(game, 'P', 'R');
    else if (x_move == -1)//right
        ft_change_pose(game, 'P', 'L');
}

void ft_move_player(t_game *game, int x_move, int y_move)
{
    int new_x;
    int new_y;

    new_x = game->player.column + x_move;
    new_y = game->player.row + y_move;
    if (game->map[new_y][new_x] == '1')//Check if it's a wall
        return;
    if (game->map[new_y][new_x] == 'E')//If it's the exit and all the collectivs were colleted
        ft_exit('E', game);
    ft_move_dir(game, x_move, y_move);
    game->map[game->player.row][game->player.column] = '0';//Remove old position
    game->move_count++;
    if (!ft_check_collective(game) && !ft_check_element(game, 'E'))
        game->map[game->exit.row][game->exit.column] = 'E';
    game->map[new_y][new_x] = 'P';//Place player in new position
    game->player.column = new_x;//update the new player position
    game->player.row = new_y;
    ft_draw_map(game);
    if (game->move_count % 2 == 0)
        ft_move_enemy(game);
}


// void ft_move_player(t_game *game, int x_move, int y_move)
// {
//     int new_x;
//     int new_y;

//     new_x = game->player.column + x_move;
//     new_y = game->player.row + y_move;
//     if (game->map[new_y][new_x] == '1')//Check if it's a wall
//         return;
//     if (game->map[new_y][new_x] == 'E')//If it's the exit and all the collectivs were colleted
//     {
//         if (ft_check_collective(game))
//         {
//             ft_printf("You won!\n");
//             ft_free_elements(game);
//             // ft_free_map(game->map);
//         exit(0);
//         }
//     }
//     // else if (game->map[new_y][new_x] == 'H')//If the player meets the enemy
//     // {
//     //     ft_printf("You lost!\n");
//     //     ft_free_elements(game);
//     //     // ft_free_map(game->map);
//     //     exit(1);
//     // }
//     if (y_move == -1)//up
//         ft_change_pose(game, 'P', 'U');
//     else if (y_move == 1)//down
//         ft_change_pose(game, 'P', 'D');
//     else if (x_move == 1)//right
//         ft_change_pose(game, 'P', 'R');
//     else if (x_move == -1)//right
//         ft_change_pose(game, 'P', 'L');
//     game->map[game->player.row][game->player.column] = '0';//Remove old position
//     game->move_count++;
//     if (!ft_check_collective(game) && !ft_check_element(game, 'E'))
//         game->map[game->exit.row][game->exit.column] = 'E';
//     game->map[new_y][new_x] = 'P';//Place player in new position
//     game->player.column = new_x;//update the new player position
//     game->player.row = new_y;
//     ft_draw_map(game);
//     if (game->move_count % 2 == 0)
//         ft_move_enemy(game);
// }

void ft_set_dir_img(t_game *game, char who, int img_size, char direction)
{
    if (who == 'P')
    {
        mlx_destroy_image(game->mlx, game->img.player);
        if (direction == 'U')
            game->img.player = mlx_xpm_file_to_image(game->mlx, "./textures/p_up.xpm", &img_size, &img_size);
        else if (direction == 'D')
            game->img.player = mlx_xpm_file_to_image(game->mlx, "./textures/p_down.xpm", &img_size, &img_size);
        else if (direction == 'R')
            game->img.player = mlx_xpm_file_to_image(game->mlx, "./textures/p_right.xpm", &img_size, &img_size);
        else if (direction == 'L')
            game->img.player = mlx_xpm_file_to_image(game->mlx, "./textures/p_left.xpm", &img_size, &img_size);
    }
    else if (who == 'H')
    {
        mlx_destroy_image(game->mlx, game->img.enemy);
        if (direction == 'U')
            game->img.enemy = mlx_xpm_file_to_image(game->mlx, "./textures/h_up.xpm", &img_size, &img_size);
        else if (direction == 'D')
            game->img.enemy = mlx_xpm_file_to_image(game->mlx, "./textures/h_down.xpm", &img_size, &img_size);
        else if (direction == 'R')
            game->img.enemy = mlx_xpm_file_to_image(game->mlx, "./textures/h_right.xpm", &img_size, &img_size);
        else if (direction == 'L')
            game->img.enemy = mlx_xpm_file_to_image(game->mlx, "./textures/h_left.xpm", &img_size, &img_size);
    }
}

void ft_change_pose(t_game *game, char who, char direction)
{
    int img_size;

    img_size = TILE_SIZE;
    ft_set_dir_img(game, who, img_size, direction);
    if (!game->img.player || !game->img.enemy)
    {
        ft_putstr_fd("Error\nFailed to load images\n", 2);
        ft_free_elements(game);
        exit(1);
    }
}

int ft_key_handler(int key, void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (key == 65307)//ESC to quit
        ft_close_game(game);
    else
    {
        
        if (key == 119)//W key
            ft_move_player(game, 0, -1);
        else if (key == 115) //S key
            ft_move_player(game, 0, 1);
        else if (key == 97)//A key
            ft_move_player(game, -1, 0);
        else if (key == 100)//D key
            ft_move_player(game, 1, 0);
    }
    return (0);
}
