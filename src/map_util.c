/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:29:30 by ryada             #+#    #+#             */
/*   Updated: 2025/03/15 14:58:56 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_count_height(char **map)
{
    int height;

    height = 0;
    while (map[height])
        height++;
    return (height);
}

int ft_count_width(char **map)
{
    int width;

    if (!map || !map[0])
        return (0);
    width = ft_strlen(map[0]);
    if (map[0][width - 1] == '\n')
        width--;
    return (width);
}

t_pos    ft_find_position(char **map, char find)
{
    t_pos position;
    int x;
    int y;

    position.column = 0;
    position.row = 0;
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == find)
            {
                position.column = x;
                position.row = y;
                return (position);
            }
            x++;
        }
        y++;
    }
    return (position);
}

void ft_find_player_position(t_game *game)
{
    game->player = ft_find_position(game->map, 'P');
}

void ft_find_enemy_position(t_game *game)
{
    game->enemy = ft_find_position(game->map, 'H');
}

void ft_find_exit_position(t_game *game)
{
    game->exit = ft_find_position(game->map, 'E');
}

int ft_check_element(t_game *game, char type)
{
    int i;
    int j;

    i = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if (game->map[i][j] == type)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

// void ft_find_player_position(t_game *game)
// {
//     int row;
//     int col;

//     row = 0;
//     while (row < game->height)
//     {
//         col = 0;
//         while (col < game->width)
//         {
//             if (game->map[row][col] == 'P')
//             {
//                 game->player.row = row;
//                 game->player.column = col;
//                 return;
//             }
//             col++;
//         }
//         row++;
//     }
// }


char **ft_copy_map(char **map)
{
    int height;
    int i;
    char **copy;

    height = ft_count_height(map);
    copy = malloc((height + 1) * sizeof(char *));
    if (!copy)
        return (NULL);
    copy[height] = NULL;
    i = 0;
    while (i < height)
    {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i])
        {
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    return (copy);
}

void ft_flood_fill(char **map, int x, int y)
{
    if (y < 0 || x < 0 || !map[y] || !map[y][x])
        return;
    if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'H')
        return;
    map[y][x] = 'V'; //visited
    ft_flood_fill(map, x, y - 1);//up
    ft_flood_fill(map, x, y + 1);//down
    ft_flood_fill(map, x - 1, y);//left
    ft_flood_fill(map, x + 1, y);//right
}

// void ft_flood_fill_collective(char **map, int x, int y)
// {
//     if (y < 0 || x < 0 || !map[y] || !map[y][x])
//         return;
//     if (map[y][x] == 'E')
//         return;
//     map[y][x] = 'V'; //visited
//     ft_flood_fill(map, x, y - 1);//up
//     ft_flood_fill(map, x, y + 1);//down
//     ft_flood_fill(map, x - 1, y);//left
//     ft_flood_fill(map, x + 1, y);//right
// }

int ft_map_height(const char *filename)
{
    int fd;
    char *line;
    int height = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    line = get_next_line(fd);
    while (line != NULL)
    {
        free(line);
        height++;
        line = get_next_line(fd);
    }
    close(fd);
    return (height);
}

void ft_set_map_dimentions(t_game *game)
{
    game->height = ft_count_height(game->map);
    game->width = ft_count_width(game->map);
}

// int ft_player_is_moved(t_game *game)
// {
//     int prev_x;
//     int prev_y;
//     int new_x;
//     int new_y;

//     prev_x = game->player.column;
//     prev_y = game->player.row;
//     ft_find_player_position(game);
//     new_x = game->player.column;
//     new_y = game->player.row;
//     if (new_x == prev_x && new_y == prev_y)
//         return (0);
//     return (1);
// }

void ft_free_img(t_game *game)
{
    if (!game || !game->mlx)
        return ;
    if (game->img.wall)
        mlx_destroy_image(game->mlx, game->img.wall);
    if (game->img.player)
        mlx_destroy_image(game->mlx, game->img.player);
    if (game->img.collect_pink)
        mlx_destroy_image(game->mlx, game->img.collect_pink);
    if (game->img.collect_green)
        mlx_destroy_image(game->mlx, game->img.collect_green);
    if (game->img.collect_yellow)
        mlx_destroy_image(game->mlx, game->img.collect_yellow);
    if (game->img.collect_brown)
        mlx_destroy_image(game->mlx, game->img.collect_brown);
    if (game->img.exit)
        mlx_destroy_image(game->mlx, game->img.exit);
    if (game->img.empty)
        mlx_destroy_image(game->mlx, game->img.empty);
    if (game->img.enemy)
        mlx_destroy_image(game->mlx, game->img.enemy);
}

void    ft_free_map(char **map)
{
    int y;

    if (!map)
        return;
    y = 0;
    while (map[y])
    {
        if (map[y])
            free(map[y]);
        y++;
    }
    free(map);
}

void ft_free_game(t_game *game)
{
    if (!game)
        return ;
    if (!game->win || !game->mlx)
        return ;
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);  // Proper way to free window
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);  // Required for Linux environments
        free(game->mlx);  // Free MiniLibX instance
    }
}

void    ft_free_elements(t_game *game)
{
    if (!game)
        return ;
    ft_free_img(game);
    ft_free_game(game);
    ft_free_map(game->map);
    // free(game);
}

void ft_init_img(t_game *game)
{
    game->img.wall= NULL;
    game->img.player = NULL;
    game->img.collect_pink = NULL;
    game->img.collect_green = NULL;
    game->img.collect_yellow = NULL;
    game->img.collect_brown = NULL;
    game->img.exit = NULL;
    game->img.empty = NULL;
    game->img.enemy = NULL;
}

void ft_exit(char c, t_game *game)
{
    if (c == 'P')
    {
        ft_printf("You lost! The enemy caught you!\n");
        ft_free_elements(game);
        exit(1);
    }
    else if (c == 'E')
    {
        if (ft_check_collective(game))
        {
            ft_printf("You won!\n");
            ft_free_elements(game);
            exit(0);
        }
    }
}
