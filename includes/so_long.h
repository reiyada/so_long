/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:10:09 by ryada             #+#    #+#             */
/*   Updated: 2025/02/08 10:06:53 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../mlx/mlx.h"
# include <fcntl.h>


typedef struct s_pos
{
    int column;
    int row;
} t_pos;

typedef struct s_images
{
    void    *wall;//1
    void    *player;//P
    void    *collect;//C
    void    *exit;//E
    void    *empty;//0
    void    *enemy;//H
    int     width;
    int     height;
}   t_images;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    t_images img;
}   t_game;


//map_error.c
int ft_is_rectanglar(char **map, int width);
int ft_is_covered(char **map, int height, int width);
int ft_is_valid_char (char **map, int height, int width);
int ft_check_char_count(char **map, int height, int width);
int ft_check_valid_path(char **map);
int ft_is_valid_map(char **map, int height, int width);

//map_load.c
void ft_load_images(t_game *game);
void ft_draw_map(t_game *game);

//map_read.c
char **ft_read_map(const char *filename);

//map_util.c
int ft_count_height(char **map);
int ft_count_width(char **map);
void    ft_find_player(char **map, t_pos *player);
char **ft_copy_map(char **map);
void ft_flood_fill(char **map, int x, int y);
void    ft_free_map(char **map);
int ft_map_height(const char *filename);


#endif