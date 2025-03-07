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

static int count = 0;

void ft_move_player(t_game *game, int x_move, int y_move)
{
    int new_x;
    int new_y;
    // static int count;

    new_x = game->player.column + x_move;
    new_y = game->player.row + y_move;
    // count = 0;
    if (game->map[new_y][new_x] == '1')//Check if it's a wall
        return;
    if (game->map[new_y][new_x] == 'E')//If it's the exit
    {
        ft_printf("You win!\n");
        exit(0);
    }
    game->map[game->player.row][game->player.column] = '0';//Remove old position
    game->map[new_y][new_x] = 'P';//Place player in new position
    game->player.column = new_x;//update the new player position
    game->player.row = new_y;
    count++;
    ft_printf("Moves: %d\n", count);
    ft_draw_map(game);
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
    else if (key == 119)//W key
        ft_move_player(game, 0, -1);
    else if (key == 115) //S key
        ft_move_player(game, 0, 1);
    else if (key == 97)//A key
        ft_move_player(game, -1, 0);
    else if (key == 100)//D key
        ft_move_player(game, 1, 0);
    return (0);
}