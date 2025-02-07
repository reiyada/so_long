/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryada <ryada@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:10:09 by ryada             #+#    #+#             */
/*   Updated: 2025/02/07 16:33:33 by ryada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../Libft/libft.h"
#include "../gnl/get_next_line.h"
#include "../ft_printf/includes/ft_printf.h"

#define O_RDONLY         00
#define O_WRONLY         01
#define O_RDWR           02

typedef struct s_pos
{
    int column;
    int row;
} t_pos;


//map_error.c
int ft_is_rectanglar(char **map, int width);
int ft_is_covered(char **map, int height, int width);
int ft_is_valid_char (char **map, int height, int width);
int ft_check_char_count(char **map, int height, int width);
int ft_check_valid_path(char **map);
int ft_is_valid_map(char **map, int height, int width);

//map_read.c
void ft_validate_map_line(char *line, int line_number, int expected_width);
void ft_parse_map(const char *filename);

//map_util.c
int ft_count_height(char **map);
int ft_count_width(char **map);
void    ft_find_player(char **map, t_pos *player);
char **ft_copy_map(char **map);
void ft_flood_fill(char **map, int x, int y);
void    ft_free_map(char **map);
int ft_map_height(const char *filename);

//map_read.c
char **ft_store_map(const char *filename);

#endif