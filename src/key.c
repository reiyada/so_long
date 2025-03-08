/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 10:33:23 by ryada             #+#    #+#             */
/*   Updated: 2025/03/08 14:29:33 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


// typedef struct s_pos
// {
//     int column;
//     int row;
// } t_pos;

// typedef struct s_images
// {
//     void    *wall;//1
//     void    *player;//P
//     void    *collect;//C
//     void    *exit;//E
//     void    *empty;//0
//     void    *enemy;//H
//     int     width;
//     int     height;
// }   t_images;

// typedef struct s_game
// {
//     void    *mlx;
//     void    *win;
//     char    **map;
//     int height;
//     int width;
//     t_images img;
//     t_pos player;
// }   t_game;



void ft_move_player(t_game *game, int x_move, int y_move)
{
    int new_x;
    int new_y;

    new_x = game->player.column + x_move;
    new_y = game->player.row + y_move;
    if (game->map[new_y][new_x] == '1')//Check if it's a wall
        return;
    if (game->map[new_y][new_x] == 'E' && ft_check_collective(game))//If it's the exit and all the collectivs were colleted
    {
        ft_printf("You win!\n");
        exit(0);
    }
    else if (game->map[new_y][new_x] == 'H')//If the player meets the enemy
    {
        ft_printf("You lose!\n");
        exit(1);
    }
    if (y_move == -1)//up
        ft_change_pose(game, 'P', 'U');
    else if (y_move == 1)//down
        ft_change_pose(game, 'P', 'D');
    else if (x_move == 1)//right
        ft_change_pose(game, 'P', 'R');
    else if (x_move == -1)//right
        ft_change_pose(game, 'P', 'L');
    if (game->map[new_y][new_x] == 'E')
    {
        new_x = game->player.column;
        new_y = game->player.row;
    }
    else
    {
        game->map[game->player.row][game->player.column] = '0';//Remove old position
        game->move_count++;
    }
    game->map[new_y][new_x] = 'P';//Place player in new position
    game->player.column = new_x;//update the new player position
    game->player.row = new_y;
    mlx_clear_window(game->mlx, game->win);
    //ft_move_enemy(game);
    ft_draw_map(game);
}
void ft_change_pose(t_game *game, char who, char direction)
{
    int img_size;

    img_size = TILE_SIZE;
    if (who == 'P')
    {
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

int ft_key_handler(int key, void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (key == 65307)//ESC to quit
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
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
        ft_move_enemy(game);
    }
    return (0);
}
